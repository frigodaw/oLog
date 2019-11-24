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
#define TIME_SEC_IN_HR    3600u
#define TIME_MIN_IN_HR    60u

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