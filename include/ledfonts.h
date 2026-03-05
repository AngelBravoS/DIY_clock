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
	ledstrings_bp   = 23,		///< "bP  " beep pattern (array index 0x17)
	ledstrings_daly = 24,		///< "dALY" daily repeat  (array index 0x18)
};

#endif /* LEDFONTS_H_ */
