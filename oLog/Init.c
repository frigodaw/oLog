/*
 * Init.c
 *
 * Created: 23.11.2019 12:40:14
 *  Author: lipsk
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "Init.h"
#include "u8g2.h"
#include "OLED.h"

extern u8g2_t u8g2;

/* Function call only once on start to initialize
 * all interfaces and pins */
void Init_Main(void)
{
	Init_Oled();
	
}


/* Function called to initialize SPI interface which is 
 * used to communicate with OLED display */
void Init_SPI(void)
{
	
}


/* Function called to initialize OLED display */
void Init_Oled(void)
{
	u8g2_Setup_ssd1306_128x64_noname_f( &u8g2, U8G2_R0, u8x8_byte_4wire_sw_spi, u8x8_avr_gpio_and_delay );
	u8g2_InitDisplay(&u8g2);
	u8g2_SetPowerSave(&u8g2, 0);
}
