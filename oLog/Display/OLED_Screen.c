/*
 * CFile1.c
 *
 * Created: 24.11.2019 21:35:29
 *  Author: lipsk
 */ 

#include <stdio.h>
#include "u8g2.h"
#include "OLED.h"
#include "SPI.h"
#include "Time.h"

/* Static buffers used to send data to OLED display */
char buff[16];
char buff_cnt[20];

extern u8g2_t u8g2;
extern timer_t timer;
extern uint32_t cnt;



void OLED_FunScreen(void)
{
		u8g2_ClearBuffer(&u8g2);
		u8g2_SetFont(&u8g2, u8g2_font_helvR08_tf  );
		u8g2_DrawStr(&u8g2, 40, 8, "oLog GPS");
		
		sprintf(buff_cnt, "%lu", cnt);
		u8g2_DrawStr(&u8g2, 45, 30, buff_cnt);
		
		sprintf(buff, "%d %s %d %s %d", timer.hours, " : ", timer.minutes, " : ", timer.seconds);
		u8g2_DrawStr(&u8g2, 45, 50, buff);
		u8g2_SendBuffer(&u8g2);
}