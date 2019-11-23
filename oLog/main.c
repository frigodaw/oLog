/*
 * oLog.c
 *
 * Created: 23.11.2019 12:34:44
 * Author : lipsk
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "OLED.h"
#include "Init.h"
#include "u8g2.h"

u8g2_t u8g2;

int main(void)
{
	/* Call init function with all modules */
	Init_Main();
	
    /* Replace with your application code */
    while (1) 
    {
		u8g2_ClearBuffer(&u8g2);
		u8g2_SetFont(&u8g2, u8g2_font_helvR08_tf  );
		u8g2_DrawStr(&u8g2, 40, 30, "oLog GPS"); 
		u8g2_SendBuffer(&u8g2);
		

    }
}

