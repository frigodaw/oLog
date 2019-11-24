/*
 * Interrupts.c
 *
 * Created: 24.11.2019 21:49:20
 *  Author: lipsk
 */ 

#include <avr/interrupt.h>
#include "Task.h"
#include "CommonTypes.h"

/* Global variable which increments in interrupt when timer1 overflows */
uint32_t cnt;

extern task_t taskIsActive;

ISR(TIMER1_OVF_vect)
{
	cnt++;
	TCNT1 = 63974;   // for 1 sec at 16 MHz
	taskIsActive.Task_100ms = TRUE;
}