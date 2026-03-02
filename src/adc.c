/*
 * adc.c
 *
 *  Created on: 25 Jul 2017
 *      Author: shenghao
 */

#define ADC_C_
#include "adc.h"
#undef ADC_C_


void adc_calibrate_LDR(uint16_t ldr_min,uint16_t ldr_max) {
	/* Bresenham/DDA linear interpolation - pure 16-bit, no library needed.
	 * pwm decrements from COUNTS_MAX to COUNTS_MIN across [ldr_min, ldr_max].
	 * step     = COUNTS_RANGE / ldr_range  (integer step per ADC count)
	 * err_step = COUNTS_RANGE % ldr_range  (fractional remainder, Bresenham)
	 * Max error vs float: 1 count out of 59604 range - negligible.
	 */
	uint16_t ldr_range = ldr_max - ldr_min;
	uint16_t step      = DISPLAY_COUNTS_RANGE / ldr_range;
	uint16_t err_step  = DISPLAY_COUNTS_RANGE % ldr_range;
	uint16_t err_acc   = 0;
	uint16_t pwm_val   = DISPLAY_COUNTS_MAX;
	uint16_t i;

	eeprom_start();
	eeprom_erase(0x00);
	eeprom_erase(0x02);
	eeprom_erase(0x04);
	eeprom_erase(0x08);
	for(i=0;i<1024;i++){
		if((i >= ldr_min) && (i <= ldr_max)){
			eeprom_write(2*i,   pwm_val & 0x00ff);
			eeprom_write((2*i)+1, pwm_val >> 8);
			pwm_val -= step;
			err_acc += err_step;
			if(err_acc >= ldr_range){
				pwm_val--;
				err_acc -= ldr_range;
			}
			continue;
		}
		if(i < ldr_min){
			eeprom_write((2*i),   DISPLAY_COUNTS_MAX & 0x00ff);
			eeprom_write((2*i)+1, DISPLAY_COUNTS_MAX >> 8);
			continue;
		}
		eeprom_write((2*i),   DISPLAY_COUNTS_MIN & 0x00ff);
		eeprom_write((2*i)+1, DISPLAY_COUNTS_MIN >> 8);
	}
	eeprom_end();
}

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
