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

void DS1307_SET_24H_MODE(void){
	I2C1_SELECT_AND_START_WR(DS1307_ADDRESS | I2C1_WRITE);
	I2C1_SEND_BYTE(HOURS_REG);
	I2C1_SEND_BYTE(HOURS_REG_CLEAR);
	I2C1_STOP();
}

void DS1307_INIT_CONF(void){
	DS1307_I2C_ENABLE_OSCILLATOR();
	DS1307_SET_24H_MODE();
}

void DS1307_SET_TIME(uint8_t SEC, uint8_t MIN, uint8_t HOUR){
	I2C1_SELECT_AND_START_WR(DS1307_ADDRESS | I2C1_WRITE);
	I2C1_SEND_BYTE(SECONDS_REG);
	I2C1_SEND_BYTE(SEC & 0x7F);
	I2C1_SEND_BYTE(MIN & 0x7F);
	I2C1_SEND_BYTE(HOUR & 0x3F);
	I2C1_STOP();
}

void DS1307_SET_DATE(uint8_t DAY, uint8_t DATE, uint8_t MONTH, uint8_t YEAR){
	I2C1_SELECT_AND_START_WR(DS1307_ADDRESS | I2C1_WRITE);
	I2C1_SEND_BYTE(DAYS_REG);
	I2C1_SEND_BYTE(DAY & 0x07);
	I2C1_SEND_BYTE(DATE & 0x3F);
	I2C1_SEND_BYTE(MONTH & 0x1F);
	I2C1_SEND_BYTE(YEAR);
	I2C1_STOP();
}

void DS1307_GET_TIME(uint8_t *ptr_SEC, uint8_t *ptr_MIN, uint8_t *ptr_HOUR){
	I2C1_SELECT_AND_START_WR(DS1307_ADDRESS | I2C1_WRITE);
	I2C1_SEND_BYTE(SECONDS_REG);
	I2C1_SELECT_AND_START_RD(DS1307_ADDRESS | I2C1_READ);
	*ptr_SEC = (I2C1_READ_BYTE() & 0x7F);
	I2C1_SELECT_AND_START_RD(DS1307_ADDRESS | I2C1_READ);
	*ptr_MIN = (I2C1_READ_BYTE() & 0x7F);
	I2C1_SELECT_AND_START_RD(DS1307_ADDRESS | I2C1_READ);
	*ptr_HOUR = (I2C1_READ_BYTE() & 0x3F);
}

void DS1307_GET_DATE(uint8_t *ptr_DAY, uint8_t *ptr_DATE, uint8_t *ptr_MONTH, uint8_t *ptr_YEAR){
	I2C1_SELECT_AND_START_WR(DS1307_ADDRESS | I2C1_WRITE);
	I2C1_SEND_BYTE(DAYS_REG);
	I2C1_SELECT_AND_START_RD(DS1307_ADDRESS | I2C1_READ);
	*ptr_DAY = (I2C1_READ_BYTE() & 0x07);
	I2C1_SELECT_AND_START_RD(DS1307_ADDRESS | I2C1_READ);
	*ptr_DATE = (I2C1_READ_BYTE() & 0x3F);
	I2C1_SELECT_AND_START_RD(DS1307_ADDRESS | I2C1_READ);
	*ptr_MONTH = (I2C1_READ_BYTE() & 0x1F);
	I2C1_SELECT_AND_START_RD(DS1307_ADDRESS | I2C1_READ);
	*ptr_YEAR = I2C1_READ_BYTE();
}
