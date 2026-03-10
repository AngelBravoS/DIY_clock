/*
 * alarm.c
 */
#include "alarm.h"

/*
 * alarm_counter: used only within this module.
 * Must be reset to 0 by alarm_buzzer_on() before starting a new alarm.
 * Declared non-static so alarm.h can expose it to alarm_buzzer_on() if
 * that function is implemented as a macro. Encapsulate fully once
 * alarm_buzzer_on() becomes a regular function.
 */
volatile uint16_t alarm_counter;
volatile uint8_t  alarm_bp = 1; ///< Beep pattern: 1=1 beep/2s  2=2 beeps pausa larga  3=2 beeps pausa corta

void ISR_T2() __interrupt(INT_T2) __using(0) {
	static uint8_t cnt  = 15;  ///< Tono: 8/15 ticks activo dentro del beep
	static uint8_t tick = 0;   ///< Contador de fase de patron (30Hz)
	uint8_t beep_on;
	uint8_t cycle;

	/*
	 * Early exit: la alarma ha expirado. Silenciar y mantener el prescaler
	 * de cnt para no perder fase cuando vuelva a activarse.
	 * No se deshabilitan interrupciones globales: estamos dentro de una ISR
	 * y las interrupciones de igual o menor prioridad ya están bloqueadas
	 * por hardware en el 8051.
	 */
	if(alarm_counter >= ALARM_MAX_TIME) {
		ALARM_BUZZER_DRIVE_INACTIVE();
		if((--cnt) == 0) cnt = 15;
		return;
	}

	/*
	 * Patrones a 30Hz (1 tick = ~33ms):
	 *
	 * bP1: beep(0-14) | silencio(15-104)                                              ciclo=105 (~3.5s)
	 * bP2: beep(0-14) | gap(15-24) | beep(25-39) | silencio(40-99)                   ciclo=100 (~3.3s)
	 * bP3: beep(0-14) | gap(15-19) | beep(20-34) | gap(35-39) | beep(40-54) | sil(55-104)
	 *      triple bip estilo Casio                                                    ciclo=105 (~3.5s)
	 */
	switch(alarm_bp) {
	case 2:
		beep_on = (tick < 15) || (tick >= 20 && tick < 35);
		cycle   = 105;
		break;
	case 3:
		beep_on = (tick < 15) || (tick >= 20 && tick < 35) || (tick >= 40 && tick < 55);
		cycle   = 105;
		break;
	default: /* bP1 */
		beep_on = (tick < 15);
		cycle   = 105;
		break;
	}

	if(beep_on && cnt > 7)
		ALARM_BUZZER_DRIVE_ACTIVE();
	else
		ALARM_BUZZER_DRIVE_INACTIVE();

	if((--cnt) == 0) cnt = 15;
	if(++tick >= cycle) tick = 0;
	alarm_counter++;
}
