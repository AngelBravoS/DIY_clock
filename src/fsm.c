/*
 * fsm.c
 */
#define FSM_C_
#include "fsm.h"
#undef FSM_C_

#define ALARM_POLL_FORCE    0x60

uint8_t alarm_lastpoll = 0;
uint16_t transition_ticks = 0;

static uint16_t chrono_seconds = 0;
static uint16_t chrono_base = 0;
static uint8_t  chrono_running = 0;

static uint16_t cd_preset  = COUNTDOWN_PRESET; /* Tiempo preestablecido ajustable */
static uint16_t cd_seconds = COUNTDOWN_PRESET;
static uint16_t cd_base = 0;
static uint8_t  cd_running = 0;
static uint8_t  cd_finished = 0;
static uint8_t  cd_editing  = 0;  /* 1=editando el preset */

static void cd_display() {
	uint8_t mm = cd_seconds / 60;
	uint8_t ss = cd_seconds % 60;
	display_putbcd(((mm / 10) << 4) | (mm % 10),
	               ((ss / 10) << 4) | (ss % 10));
}

enum fsm_return fsm_home_fn() {
	static enum fsm_states_home curstate = fsm_home_start;
	uint8_t alarm_index = 0;
	uint16_t temp_cache;
	enum button_states menu_state;
	enum button_states select_state;
	menu_state   = button_read_and_clear_menu();
	select_state = button_read_and_clear_select();

	if(curstate == fsm_home_chrono) {
		if(select_state == BUTTON_PRESSED) {
			if(!chrono_running) { chrono_base = centiseconds(); chrono_running = 1; }
			else chrono_running = 0;
			select_state = BUTTON_NONE;
		}
		if(select_state == BUTTON_LONG_PRESSED) {
			chrono_seconds = 0; chrono_running = 0;
			select_state = BUTTON_NONE;
		}
	}

	if(curstate == fsm_home_countdown) {
		if(cd_finished) {
			/* Cualquier boton detiene el pitido y reinicia al preset */
			if(menu_state != BUTTON_NONE || select_state != BUTTON_NONE) {
				cd_finished = 0; cd_running = 0; cd_seconds = cd_preset;
				alarm_buzzer_off(); display_autobrightness = 1; display_flash = 0x00;
			}
			menu_state = BUTTON_NONE; select_state = BUTTON_NONE;
		} else if(cd_editing) {
			/* Modo edicion: M·L sale, M·S navega (limpiando edicion), S·S/held incrementa */
			if(menu_state == BUTTON_LONG_PRESSED) {
				cd_editing = 0; display_flash = 0x00;
				menu_state = BUTTON_NONE;
			}
			if(menu_state == BUTTON_PRESSED) {
				/* Navegar a otro estado: limpiar edicion, dejar que el handler avance */
				cd_editing = 0; display_flash = 0x00;
			}
			if((select_state == BUTTON_PRESSED) || (select_state == BUTTON_HELD_DOWN)) {
				cd_preset += 60;
				if(cd_preset > 3540) cd_preset = 60;  /* 1:00 minuto minimo, 59:00 maximo */
				cd_seconds = cd_preset;
				select_state = BUTTON_NONE;
			}
		} else {
			/* Modo normal */
			if(menu_state == BUTTON_LONG_PRESSED) {
				/* M·L: entrar en modo edicion del preset */
				cd_editing = 1; cd_running = 0; cd_seconds = cd_preset;
				display_flash = 0x0f;
				menu_state = BUTTON_NONE;
			}
			if(select_state == BUTTON_PRESSED) {
				if(!cd_running && cd_seconds > 0) { cd_base = centiseconds(); cd_running = 1; }
				else cd_running = 0;
				select_state = BUTTON_NONE;
			}
			if(select_state == BUTTON_LONG_PRESSED) {
				cd_seconds = cd_preset; cd_running = 0;
				select_state = BUTTON_NONE;
			}
		}
	}

	if(curstate != fsm_home_alarm) {
		if((menu_state == BUTTON_LONG_PRESSED) && (select_state == BUTTON_LONG_PRESSED)) {
			curstate = fsm_home_start; return fsm_ok;
		}
		if(menu_state == BUTTON_PRESSED) {
			transition_ticks = centiseconds();
			if(++curstate == fsm_home_end) curstate = fsm_home_start;
		}
		if(menu_state == BUTTON_LONG_PRESSED) {
			transition_ticks = centiseconds(); curstate = fsm_home_start;
		}
		if(select_state == BUTTON_PRESSED) {
			transition_ticks = centiseconds(); curstate = fsm_home_temp;
		}
		if(curstate != fsm_home_start && curstate != fsm_home_chrono && curstate != fsm_home_countdown) {
			if((centiseconds() - transition_ticks) > FSM_HOME_RESET_TICKS) {
				transition_ticks = centiseconds(); curstate = fsm_home_start;
			}
		}
	}

	ds1302_get_time();

	if(alarm_lastpoll != ds1302.minutes) {
		for(; alarm_index < NUM_ALARMS; alarm_index++) {
			if(alarm_dow_state(alarm_index, ds1302.day) && (alarms[alarm_index].dow_and_enable & 0x01)) {
				if((alarms[alarm_index].hour == ds1302.hour) && (alarms[alarm_index].minute == ds1302.minutes)) {
					alarm_bp = ALARM_PATTERNS[alarm_index] ? ALARM_PATTERNS[alarm_index] : 1;
					alarm_buzzer_on();
					display_autobrightness = 0;
					INT_IE_EA = 0; display_counts = DISPLAY_COUNTS_MAX; INT_IE_EA = 1;
					curstate = fsm_home_alarm;
				}
			}
		}
		alarm_lastpoll = ds1302.minutes;
	}

	switch(curstate) {
	case fsm_home_alarm:
	case fsm_home_time:
		if(curstate == fsm_home_alarm) {
			display_flash = 0x0f;
			if((menu_state != BUTTON_NONE) || (select_state != BUTTON_NONE)) {
				display_flash = 0x00; alarm_buzzer_off();
				display_autobrightness = 1; curstate = fsm_home_start;
			}
		}
		display_puttime(ds1302.hour, ds1302.minutes);
		if(ds1302.seconds % 2) display_colonon();
		if(curstate == fsm_home_time) {
			uint8_t ai, alarm_today = 0;
			for(ai = 0; ai < NUM_ALARMS; ai++)
				if((alarms[ai].dow_and_enable & 0x01) && alarm_dow_state(ai, ds1302.day)) alarm_today = 1;
			if(alarm_today) display_ampmon(); else display_ampmoff();
		}
		break;

	case fsm_home_chrono:
	{
		uint8_t mm, ss;
		if(chrono_running) {
			if((uint16_t)(centiseconds() - chrono_base) >= 100) {
				chrono_base += 100; chrono_seconds++;
				if(chrono_seconds >= 3600) { chrono_seconds = 0; chrono_running = 0; }
			}
		}
		mm = chrono_seconds / 60; ss = chrono_seconds % 60;
		display_putbcd(((mm/10)<<4)|(mm%10), ((ss/10)<<4)|(ss%10));
		if(chrono_running && (ss & 0x01)) display_colonon();
		break;
	}

	case fsm_home_countdown:
		if(cd_finished) {
			display_flash = 0x0f;
		} else {
			if(cd_running) {
				if((uint16_t)(centiseconds() - cd_base) >= 100) {
					cd_base += 100;
					if(cd_seconds > 0) {
						cd_seconds--;
					} else {
						cd_running = 0; cd_finished = 1;
						alarm_bp = 3;
						alarm_buzzer_on();
						display_autobrightness = 0;
						INT_IE_EA = 0; display_counts = DISPLAY_COUNTS_MAX; INT_IE_EA = 1;
					}
				}
			}
			if((cd_running && (cd_seconds & 0x01)) || cd_editing) display_colonon();
		}
		cd_display();
		break;

	case fsm_home_temp:
		temp_cache = EEPROM_TEMP_FROM_THERMISTOR_TABLE[adc_get_thermistor()];
		temp_cache = bcd_add_16(temp_cache, (ds1302_sram_data[DS1302_BBSRAM_SIZE-2] |
				(ds1302_sram_data[DS1302_BBSRAM_SIZE-1] << 0x08)));
		if(temp_cache > 0x0999) temp_cache = 0x0999;
		display_puttemp(temp_cache); display_periodon();
		break;

	case fsm_home_dow:
		display_puts(ledstrings[ledstrings_es_mon + ds1302.day - 1]);
		break;

	case fsm_home_date:
		display_putdate();
		break;
	}

	return fsm_repeat;
}

enum fsm_return fsm_set_fn() {
	static enum fsm_states_set curstate = fsm_set_label;
	uint8_t fsm_set_temp;
	enum button_states menu_state;
	enum button_states select_state;
	menu_state   = button_read_and_clear_menu();
	select_state = button_read_and_clear_select();

	if(curstate != fsm_set_label) {
		if(menu_state == BUTTON_LONG_PRESSED) {
			display_flash = 0x00; ds1302_set_time();
			alarm_lastpoll = ALARM_POLL_FORCE; curstate = fsm_set_label;
			return fsm_ok;
		}
		if(menu_state == BUTTON_PRESSED)
			if(++curstate == fsm_set_end) curstate = fsm_set_start;
	}

	fsm_set_temp = ((select_state == BUTTON_PRESSED) || (select_state == BUTTON_HELD_DOWN)) ? 1 : 0;

	switch(curstate) {
	case fsm_set_label:
		if(select_state == BUTTON_PRESSED) curstate++;
		if(menu_state == BUTTON_PRESSED) return fsm_fail;
		display_puts(ledstrings[ledstrings_setc]);
		break;
	case fsm_set_hh:
	case fsm_set_mm:
		if(curstate == fsm_set_hh) {
			ds1302.hour = bcd_add(ds1302.hour, fsm_set_temp);
			if(ds1302.hour > 0x23) ds1302.hour = 0x00;
			display_flash = 0x03;
		}
		if(curstate == fsm_set_mm) {
			ds1302.minutes = bcd_add(ds1302.minutes, fsm_set_temp);
			if(ds1302.minutes > 0x59) ds1302.minutes = 0;
			display_flash = 0x0c;
		}
		display_puttime(ds1302.hour, ds1302.minutes); display_colonon();
		break;
	case fsm_set_dd:
	case fsm_set_month:
		if(curstate == fsm_set_dd) {
			ds1302.date = bcd_add(ds1302.date, fsm_set_temp);
			if(ds1302.date > 0x31) ds1302.date = 0x00;
			if(DATE_DISPLAY_MMDD) display_flash = 0x0c; else display_flash = 0x03;
		}
		if(curstate == fsm_set_month) {
			ds1302.month = bcd_add(ds1302.month, fsm_set_temp);
			if(ds1302.month > 0x12) ds1302.month = 0x00;
			if(DATE_DISPLAY_MMDD) display_flash = 0x03; else display_flash = 0x0c;
		}
		display_putdate();
		break;
	case fsm_set_dow:
		ds1302.day = bcd_add(ds1302.day, fsm_set_temp);
		if(ds1302.day > 0x07) ds1302.day = 0x01;
		display_flash = 0x0f;
		display_puts(ledstrings[ledstrings_es_mon + ds1302.day - 1]);
		break;
	}
	return fsm_repeat;
}

enum fsm_return fsm_alarm_fn() {
	static enum fsm_states_alarm curstate = fsm_alarm_label;
	static enum fsm_substates_alarm sub_curstate = fsm_alarm_substate_toggle;
	uint8_t alarm_temp;
	enum button_states menu_state;
	enum button_states select_state;
	menu_state   = button_read_and_clear_menu();
	select_state = button_read_and_clear_select();
	alarm_temp = (select_state == BUTTON_PRESSED || select_state == BUTTON_HELD_DOWN) ? 1 : 0;

	switch(curstate) {
	case fsm_alarm_label:
		if(menu_state == BUTTON_PRESSED) return fsm_fail;
		if(select_state == BUTTON_PRESSED) { curstate = fsm_alarm_end; sub_curstate = fsm_alarm_substate_toggle; return fsm_repeat; }
		display_puts(ledstrings[ledstrings_seta]);
		break;
	default:
		switch(sub_curstate) {
		case fsm_alarm_substate_toggle:
			if(menu_state == BUTTON_LONG_PRESSED) {
				sub_curstate = fsm_alarm_substate_toggle; display_flash = 0x00; curstate = fsm_alarm_label;
				ds1302_calculate_CRC(); ds1302_write_SRAM(); alarm_lastpoll = ALARM_POLL_FORCE;
				return fsm_ok;
			}
			if(menu_state == BUTTON_PRESSED) {
				if(++curstate == (fsm_alarm_end + NUM_ALARMS)) curstate = fsm_alarm_end;
				break;
			}
			if(select_state == BUTTON_PRESSED) alarms[(curstate-fsm_alarm_end)].dow_and_enable ^= 1;
			if(select_state == BUTTON_LONG_PRESSED) { sub_curstate = fsm_alarm_substate_hh; break; }
			display_buffer[0] = ledfonts_numeric_normal['A'];
			display_buffer[1] = ledfonts_numeric_normal[(curstate-fsm_alarm_end)+1];
			display_putbool(alarms[(curstate-fsm_alarm_end)].dow_and_enable & 0x01);
			display_colonon();
			break;
		case fsm_alarm_substate_hh:
			if(menu_state == BUTTON_LONG_PRESSED) { display_flash=0x00; sub_curstate=fsm_alarm_substate_toggle; break; }
			if(menu_state == BUTTON_PRESSED) { display_flash=0x00; sub_curstate=fsm_alarm_substate_mm; break; }
			alarms[(curstate-fsm_alarm_end)].hour = bcd_add(alarms[(curstate-fsm_alarm_end)].hour, alarm_temp);
			if(alarms[(curstate-fsm_alarm_end)].hour > 0x23) alarms[(curstate-fsm_alarm_end)].hour = 0x00;
			display_flash=0x03; display_putbcd(alarms[(curstate-fsm_alarm_end)].hour, alarms[(curstate-fsm_alarm_end)].minute); display_colonon();
			break;
		case fsm_alarm_substate_mm:
			if(menu_state == BUTTON_LONG_PRESSED) { display_flash=0x00; sub_curstate=fsm_alarm_substate_toggle; break; }
			if(menu_state == BUTTON_PRESSED) { display_flash=0x00; sub_curstate=fsm_alarm_substate_dias; break; }
			alarms[(curstate-fsm_alarm_end)].minute = bcd_add(alarms[(curstate-fsm_alarm_end)].minute, alarm_temp);
			if(alarms[(curstate-fsm_alarm_end)].minute > 0x59) alarms[(curstate-fsm_alarm_end)].minute = 0x00;
			display_flash=0x0c; display_putbcd(alarms[(curstate-fsm_alarm_end)].hour, alarms[(curstate-fsm_alarm_end)].minute); display_colonon();
			break;
		case fsm_alarm_substate_dias:
			if(menu_state == BUTTON_LONG_PRESSED) { sub_curstate=fsm_alarm_substate_toggle; break; }
			if(menu_state == BUTTON_PRESSED) { sub_curstate=fsm_alarm_substate_bp; break; }
			if(select_state == BUTTON_LONG_PRESSED) { sub_curstate=fsm_alarm_substate_dow_mon; break; }
			display_puts(ledstrings[ledstrings_dias]);
			if((alarms[(curstate-fsm_alarm_end)].dow_and_enable & 0xfe) == 0xfe) display_ampmon(); else display_ampmoff();
			break;
		case fsm_alarm_substate_dow_mon:
		case fsm_alarm_substate_dow_tue:
		case fsm_alarm_substate_dow_wed:
		case fsm_alarm_substate_dow_thu:
		case fsm_alarm_substate_dow_fri:
		case fsm_alarm_substate_dow_sat:
		case fsm_alarm_substate_dow_sun:
			display_puts(ledstrings[ledstrings_es_mon + (sub_curstate - fsm_alarm_substate_dow_mon)]);
			if(alarm_dow_state(curstate-fsm_alarm_end, sub_curstate-fsm_alarm_substate_dias)) display_ampmon(); else display_ampmoff();
			if(select_state == BUTTON_PRESSED) { if(++sub_curstate > fsm_alarm_substate_dow_sun) sub_curstate=fsm_alarm_substate_all; break; }
			if(select_state == BUTTON_LONG_PRESSED) { alarm_dow_toggle(curstate-fsm_alarm_end, sub_curstate-fsm_alarm_substate_dias); break; }
			if(menu_state == BUTTON_PRESSED) { sub_curstate=fsm_alarm_substate_bp; break; }
			if(menu_state == BUTTON_LONG_PRESSED) { sub_curstate=fsm_alarm_substate_dias; break; }
			break;
		case fsm_alarm_substate_all:
			display_puts(ledstrings[ledstrings_all]);
			if((alarms[(curstate-fsm_alarm_end)].dow_and_enable & 0xfe) == 0xfe) display_ampmon(); else display_ampmoff();
			if(select_state == BUTTON_PRESSED) { sub_curstate=fsm_alarm_substate_dow_mon; break; }
			if(select_state == BUTTON_LONG_PRESSED) {
				if((alarms[(curstate-fsm_alarm_end)].dow_and_enable & 0xfe) == 0xfe) alarms[(curstate-fsm_alarm_end)].dow_and_enable &= 0x01;
				else alarms[(curstate-fsm_alarm_end)].dow_and_enable |= 0xfe;
				break;
			}
			if(menu_state == BUTTON_PRESSED) { sub_curstate=fsm_alarm_substate_bp; break; }
			if(menu_state == BUTTON_LONG_PRESSED) { sub_curstate=fsm_alarm_substate_dias; break; }
			break;
		case fsm_alarm_substate_bp:
			if(menu_state == BUTTON_PRESSED || menu_state == BUTTON_LONG_PRESSED) { alarm_buzzer_off(); sub_curstate=fsm_alarm_substate_toggle; break; }
			if(select_state == BUTTON_PRESSED) {
				if(ALARM_PATTERNS[(curstate-fsm_alarm_end)] < 1 || ALARM_PATTERNS[(curstate-fsm_alarm_end)] > 3) ALARM_PATTERNS[(curstate-fsm_alarm_end)] = 1;
				else if(++ALARM_PATTERNS[(curstate-fsm_alarm_end)] > 3) ALARM_PATTERNS[(curstate-fsm_alarm_end)] = 1;
				alarm_bp = ALARM_PATTERNS[(curstate-fsm_alarm_end)]; alarm_buzzer_on();
			}
			if(ALARM_PATTERNS[(curstate-fsm_alarm_end)] < 1 || ALARM_PATTERNS[(curstate-fsm_alarm_end)] > 3) ALARM_PATTERNS[(curstate-fsm_alarm_end)] = 1;
			display_buffer[0]=ledfonts_numeric_normal['b']; display_buffer[1]=ledfonts_numeric_normal['P'];
			display_buffer[2]=ledfonts_numeric_flipped[' ']; display_buffer[3]=ledfonts_numeric_normal['0'+ALARM_PATTERNS[(curstate-fsm_alarm_end)]];
			break;
		}
		break;
	}
	return fsm_repeat;
}

enum fsm_return fsm_config_fn() {
	static enum fsm_states_config curstate = fsm_config_label;
	static uint16_t config_tmp;
	uint16_t config_tmp2;
	enum button_states menu_state;
	enum button_states select_state;
	menu_state   = button_read_and_clear_menu();
	select_state = button_read_and_clear_select();

	switch(curstate) {
	case fsm_config_label:
		if(menu_state == BUTTON_PRESSED) { ds1302_calculate_CRC(); ds1302_write_SRAM(); transition_ticks = centiseconds(); return fsm_fail; }
		if(select_state == BUTTON_PRESSED) curstate++;
		display_puts(ledstrings[ledstrings_conf]);
		break;
	case fsm_config_br:
		if(menu_state == BUTTON_LONG_PRESSED) { curstate=fsm_config_label; return fsm_ok; }
		if(menu_state == BUTTON_PRESSED) curstate=fsm_config_thermistor_calib_label;
		if(select_state == BUTTON_PRESSED || select_state == BUTTON_HELD_DOWN) if(++BR_LEVEL > 10) BR_LEVEL = 0;
		if(BR_LEVEL == 0) { display_autobrightness=1; }
		else { display_autobrightness=0; INT_IE_EA=0; display_counts=DISPLAY_COUNTS_MIN+(uint16_t)(BR_LEVEL-1)*(DISPLAY_COUNTS_RANGE/9); INT_IE_EA=1; }
		display_buffer[0]=ledfonts_numeric_normal['b']; display_buffer[1]=ledfonts_numeric_normal['r'];
		if(BR_LEVEL==10) { display_buffer[2]=ledfonts_numeric_flipped['1']; display_buffer[3]=ledfonts_numeric_normal['0']; }
		else { display_buffer[2]=ledfonts_numeric_flipped[' ']; display_buffer[3]=ledfonts_numeric_normal['0'+BR_LEVEL]; }
		display_colonon();
		break;
	case fsm_config_thermistor_calib_label:
		if(menu_state == BUTTON_PRESSED) curstate=fsm_config_display_label;
		if(select_state == BUTTON_PRESSED) { curstate=fsm_config_thermistor_calib; config_tmp=(TEMP_OFFSET_LSB|(TEMP_OFFSET_MSB<<0x08)); }
		display_puts(ledstrings[ledstrings_tcal]);
		break;
	case fsm_config_thermistor_calib:
		if(menu_state == BUTTON_LONG_PRESSED) { curstate=fsm_config_thermistor_calib_label; TEMP_OFFSET_LSB=(config_tmp&0x00ff); TEMP_OFFSET_MSB=(config_tmp>>0x08); }
		if((select_state==BUTTON_PRESSED)||(select_state==BUTTON_HELD_DOWN)) config_tmp=bcd_add_16(config_tmp,0x0001);
		if(config_tmp>0x0140) config_tmp=0x0000;
		config_tmp2=EEPROM_TEMP_FROM_THERMISTOR_TABLE[adc_get_thermistor()]; config_tmp2=bcd_add_16(config_tmp2,config_tmp);
		if(config_tmp2>0x0999) config_tmp2=0x0999;
		display_puttemp(config_tmp2);
		break;
	case fsm_config_display_label:
		if(select_state==BUTTON_PRESSED) curstate=fsm_config_display_12h;
		if(menu_state==BUTTON_PRESSED) curstate=fsm_config_label;
		display_puts(ledstrings[ledstrings_disp]);
		break;
	case fsm_config_display_12h:
		display_puts(ledstrings[ledstrings_12h]); display_putbool(TIME_DISPLAY_12);
		if(select_state==BUTTON_PRESSED) SC_1 ^= 0x40;
		display_colonon();
		if(menu_state==BUTTON_PRESSED) if(++curstate==fsm_config_end) curstate=fsm_config_display_12h;
		if(menu_state==BUTTON_LONG_PRESSED) curstate=fsm_config_display_label;
		break;
	case fsm_config_display_mmdd:
		display_puts(ledstrings[ledstrings_mmdd]); display_putbool(DATE_DISPLAY_MMDD);
		if(select_state==BUTTON_PRESSED) SC_1 ^= 0x80;
		display_colonon();
		if(menu_state==BUTTON_PRESSED) if(++curstate==fsm_config_end) curstate=fsm_config_display_12h;
		if(menu_state==BUTTON_LONG_PRESSED) curstate=fsm_config_display_label;
		break;
	case fsm_config_display_remove_lzeroes:
		display_puts(ledstrings[ledstrings_lz]); display_putbool(DISPLAY_REMOVE_LEADING_ZEROES);
		if(select_state==BUTTON_PRESSED) SC_0 ^= 0x01;
		display_colonon();
		if(menu_state==BUTTON_PRESSED) if(++curstate==fsm_config_end) curstate=fsm_config_display_12h;
		if(menu_state==BUTTON_LONG_PRESSED) curstate=fsm_config_display_label;
		break;
	}
	return fsm_repeat;
}
