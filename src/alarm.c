/*
 * alarm.c
 */
#include "alarm.h"

volatile uint16_t alarm_counter;
volatile uint8_t  alarm_bp = 1; ///< Beep pattern: 1=1 beep/2s  2=2 beeps pausa larga  3=2 beeps pausa corta

void ISR_T2() __interrupt(INT_T2) __using(0) {
	static uint8_t cnt  = 15;  ///< Tono: 8/15 ticks activo dentro del beep
	static uint8_t tick = 0;   ///< Contador de fase de patron (30Hz)
	uint8_t beep_on;
	uint8_t cycle;

	/*
	 * Patrones a 30Hz (1 tick = ~33ms):
	 *
	 * bP1: beep(0-14) | silencio(15-104)              ciclo=105 (~3.5s)
	 * bP2: beep(0-14) | gap(15-24) | beep(25-39) | silencio(40-99)  ciclo=100 (~3.3s)
	 * bP3: beep(0-14) | gap(15-24) | beep(25-39) | silencio(40-69)  ciclo=70  (~2.3s)
	 */
	if(alarm_bp == 2 || alarm_bp == 3) {
		beep_on = (tick < 15) || (tick >= 25 && tick < 40);
		cycle   = (alarm_bp == 2) ? 100 : 70;
	} else {
		beep_on = (tick < 15);
		cycle   = 105;
	}

	INT_IE_EA = 0;
	if(beep_on && cnt > 7 && (alarm_counter < ALARM_MAX_TIME))
		ALARM_BUZZER_DRIVE_ACTIVE();
	else
		ALARM_BUZZER_DRIVE_INACTIVE();
	INT_IE_EA = 1;

	if((--cnt) == 0) cnt = 15;
	if(++tick >= cycle) tick = 0;
	if(alarm_counter < ALARM_MAX_TIME)
		alarm_counter++;
}
