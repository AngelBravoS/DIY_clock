#!/bin/bash
set -e

CC=sdcc
CFLAGS="--std-sdcc11 --opt-code-size --fomit-frame-pointer --data-loc 0x24 --model-small --iram-size 256 --xram-size 256 --code-size 8192 --stack-size 128"
INCLUDES="-Iinclude -I/usr/share/sdcc/include/mcs51 -I/usr/share/sdcc/include"

mkdir -p Release Binary

SOURCES="main adc alarm button crc display ds1302 eeprom fsm ledfonts timer uart"

echo "Compiling..."
for src in $SOURCES; do
    echo "  src/$src.c"
    $CC -c $CFLAGS $INCLUDES src/$src.c -o Release/$src.rel
done

echo "Linking..."
$CC --data-loc 0x24 -o Binary/stc_led_clock_8k.ihx Release/*.rel

echo "Done!"
./check_size.sh
