#!/bin/bash
# Script para verificar tamaño del firmware

IHX_FILE="Binary/DIY_Firmware_13k.ihx"

if [ ! -f "$IHX_FILE" ]; then
    echo "Error: $IHX_FILE no encontrado"
    echo "Ejecuta 'make' primero"
    exit 1
fi

code=0
eeprom=0

while IFS= read -r line; do
    if [[ $line == :* ]]; then
        tipo="${line:7:2}"
        if [ "$tipo" == "00" ]; then
            len="${line:1:2}"
            addr="${line:3:4}"
            len_dec=$((16#$len))
            addr_dec=$((16#$addr))

            if [ $addr_dec -lt 8192 ]; then
                code=$((code + len_dec))
            else
                eeprom=$((eeprom + len_dec))
            fi
        fi
    fi
done < "$IHX_FILE"

total=$((code + eeprom))

if command -v bc &> /dev/null; then
    code_kb=$(echo "scale=2; $code/1024" | bc)
    eeprom_kb=$(echo "scale=2; $eeprom/1024" | bc)
    total_kb=$(echo "scale=2; $total/1024" | bc)
else
    code_kb=$((code * 100 / 1024))
    code_kb="${code_kb:0:-2}.${code_kb: -2}"
    eeprom_kb=$((eeprom * 100 / 1024))
    eeprom_kb="${eeprom_kb:0:-2}.${eeprom_kb: -2}"
    total_kb=$((total * 100 / 1024))
    total_kb="${total_kb:0:-2}.${total_kb: -2}"
fi

echo "════════════════════════════════════════════════"
echo "  Tamaño del firmware"
echo "════════════════════════════════════════════════"
echo "  Código (0x0000-0x1FFF):  $code bytes ($code_kb KB)"
echo "  Tablas EEPROM (0x2000+):  $eeprom bytes ($eeprom_kb KB)"
echo "  ─────────────────────────────────────────────"
echo "  TOTAL en .ihx:            $total bytes ($total_kb KB)"
echo ""
echo "  AP15W413AS código (13 KB):   $([ $code -le 13312 ] && echo '✓ CABE' || echo '✗ NO CABE')"
echo "════════════════════════════════════════════════"
