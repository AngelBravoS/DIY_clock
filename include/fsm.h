/*!
 * \file fsm.h
 *
 * \brief Declarations for the Finite State Machine that is executed as the
 * clock runs.
 *
 * \note Functions are not declared inline as they will be referenced more than
 * once.
 */

#ifndef FSM_H_
#define FSM_H_
#include <stdint.h>
#include "stc15w408as.h"
#include "ds1302.h"
#include "eeprom.h"
#include "display.h"
#include "ledfonts.h"
#include "uart.h"
#include "button.h"
#include "adc.h"
#include "alarm.h"
#include "timer.h"

/*!
 * \brief Time (in centiseconds) before the display returns to the HH:MM display
 * state when in any other fsm_home state except alarm, chrono and countdown.
 *
 * \warning Cannot exceed 0xff00
 * 0x0064 = 1 sec
 * 0x00C8 = 2 sec
 * 0x012C = 3 sec
 * 0x01f4 = 5 sec
 * 0x03e8 = 10 sec
 */
#define FSM_HOME_RESET_TICKS 0x0064

/*!
 * \brief Seconds preloaded into the countdown timer on reset. 59*60 = 3540.
 */
#define COUNTDOWN_PRESET 3540

/*!
 * \brief FSM return states
 */
enum fsm_return {
	fsm_ok = 0,		///< Proceed to next state
	fsm_repeat = 1,	///< Repeat state
	fsm_fail = 2,	///< Fail, proceed to another predefined state
};

/*!
 * \brief High level clock state machine states
 */
enum fsm_states_highlevel {
	fsm_home = 0,	///< Home state, main clock display
	fsm_set = 1,	///< Set state, set main clock
	fsm_alarm = 2,	///< Alarm state, set main alarm
	fsm_config = 3,	///< Config state, configure alarm settings
};

/*!
 * \brief Low level state machine states for the home state
 */
enum fsm_states_home {
	fsm_home_start     = 0,	///< FSM home state machine repetitive start location
	fsm_home_time      = 0,	///< Home state displaying time (hour, minutes)
	fsm_home_chrono    = 1,	///< Home state displaying chronometer (minutes, seconds)
	fsm_home_countdown = 2,	///< Home state displaying countdown timer
	fsm_home_temp      = 3,	///< Home state displaying temperature
	fsm_home_dow       = 4,	///< Home state displaying day of week
	fsm_home_date      = 5,	///< Home state displaying short date
	fsm_home_end,			///< FSM home state machine repetitive end location
	fsm_home_alarm,			///< Home state displaying alarm notification
};

/*!
 * \brief Low level state machine states for the set state
 */
enum fsm_states_set {
	fsm_set_label = 0,	///< Set state label display
	fsm_set_start = 1,	///< FSM set state machine repetitive start location
	fsm_set_hh    = 1,	///< Set state setting hh
	fsm_set_mm    = 2,	///< Set state setting mm
	fsm_set_dd    = 3,	///< Set state setting dd
	fsm_set_month = 4,	///< Set state setting month
	fsm_set_dow   = 5,	///< Set state setting day of week
	fsm_set_end,		///< FSM set state machine repetitive end location
};

/*!
 * \brief Low level state machine states for the alarm state
 */
enum fsm_states_alarm {
	fsm_alarm_label = 0,	///< Alarm state label display
	fsm_alarm_start = 1,	///< FSM alarm state machine repetitive start location
	fsm_alarm_end   = 1,	///< Alarm list base (A1..A5 = curstate - fsm_alarm_end gives 0..4)
};

/*!
 * \brief Even lower level state machine states for the alarm state
 */
enum fsm_substates_alarm {
	fsm_alarm_substate_toggle  = 0,		///< Alarm list: on/off + S·L enter edit
	fsm_alarm_substate_start   = 1,		///< FSM alarm sub-state machine start location
	fsm_alarm_substate_hh      = 1,		///< Alarm set hour
	fsm_alarm_substate_mm      = 2,		///< Alarm set minute
	fsm_alarm_substate_dias    = 3,		///< DIAS: cabecera; S·L entra ciclo DOW
	fsm_alarm_substate_dow_mon = 4,		///< Alarm set lunes
	fsm_alarm_substate_dow_tue = 5,		///< Alarm set martes
	fsm_alarm_substate_dow_wed = 6,		///< Alarm set miercoles
	fsm_alarm_substate_dow_thu = 7,		///< Alarm set jueves
	fsm_alarm_substate_dow_fri = 8,		///< Alarm set viernes
	fsm_alarm_substate_dow_sat = 9,		///< Alarm set sabado
	fsm_alarm_substate_dow_sun = 10,	///< Alarm set domingo
	fsm_alarm_substate_all     = 11,	///< ALL — todos los dias
	fsm_alarm_substate_bp      = 12,	///< Beep pattern per alarm (1-3)
	fsm_alarm_substate_end,				///< FSM alarm sub-state machine end location
};

/*!
 * \brief Low level state machine states for the config state
 */
enum fsm_states_config {
	fsm_config_label = 0,					///< Configuration state label display
	fsm_config_start = 1,					///< FSM configuration sub-state machine start location
	fsm_config_br = 1,						///< Configuration: Brightness level (0=auto, 1-10=manual)
	fsm_config_thermistor_calib_label = 2,	///< Configuration: Thermistor calibration label
	fsm_config_thermistor_calib = 3,		///< Configuration: Calibrate thermistor
	fsm_config_display_label = 4,			///< Configuration: Display configuration label
	fsm_config_display_12h = 5,				///< Configure time display format (12h or 24h)
	fsm_config_display_mmdd = 6,			///< Configure date display format (mmdd or ddmm)
	fsm_config_display_remove_lzeroes = 7,	///< Configure whether to remove leading zeroes
	fsm_config_end,							///< FSM configuration sub-state machine end location
};

/* FSM function declarations */
enum fsm_return fsm_home_fn();
enum fsm_return fsm_set_fn();
enum fsm_return fsm_alarm_fn();
enum fsm_return fsm_config_fn();

/*!
 * \brief FSM state transition table
 */
typedef enum fsm_return (*fsm_function)(void);

#ifndef FSM_C_
extern const fsm_function fsm_transition_table_fp[][3];
extern const uint8_t fsm_transition_table_s[][3];
#else
__code __at(0x3300) const fsm_function fsm_transition_table_fp[][3] = {
		{fsm_set_fn,fsm_home_fn,fsm_home_fn},
		{fsm_home_fn,fsm_set_fn,fsm_alarm_fn},
		{fsm_home_fn,fsm_alarm_fn,fsm_config_fn},
		{fsm_home_fn,fsm_config_fn,fsm_home_fn},
};
__code __at(0x3300 + sizeof(fsm_transition_table_fp))
		const uint8_t fsm_transition_table_s[][3] = {
		{fsm_set,fsm_home,fsm_home},
		{fsm_home,fsm_set,fsm_alarm},
		{fsm_home,fsm_alarm,fsm_config},
		{fsm_home,fsm_config,fsm_home},
};
#endif

#endif /* FSM_H_ */
