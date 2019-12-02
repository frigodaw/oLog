/*
 * Interrupts.c
 *
 * Created: 24.11.2019 21:49:20
 *  Author: lipsk
 */ 

#include <avr/interrupt.h>
#include "Task.h"
#include "Time.h"
#include "CommonTypes.h"

/* Global variable which increments in interrupt when timer1 overflows */
uint32_t cnt;

extern uint8_t taskEnter;

ISR(TIMER1_OVF_vect)
{	
	cnt++;	//increment counter every 100ms
	
	TCNT1 = TIME_TIMER1_SET_TICKS;   // for 1 sec at 16 MHz
	taskEnter |= TASK_ENTER_100MS;
	
	/* cnt divisible by 10, enter task 1s */
	if(DIVISIBLE == (cnt % TASK_1S_CYCLES))
	{
		taskEnter |= TASK_ENTER_1S;
	}
}