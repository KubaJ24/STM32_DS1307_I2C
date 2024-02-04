/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include "main.h"

/*
 * SCL	PB8
 * SDA	PB9
 */

// Zmienna do SysTick Timera - funkcja Delay
uint32_t Tick;

// Przed wgraniem ustawić czas początkowy
uint8_t SEC;
uint8_t	MIN;
uint8_t HOUR;
uint8_t DAY;
uint8_t DATE;
uint8_t MONTH;
// Rok liczony od 2000, tj 0 -> 2000, 1 -> 2001 itd.
uint8_t YEAR;

uint8_t *ptr_SEC = & SEC;
uint8_t	*ptr_MIN = & MIN;
uint8_t *ptr_HOUR = & HOUR;
uint8_t *ptr_DAY = & DAY;
uint8_t *ptr_DATE = & DATE;
uint8_t *ptr_MONTH = & MONTH;
uint8_t *ptr_YEAR = & YEAR;



void SysTick_Handler(void){
	//INCREASE SYSTEM TIMER
	Tick++;
}

void DELAY(uint32_t Delay_ms){
    uint32_t StartTime = Tick;
    while(Tick < (StartTime + Delay_ms))
    {
        // Just wait
    }
}

static inline uint8_t bcd2bin(uint8_t n) { return ((((n >> 4) & 0x0F) * 10) + (n & 0x0F)); }

static inline uint8_t bin2bcd(uint8_t n) { return (((n / 10) << 4) | (n % 10)); }

/*
 * Funkcja główna programu
 */

int main(void)
{

	SysTick_Config(16000000/1000);

	I2C1_GPIO_CONF();
	I2C1_CONF();

	DS1307_INIT_CONF();

	DS1307_SET_TIME(SEC, MIN, HOUR);
	DS1307_SET_DATE(DAY, DATE, MONTH, YEAR);

	while(1){

		DELAY(1000);

		DS1307_GET_TIME(ptr_SEC, ptr_MIN, ptr_HOUR);
		DS1307_GET_DATE(ptr_DAY, ptr_DATE, ptr_MONTH, ptr_YEAR);

		// Potrzebny Semihosting
		//printf("Godzina: %d : %d : %d", HOUR, MIN, SEC);
		//printf("        Data: %d / %d / %d / 20%d\n", DAY, DATE, MONTH, YEAR);

	}
}
