/*
 * main.h
 *
 *  Created on: Nov 19, 2023
 *      Author: ahadz
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <stdint.h>
#include "stm32f746xx.h"
#include "i2c1.h"
#include "DS1307_I2C.h"

uint8_t bcd2bin(uint8_t n) { return ((((n >> 4) & 0x0F) * 10) + (n & 0x0F)); }

uint8_t bin2bcd(uint8_t n) { return (((n / 10) << 4) | (n % 10)); }

#endif /* MAIN_H_ */
