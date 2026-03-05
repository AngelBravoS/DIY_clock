/*
 * ledfonts.h
 *
 *  Created on: 22 Jul 2017
 *      Author: shenghao
 */

#ifndef LEDFONTS_H_
#define LEDFONTS_H_

#include "stdint.h"

extern const uint8_t ledfonts_numeric_normal[127];
extern const uint8_t ledfonts_numeric_flipped[127];
extern const char ledstrings[][5];

enum ledstrings_key {
	ledstrings_setc = 7,
	ledstrings_seta,
	ledstrings_alon,
	ledstrings_alof,
	ledstrings_conf,
	ledstrings_brig,		///<  "br  " brightness menu
	ledstrings_tcal,
	ledstrings_disp,
	ledstrings_bp,			///< "bP  " beep pattern menu
	ledstrings_daly,		///< "dALY" daily repeat
};

#endif /* LEDFONTS_H_ */
