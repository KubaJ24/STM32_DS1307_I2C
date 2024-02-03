/*
 * i2c1.h
 *
 *  Created on: Jan 28, 2024
 *      Author: ahadz
 */

#ifndef I2C1_H_
#define I2C1_H_

#include <stdint.h>
#include "stm32f746xx.h"

#define I2C1_WRITE		0
#define I2C1_READ		1

void I2C1_GPIO_CONF(void);

void I2C1_CONF(void);

/*
 * Ustawia adres urządzenia docelowego i wysyła bit START
 * Ustawia I2C na wysyłanie
 * Funkcja kończy działanie, gdy wyzeruje się bit START (wysłano START i adres)
 * Może być konieczność użycia makra I2C1_WRITE (RTC przyjmuje 1 na LSB dla zapisu)
 */
void I2C1_SELECT_AND_START_WR(uint8_t Address);

/*
 * Ustawia adres urządzenia docelowego i wysyła bit START
 * Ustawia I2C na odczyt
 * Funkcja kończy działanie, gdy wyzeruje się bit START (wysłano START i adres)
 * Może być konieczność użycia makra I2C1_READ (RTC przyjmuje 0 na LSB dla odczytu)
 */
void I2C1_SELECT_AND_START_RD(uint8_t Address);

/*
 * Wysła 1 bajt danych
 */
void I2C1_SEND_BYTE(uint8_t Byte);

/*
 * Odbiera 1 bajt danych
 */
uint8_t I2C1_READ_BYTE(void);

/*
 * Wysyła bit START
 * Bit START w rejestrze jest automatycznie zerowany po wysłaniu bitu START i wysłaniu adresu SADD
 * Przed użyciem funkcji należy:
 * 	- Wstawić adres SADD
 * 	- Wybrać kierunek RD_WRN
 * 	- Ustawić liczbę bajtów do wysłania
 * Dopiero potem można użyć I2C1_START();
 */
static inline void I2C1_START(void) { I2C1->CR2 |= I2C_CR2_START; }

/*
 * Generuje STOP po zakończeniu obecnego transferu
 */
static inline void I2C1_STOP(void) { I2C1->CR2 |= I2C_CR2_STOP; }

/*
 * Ustawia adres urządznia docelowego
 */
static inline void I2C1_SET_ADDR(uint8_t Address) { I2C1->CR2 |= Address; }

/*
 * Ustawia I2C na wysyłanie danych
 */
static inline void I2C1_SET_WRITE(void) { I2C1->CR2 &= ~(I2C_CR2_RD_WRN); }

/*
 * Ustawia I2C na odbieranie danych
 */
static inline void I2C1_SET_READ(void) { I2C1->CR2 |= I2C_CR2_RD_WRN; }

/*
 * Ustawia I2C na wysłanie/odbieranie 1 bajtu
 */
static inline void I2C1_SET_1_BYTE_TRANSFER(void) { I2C1->CR2 |= (1 << 16); }

/*
 * Ustawia I2C na wysłanie/odbieranie 1 bajtu
 */
static inline void I2C1_WAIT_FOR_START(void) {
	while(I2C1->CR2 & I2C_CR2_START){  }
}

/*
 * Czeka na opróżnienie rejestru TXDR
 */
static inline void I2C1_WAIT_FOR_TXDR_EMPTY(void) {
	while(!(I2C1->ISR & I2C_ISR_TXE)){  }
}

/*
 * Czeka na zakończenie odbioru danych
 */
static inline void I2C1_WAIT_FOR_REC_COMPLETE(void) {
	while(!(I2C1->ISR & I2C_ISR_RXNE)){  }
}

/*
 * Wysyła NACK po odebraniu bajtu
 */
static inline void I2C1_SEND_NACK(void) { I2C1->CR2 |= I2C_CR2_NACK; }

/*
 * Czeka na zakończenie transferu danych
 */
static inline void I2C1_WAIT_FOR_TR_COMPLETE(void) {
	while(!(I2C1->ISR & I2C_ISR_TC)){  }
}

#endif /* I2C1_H_ */
