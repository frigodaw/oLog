/*
 * OLED.c
 *
 * Created: 23.11.2019 12:59:45
 *  Author: lipsk
 */ 

#include "u8g2.h" 
#include "OLED.h"
#include "SPI.h"

uint8_t u8x8_avr_delay(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{
	uint8_t cycles;

	switch(msg)
	{
		case U8X8_MSG_DELAY_NANO:     // delay arg_int * 1 nano second
		{
			// At 20Mhz, each cycle is 50ns, the call itself is slower.
		} break;

		case U8X8_MSG_DELAY_100NANO:    // delay arg_int * 100 nano seconds
		{
			// Approximate best case values...
			cycles = (100UL * arg_int) / (P_CPU_NS * CYCLES_PER_LOOP);

			if(cycles > CALL_CYCLES + RETURN_CYCLES + CALC_CYCLES)
				break;

			__asm__ __volatile__ (
				"1: sbiw %0,1" "\n\t" // 2 cycles
				"brne 1b" : "=w" (cycles) : "0" (cycles) // 2 cycles
			);
		}break;
		
		case U8X8_MSG_DELAY_10MICRO:    // delay arg_int * 10 micro seconds
		{
			for(int i=0 ; i < arg_int ; i++)
				_delay_us(10);
		}break;
		
		case U8X8_MSG_DELAY_MILLI:      // delay arg_int * 1 milli second
		{
			for(int i=0 ; i < arg_int ; i++)
				_delay_ms(1);
		}break;
		
		default:
			return 0;
	}
	return 1;
}


uint8_t u8x8_avr_gpio_and_delay(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{
	// Re-use library for delays

	switch(msg)
	{
		case U8X8_MSG_GPIO_AND_DELAY_INIT:  // called once during init phase of u8g2/u8x8
		{
			DISPLAY_CLK_DIR |= 1<<DISPLAY_CLK_PIN;
			DISPLAY_DATA_DIR |= 1<<DISPLAY_DATA_PIN;
			DISPLAY_CS_DIR |= 1<<DISPLAY_CS_PIN;
			DISPLAY_DC_DIR |= 1<<DISPLAY_DC_PIN;
			DISPLAY_RESET_DIR |= 1<<DISPLAY_RESET_PIN;
		}break;              // can be used to setup pins
		
		case U8X8_MSG_GPIO_SPI_CLOCK:        // Clock pin: Output level in arg_int
		{
			if(arg_int)
				DISPLAY_CLK_PORT |= (1<<DISPLAY_CLK_PIN);
			else
				DISPLAY_CLK_PORT &= ~(1<<DISPLAY_CLK_PIN);
		}break;
		
		case U8X8_MSG_GPIO_SPI_DATA:        // MOSI pin: Output level in arg_int
		{
			if(arg_int)
				DISPLAY_DATA_PORT |= (1<<DISPLAY_DATA_PIN);
			else
				DISPLAY_DATA_PORT &= ~(1<<DISPLAY_DATA_PIN);
		}break;
		
		case U8X8_MSG_GPIO_CS:        // CS (chip select) pin: Output level in arg_int
		{
			if(arg_int)
				DISPLAY_CS_PORT |= (1<<DISPLAY_CS_PIN);
			else
				DISPLAY_CS_PORT &= ~(1<<DISPLAY_CS_PIN);
		}break;
		
		case U8X8_MSG_GPIO_DC:        // DC (data/cmd, A0, register select) pin: Output level in arg_int
		{
			if(arg_int)
			DISPLAY_DC_PORT |= (1<<DISPLAY_DC_PIN);
			else
			DISPLAY_DC_PORT &= ~(1<<DISPLAY_DC_PIN);
		}break;
		
		case U8X8_MSG_GPIO_RESET:     // Reset pin: Output level in arg_int
		{
			if(arg_int)
			DISPLAY_RESET_PORT |= (1<<DISPLAY_RESET_PIN);
			else
			DISPLAY_RESET_PORT &= ~(1<<DISPLAY_RESET_PIN);
		}break;
		
		default:
		{
			if (u8x8_avr_delay(u8x8, msg, arg_int, arg_ptr))	// check for any delay msgs
			return 1;
			u8x8_SetGPIOResult(u8x8, 1);      // default return value
		}break;	
	}
	return 1;
}