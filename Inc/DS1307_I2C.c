/*
 * DS1307_I2C.c
 *
 *  Created on: Jan 28, 2024
 *      Author: ahadz
 */

#include <stdint.h>
#include "stm32f746xx.h"
#include "DS1307_I2C.h"

void DS1307_I2C_ENABLE_OSCILLATOR(void){
	I2C1_SELECT_AND_START_WR(DS1307_ADDRESS | I2C1_WRITE);
	I2C1_SEND_BYTE(SECONDS_REG);
	I2C1_SEND_BYTE(SECONDS_REG_CLEAR);
	I2C1_STOP();
}
