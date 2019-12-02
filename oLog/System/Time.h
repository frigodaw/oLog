/*
 * Time.h
 *
 * Created: 24.11.2019 00:26:00
 *  Author: lipsk
 */ 


#ifndef TIME_H_
#define TIME_H_

#include <avr/io.h>

#define TIME_CNT_COEFF    10u
#define TIME_UC_IN_SEC    1000000u
#define TIME_UC_IN_MS	  1000u
#define TIME_MS_IN_SEC    1000u
#define TIME_SEC_IN_HR    3600u
#define TIME_MIN_IN_HR    60u

#define TIME_PRESCALAR					1024u
#define TIME_SCALED_FREQ				(uint16_t)((F_CPU)/(TIME_PRESCALAR))			//15625Hz
#define TIME_SCALED_PERIOD_UC			(uint8_t)((TIME_UC_IN_SEC)/(TIME_SCALED_FREQ))	//T=1/f  64us
#define TIME_TIMER1_PERIOD_MS			100u
#define TIME_TIMER1_TICKS_TO_OVERFLOW   (uint16_t)((uint32_t)(TIME_UC_IN_MS))*((uint32_t)(TIME_TIMER1_PERIOD_MS))/((uint32_t)(TIME_SCALED_PERIOD_UC))	//1562
#define TIME_TIMER1_MAX_TICKS           65535u
#define TIME_TIMER1_SET_TICKS			(uint16_t)((TIME_TIMER1_MAX_TICKS)-(TIME_TIMER1_TICKS_TO_OVERFLOW))


typedef struct timer_tag
{
	uint32_t sec_total;
	uint8_t hours;
	uint8_t minutes;
	uint8_t seconds;
} timer_t;

void Init_Timer(timer_t *timer);
void UpdateTimer(timer_t *timer, uint32_t cnt);

#endif /* TIME_H_ */