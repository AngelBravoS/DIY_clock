#!/bin/bash
#

IHX="Binary/DIY_Firmware_13k.ihx"
MAP="Binary/DIY_Firmware_13k.map"

MAX_CODE=8192    # 0x0000–0x1FFF
MAX_IAP=5120     # 0x2000–0x33FF
MAX_TOTAL=13312

# ── Funciones de parseo ───────────────────────────────────────────────────────

# IHX: emite "addr size" para cada registro de datos (tipo 00).
# Soporta registros de dirección extendida (tipo 02 y 04).
parse_ihx() {
    awk '
        BEGIN { base = 0 }
        /^:/ {
            count   = strtonum("0x" substr($0, 2, 2))
            addr    = strtonum("0x" substr($0, 4, 4)) + base
            rectype = strtonum("0x" substr($0, 8, 2))
            if      (rectype == 0) printf "%d %d\n", addr, count
            else if (rectype == 2) base = strtonum("0x" substr($0,10,4)) * 16
            else if (rectype == 4) base = strtonum("0x" substr($0,10,4)) * 65536
        }
    ' "$IHX"
}

# MAP fallback: emite "addr size" solo para áreas REL CODE.
# Las áreas ABS/CABS tienen addr=0x0000 y se excluyen deliberadamente;
# no son fiables para medir la región IAP.
parse_map_code() {
    awk '
        /^[A-Z][A-Z0-9_]*[[:space:]]+[0-9A-Fa-f]{8}[[:space:]]+[0-9A-Fa-f]{8}.*REL.*CODE/ {
            addr = strtonum("0x" $2)
            size = strtonum("0x" $3)
            if (size > 0) printf "%d %d\n", addr, size
        }
    ' "$MAP"
}

# ── Selección de fuente ───────────────────────────────────────────────────────

if   [ -f "$IHX" ]; then SOURCE="ihx"; DATA=$(parse_ihx)
elif [ -f "$MAP" ]; then SOURCE="map*"; DATA=$(parse_map_code)
else echo "Error: no se encuentra $IHX ni $MAP"; exit 1
fi

[ "${1}" = "--debug" ] && { echo "=== $SOURCE ==="; echo "$DATA"; echo "==="; }

# ── Suma de bytes por región ──────────────────────────────────────────────────
# overlap(addr, size, lo, hi): bytes de [addr, addr+size) que caen en [lo, hi)

SZ_CODE=0
SZ_IAP=0

while read -r addr size; do
    # Contribución a CODE
    s=$(( addr < 0         ? 0         : addr ))
    e=$(( addr+size < $MAX_CODE  ? addr+size : $MAX_CODE ))
    [ $e -gt $s ] && SZ_CODE=$((SZ_CODE + e - s))

    # Contribución a IAP
    s=$(( addr < $MAX_CODE  ? $MAX_CODE  : addr ))
    e=$(( addr+size < $MAX_TOTAL ? addr+size : $MAX_TOTAL ))
    [ $e -gt $s ] && SZ_IAP=$((SZ_IAP + e - s))
done <<< "$DATA"

TOTAL=$((SZ_CODE + SZ_IAP))
FREE=$((MAX_TOTAL - TOTAL))
PCT=$((TOTAL * 100 / MAX_TOTAL))

# ── Barra de progreso ─────────────────────────────────────────────────────────

bar=""
for i in $(seq 1 20); do
    [ $((i * 5)) -le $PCT ] && bar="${bar}█" || bar="${bar}░"
done

# ── Salida ────────────────────────────────────────────────────────────────────

echo "┌─────────────────────────────────────────────┐"
printf "│         Flash IAP15W413AS       [%s]       │\n" "$SOURCE"
echo "├──────────────────────────┬────────┬─────────┤"
echo "│ Región                   │  Usado │  Límite │"
echo "├──────────────────────────┼────────┼─────────┤"
printf "│ Código  (0x0000–0x1FFF)  │%5d B │  8192 B │\n" $SZ_CODE
printf "│ IAP/ROM (0x2000–0x33FF)  │%5d B │  5120 B │\n" $SZ_IAP
echo "├──────────────────────────┼────────┼─────────┤"
printf "│ Total                    │%5d B │ 13312 B │\n" $TOTAL
printf "│ Libres                   │%5d B │         │\n" $FREE
echo "├──────────────────────────┴────────┴─────────┤"
printf "│  [%s] %3d%%                │\n" "$bar" $PCT
echo "└─────────────────────────────────────────────┘"
[ "$SOURCE" = "map*" ] && echo "Nota: solo se midió la región de código (el .ihx no estaba disponible)."

# ── Comprobaciones de límite ──────────────────────────────────────────────────

RC=0
[ $SZ_CODE -gt $MAX_CODE  ] && { echo "ERROR: código ($SZ_CODE B) supera el límite de $MAX_CODE B.";  RC=2; }
[ $SZ_IAP  -gt $MAX_IAP   ] && { echo "ERROR: IAP/ROM ($SZ_IAP B) supera el límite de $MAX_IAP B.";  RC=2; }
[ $TOTAL   -gt $MAX_TOTAL ] && { echo "ERROR: total ($TOTAL B) supera el límite de $MAX_TOTAL B.";    RC=2; }
[ $RC -eq 0 ] && echo "OK."
exit $RC
