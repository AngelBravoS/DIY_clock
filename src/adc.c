/*
 * adc.c
 *
 *  Created on: 25 Jul 2017
 *      Author: shenghao
 */

#define ADC_C_
#include "adc.h"
#undef ADC_C_


/*!
 * \brief ADC ISR
 *
 * The ADC ISR handles the update of the two global variables, each storing
 * the reading from the thermistor, and the reading from the ldr, respectively.esult(
 * It also handles the automatic brightness adjustment.
 *
 * Note that the ADC ISR is not responsible for the triggering of the ADC, the
 * main 10ms timebase performs that function. However, the ADC ISR reads the
 * ADC_CONTR register to determine what channel the ADC was triggered on, and
 * updates the global variables.
 *
 * \note The ADC ISR uses integer arithmetic only (IIR filter with bitshift).
 *
 */
void ISR_ADC(void) __interrupt(INT_ADC) __using(3) {
	uint16_t display_counts_buffer;
	ADC_CONTR ^= 0x10; //Clear the ADC flag
	/* Determine interrupt source and update globals */
	if(ADC_CONTR == ADC_SETUP_THERMISTOR){
		adc_thermistor_reading = ADC_RES;
	} else {
		adc_ldr_reading = ADC_RES;
		if(display_autobrightness) {
			/* Perform brightness adjustment - IIR filter alpha=1/64, integer only */
			uint16_t target = EEPROM_PWM_FROM_LDR_TABLE[adc_ldr_reading];
			if(target > display_counts)
				display_counts_buffer = display_counts + ((target - display_counts) >> 6);
			else
				display_counts_buffer = display_counts - ((display_counts - target) >> 6);
			INT_IP_PPCA = 0; //Block PCA interrupt from stacking on top of ADC ISR
			display_counts = display_counts_buffer;
			INT_IP_PPCA = 1; //Re-enable PCA interrupt high priority
		}
	}
}
