/*
 * eeprom.h
 *
 *  Created on: 25 Jul 2017
 *      Author: shenghao
 */
/*!
 * \file eeprom.h
 * \brief Declarations for functions to access EEPROM / IAP on STC15 devices, and
 * EEPROM data storage table locations
 */

#ifndef EEPROM_H_
#define EEPROM_H_
#include <stdint.h>
#include "stc15w408as.h"

#define EEPROM_RESET_BYTE 0b11000000		///< Byte to be written into the IAP_CONTR register to enable EEPROM acess via the SFR registers \todo Change to read modify write operation and add note to change wait state length for different processors.
#define EEPROM_DISABLE_BYTE 0b10000000		///< Byte to be written into the IAP_CONTR register to disable EEPROM access via the SFR registers. Access using the MOVC instruction is still permissible on supported processors.
#define EEPROM_COMMAND_ERASE 0x03			///< Byte to be written into the IAP_CMD register to indicate an erase operation
#define EEPROM_COMMAND_WRITE 0x02			///< Byte to be written into the IAP_CMD register to indicate a write operation
#define EEPROM_COMMAND_READ  0x01			///< Byte to be written into the IAP_CMD register to indicate a read operation
#define EEPROM_COMMAND_STANDBY 0x00			///< Byte to be written into the IAP_CMD register to indicate a no-op
#define EEPROM_TRIGGER_MAGIC0 0x5a			///< First magic byte to be written into IAP_TRIG register
#define EEPROM_TRIGGER_MAGIC1 0xa5			///< Second magic byte to be written into IAP_TRIG register. A write of this byte after writing the first byte to the IAP_TRIG register triggers the IAP operation as indicated in IAP_CMD

#ifndef EEPROM_C_
extern __code __at(0x2000) uint16_t EEPROM_PWM_FROM_LDR_TABLE[1024];
extern __code __at(0x2000 + sizeof(EEPROM_PWM_FROM_LDR_TABLE)) uint16_t EEPROM_TEMP_FROM_THERMISTOR_TABLE[1024];
#endif

/*!
 * \brief Function called to start any sequence of EEPROM operations.
 *
 * Resets the EEPROM interface and sets up the appropriate wait states for
 * EEPROM operation.
 */
#endif /* EEPROM_H_ */
