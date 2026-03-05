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
	ledstrings_bp      = 23,	///< "bP  " beep pattern        (0x17)
	ledstrings_daly    = 24,	///< "dALY" daily EN            (0x18)
	ledstrings_lan     = 25,	///< "LAn " language menu       (0x19)
	ledstrings_len     = 26,	///< "L-En" English             (0x1a)
	ledstrings_les     = 27,	///< "L-ES" Spanish             (0x1b)
	ledstrings_es_mon  = 28,	///< "Lun " ES Monday           (0x1c)
	ledstrings_es_tue  = 29,	///< "nAr " ES Tuesday  (Mar)   (0x1d)
	ledstrings_es_wed  = 30,	///< "niE " ES Wednesday (Mie)  (0x1e)
	ledstrings_es_thu  = 31,	///< "JuE " ES Thursday (Jue)   (0x1f)
	ledstrings_es_fri  = 32,	///< "UiE " ES Friday   (Vie)   (0x20)
	ledstrings_es_sat  = 33,	///< "SAb " ES Saturday (Sab)   (0x21)
	ledstrings_es_sun  = 34,	///< "don " ES Sunday   (Dom)   (0x22)
	ledstrings_all     = 35,	///< "ALL " EN all days         (0x23)
	ledstrings_tod     = 36,	///< "tod " ES all days (todos) (0x24)
};

#endif /* LEDFONTS_H_ */
