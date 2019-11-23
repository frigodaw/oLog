/*
 * OLED.h
 *
 * Created: 23.11.2019 13:00:14
 *  Author: lipsk
 */ 

#ifndef OLED_H_
#define OLED_H_

#include <avr/io.h>
#include <util/delay.h>
#include "u8g2.h"


#define CALL_CYCLES 26UL
#define CALC_CYCLES 4UL
#define RETURN_CYCLES 4UL
#define CYCLES_PER_LOOP 4UL
#define P_CPU_NS (1000000000UL / F_CPU)


uint8_t u8x8_avr_delay(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);
uint8_t u8x8_avr_gpio_and_delay(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr);




#endif /* OLED_H_ */