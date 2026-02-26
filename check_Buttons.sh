cd DIY_clock/

echo "=== CONSTANTES DE TIEMPO ==="
grep -n "0x20\|0x96\|LONG\|HELD" button.h button.c

echo ""
echo "=== LÓGICA ISR TIMER0 ==="
grep -A 30 "void timer_tick_isr" timer.c | grep -E "button|counter"

echo ""
echo "=== DETECCIÓN LONG PRESS ==="
grep -B 2 -A 5 "long_pressed\|0x20" button.c

echo ""
echo "=== MÁSCARAS DE SHIFT REGISTER ==="
grep -n "0x87\|0x80\|0x07" button.c

echo ""
echo "=== FLAGS EXPORTADOS ==="
grep "extern\|volatile" button.h | grep button
