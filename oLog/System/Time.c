/*
 * Time.c
 *
 * Created: 24.11.2019 00:26:11
 *  Author: lipsk
 */ 

#include "Time.h"
#include <avr/io.h>
#include <avr/interrupt.h>		//for sei()

/* Global variable to store uptime values */
timer_t timer;

/* Function called to set timer values to 0 */
void Init_Timer(timer_t *timer)
{
	timer->sec_total    = 0u;
	timer->hours        = 0u;
	timer->minutes      = 0u;
	timer->seconds      = 0u;
	
	/* Enabling timer1 */
	TCNT1 = 63974;   // for 1 sec at 16 MHz
	TCCR1A = 0x00;
	TCCR1B = (1<<CS10) | (1<<CS12);;  // Timer mode with 1024 prescalar
	TIMSK1 = (1 << TOIE1) ;			  // Enable timer1 overflow interrupt(TOIE1)
	sei();        // Enable global interrupts by setting global interrupt enable bit in SREG
}

/* Function called to update timer structure */
void UpdateTimer(timer_t *timer, uint32_t cnt)
{
	timer->sec_total = cnt / TIME_CNT_COEFF;
	timer->hours = timer->sec_total / TIME_SEC_IN_HR;
	timer->minutes = (timer->sec_total % TIME_SEC_IN_HR) / TIME_MIN_IN_HR;
	timer->seconds = (timer->sec_total % TIME_SEC_IN_HR) % TIME_MIN_IN_HR;
}