#!/bin/bash

FILE="Binary/DIY_Firmware_13k.ihx"
#FILE="Binary/DIY_Firmware_4k.hex"

MAX_TOTAL=13312      # 13 KB totales del IAP15W413AS
TABLE_ADDR=8192      # Tu dirección __at(0x2000)

if [ ! -f "$FILE" ]; then
    echo "Error: No se encuentra $FILE"
    exit 1
fi

# 1. Convertir a binario real para medir ocupación física en la Flash
TEMP_BIN=$(mktemp).bin
objcopy -I ihex -O binary "$FILE" "$TEMP_BIN"

# 2. Medir hasta dónde llega el último byte de datos
TOTAL_BYTES=$(stat -c%s "$TEMP_BIN")
FREE_BYTES=$((MAX_TOTAL - TOTAL_BYTES))

# 3. Calcular ocupación de la tabla específicamente
# Si el archivo llega más allá de 0x2000, calculamos cuánto ocupa la tabla
if [ $TOTAL_BYTES -gt $TABLE_ADDR ]; then
    SIZE_BEFORE_TABLE=$TABLE_ADDR
    SIZE_FROM_TABLE=$((TOTAL_BYTES - TABLE_ADDR))
else
    SIZE_BEFORE_TABLE=$TOTAL_BYTES
    SIZE_FROM_TABLE=0
fi

# 4. Mostrar Reporte Visual
echo "------------------------------------------------"
echo "Estado de Memoria Flash: IAP15W413AS"
echo "------------------------------------------------"
echo -e "Código (hasta 0x1FFF):   $SIZE_BEFORE_TABLE bytes"
echo -e "Tablas (desde 0x2000):   $SIZE_FROM_TABLE bytes"
echo "------------------------------------------------"
echo -e "OCUPACIÓN TOTAL:         $TOTAL_BYTES / $MAX_TOTAL bytes"

# Barra de progreso simple
PERCENT=$((TOTAL_BYTES * 100 / MAX_TOTAL))
echo -n "Progreso: ["
for i in {1..20}; do
    if [ $((i * 5)) -le $PERCENT ]; then echo -n "#"; else echo -n "."; fi
done
echo "] $PERCENT%"
echo "------------------------------------------------"

rm "$TEMP_BIN"

# 5. Verificación de seguridad
if [ $TOTAL_BYTES -gt $MAX_TOTAL ]; then
    echo "❌ ERROR: El firmware ($TOTAL_BYTES bytes) NO CABE en los 13KB."
    exit 2
else
    echo "✅ ESPACIO DISPONIBLE: $FREE_BYTES bytes libres."
fi
