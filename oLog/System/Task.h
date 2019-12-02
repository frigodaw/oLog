/*
 * Task.h
 *
 * Created: 24.11.2019 21:09:18
 *  Author: lipsk
 */ 


#ifndef TASK_H_
#define TASK_H_

#include <avr/io.h>
#include "Time.h"

#define TASK_ENTER_100MS	1u
#define TASK_ENTER_1S		2u

#define TASK_1S_CYCLES		((TIME_MS_IN_SEC)/(TIME_TIMER1_PERIOD_MS))	//number of timer1 (100ms) overflows to run task1


void Task_Init(void);
void Task_100ms(void);
void Task_1s(void);
void Task_Idle(void);



#endif /* TASK_H_ */