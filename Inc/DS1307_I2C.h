/*
 * DS1307_I2C.h
 *
 *  Created on: Jan 28, 2024
 *      Author: ahadz
 */

#ifndef DS1307_I2C_H_
#define DS1307_I2C_H_

/*
 * Pierwotny 7-bitowy adres zegara to 0x68. W definicji jest przesunięty o 1 w lewo. Przy wysłaniu, do LSB wpisuje się 1 lub 0 w zależności od kierunku transmisji.
 */
#define DS1307_ADDRESS			0xD0

/*
 * Adresy rejestrów zegara
 */
#define SECONDS_REG				0x00
#define MINUTES_REG				0x01
#define HOURS_REG				0x02
#define DAYS_REG				0x03
#define DATE_REG				0x04
#define MONTHS_REG				0x05
#define YEAR_REG				0x06
#define CONTROL_REG				0x07

/*
 * Zerowanie bitu CH - włącza zasilanie rejestrów
 */
#define SECONDS_REG_CLEAR		0x00

#include <stdint.h>
#include "stm32f746xx.h"
#include "i2c1.h"

/*
 * Włącza oscylator - zasilanie rejstrów zegara
 */
void DS1307_I2C_ENABLE_OSCILLATOR(void);

#endif /* DS1307_I2C_H_ */
