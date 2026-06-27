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
	ledstrings_setc = 0,	///< "SEtC" set clock label
	ledstrings_seta,		///< "SEtA" set alarm label
	ledstrings_alon,		///< "ALon" alarm on
	ledstrings_alof,		///< "ALoF" alarm off
	ledstrings_conf,		///< "ConF" config label
	ledstrings_brig,		///< "br  " brightness
	ledstrings_tcal,		///< "tCAL" thermistor calibration
	ledstrings_disp,		///< "diSP" display config label
	ledstrings_12h,			///< "12  " 12h/24h format
	ledstrings_mmdd,		///< "nd  " MMDD/DDMM date format
	ledstrings_lz,			///< "L0  " remove leading zeroes
	ledstrings_bp,			///< "bP  " beep pattern
	ledstrings_dias,		///< "dIAS" cabecera submenu dias de activacion
	ledstrings_es_mon,		///< "Lun " lunes
	ledstrings_es_tue,		///< "MAr " martes
	ledstrings_es_wed,		///< "MiE " miércoles
	ledstrings_es_thu,		///< "JuE " jueves
	ledstrings_es_fri,		///< "UiE " viernes
	ledstrings_es_sat,		///< "SAb " sábado
	ledstrings_es_sun,		///< "doN " domingo
	ledstrings_all,			///< "ALL " todos los dias (opcion seleccionar todos)
	ledstrings_cd,			///< "Cd  " cuenta regresiva
};

#endif /* LEDFONTS_H_ */
