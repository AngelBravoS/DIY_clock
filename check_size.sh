#!/bin/bash

# Configuración del chip IAP15W413AS
MAX_SIZE=13312
FILE="Binary/DIY_Firmware_13k.ihx"

# Verificar si el archivo existe
if [ ! -f "$FILE" ]; then
    echo "Error: No se encuentra $FILE"
    exit 1
fi

# Crear binario temporal para medir tamaño real
TEMP_BIN=$(mktemp).bin
objcopy -I ihex -O binary "$FILE" "$TEMP_BIN" 2>/dev/null

if [ $? -ne 0 ]; then
    echo "Error: Falló la conversión. Asegúrate de tener 'binutils' instalado."
    rm -f "$TEMP_BIN"
    exit 1
fi

# Calcular tamaño
ACTUAL_SIZE=$(stat -c%s "$TEMP_BIN")
REMAINING=$((MAX_SIZE - ACTUAL_SIZE))
PERCENTAGE=$((ACTUAL_SIZE * 100 / MAX_SIZE))

# Limpieza
rm "$TEMP_BIN"

# Mostrar reporte
echo "------------------------------------------"
echo "Chip: IAP15W413AS (Límite: $MAX_SIZE bytes)"
echo "Archivo: $FILE"
echo "Tamaño en Flash: $ACTUAL_SIZE bytes"
echo "Uso de memoria: $PERCENTAGE%"
echo "------------------------------------------"

if [ $ACTUAL_SIZE -le $MAX_SIZE ]; then
    echo "✅ Quedan $REMAINING bytes libres."
else
    echo "❌ ERROR: El firmware excede la memoria por $((ACTUAL_SIZE - MAX_SIZE)) bytes."
    exit 2
fi