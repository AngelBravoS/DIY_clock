#!/bin/bash
#
# check_size.sh — verifica el uso de flash del firmware para el IAP15W413AS.
#
# El IAP15W413AS tiene 13 312 bytes de flash de programa unificada (0x0000–0x33FF).
# No existe partición hardware entre código e IAP: el único límite es el total.
#
# Fuente preferida: .ihx (Intel HEX). Fallback: .map (área CSEG/REL/CODE).

IHX="Binary/DIY_Firmware_13k.ihx"
MAP="Binary/DIY_Firmware_13k.map"

MAX_TOTAL=13312   # Bytes de flash del IAP15W413AS (0x0000–0x33FF)

# ── Parseo del IHX ────────────────────────────────────────────────────────────
# Emite "addr size" para cada registro de datos (tipo 00).
# Soporta registros de dirección extendida (tipo 02 y 04).
parse_ihx() {
    python3 - "$IHX" <<'PYEOF'
import sys
total = 0
base  = 0
with open(sys.argv[1]) as f:
    for line in f:
        line = line.strip()
        if not line.startswith(':'): continue
        count   = int(line[1:3],   16)
        addr    = int(line[3:7],   16) + base
        rectype = int(line[7:9],   16)
        if rectype == 0:
            # Clamp to flash range; bytes beyond MAX are a linker overflow error
            end = addr + count
            lo  = max(addr, 0)
            hi  = min(end,  13312)
            if hi > lo: total += hi - lo
        elif rectype == 2: base = int(line[9:13], 16) * 16
        elif rectype == 4: base = int(line[9:13], 16) * 65536
print(total)
PYEOF
}

# ── Parseo del MAP (fallback) ─────────────────────────────────────────────────
# Suma solo las áreas REL CODE (excluye ABS/CABS cuya dirección base es 0x0000).
parse_map() {
    awk '
        /^[A-Z][A-Z0-9_]*[[:space:]]+[0-9A-Fa-f]{8}[[:space:]]+[0-9A-Fa-f]{8}.*REL.*CODE/ {
            size = strtonum("0x" $3)
            total += size
        }
        END { print total }
    ' "$MAP"
}

# ── Selección de fuente ───────────────────────────────────────────────────────
if   [ -f "$IHX" ]; then SOURCE="ihx"; TOTAL=$(parse_ihx)
elif [ -f "$MAP" ]; then SOURCE="map*"; TOTAL=$(parse_map)
else echo "Error: no se encuentra $IHX ni $MAP"; exit 1
fi

FREE=$((MAX_TOTAL - TOTAL))
PCT=$((TOTAL * 100 / MAX_TOTAL))

# ── Barra de progreso ─────────────────────────────────────────────────────────
bar=""
for i in $(seq 1 20); do
    [ $((i * 5)) -le $PCT ] && bar="${bar}█" || bar="${bar}░"
done

# ── Salida ────────────────────────────────────────────────────────────────────
echo "┌─────────────────────────────┐"
echo "│      IAP15W413AS 13 KB      │"
printf "│    (0x0000–0x33FF) [%s]    │\n" "$SOURCE"
echo "├─────────────────────────────┤"
echo "│ Total                13312B │"
printf "│ Usado                %5dB │\n" "$TOTAL"
printf "│ Libre                %5dB │\n" "$FREE"
echo "├─────────────────────────────┤"
printf "│ [%s] %3d%% │\n" "$bar" "$PCT"
echo "└─────────────────────────────┘"

[ "$SOURCE" = "map*" ] && echo "Nota: fuente .map, solo se midió código REL (el .ihx no estaba disponible)."

# ── Comprobación de límite ────────────────────────────────────────────────────
if [ "$TOTAL" -gt "$MAX_TOTAL" ]; then
    echo "ERROR: el firmware ($TOTAL B) supera los $MAX_TOTAL B del IAP15W413AS."
    exit 2
fi
echo "OK."
