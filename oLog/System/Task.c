/*
 * Task.c
 *
 * Created: 24.11.2019 21:09:07
 *  Author: lipsk
 */ 

#include "Task.h"
#include "u8g2.h"
#include "OLED.h"
#include "Time.h"
#include "CommonTypes.h"

/* Global variables to store task mode. Value is set during ISR 
from timer1 when enough period of time elapses. */
task_t taskIsActive;

extern u8g2_t u8g2;
extern timer_t timer;
extern uint32_t cnt;


/* Task call only once on start to initialize
 * all interfaces and pins */
void Task_Init(void)
{
	Init_Oled(&u8g2);
	Init_Timer(&timer);
}

/* Task called every 10ms */
void Task_10ms(void)
{


}

/* Task called every 100ms */
void Task_100ms(void)
{
	OLED_FunScreen();
	UpdateTimer(&timer, cnt);
		
}

/* Task called every 1s */
void Task_1s(void)
{


}

/* Task called when other task do not have processor time */
void Task_Idle(void)
{
	asm ("nop");		//to prevent optimization
}