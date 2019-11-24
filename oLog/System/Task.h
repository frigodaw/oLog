/*
 * Task.h
 *
 * Created: 24.11.2019 21:09:18
 *  Author: lipsk
 */ 


#ifndef TASK_H_
#define TASK_H_

#include <avr/io.h>

#define TIME_ENTER_IDLE_TASK  0u


/* Every timing task need to have its own pole in structure below */
typedef struct task_tag
{
	uint8_t Task_10ms : 1;
	uint8_t Task_100ms : 1;
	uint8_t Task_1s : 1;
}task_t;


void Task_Init(void);
void Task_10ms(void);
void Task_100ms(void);
void Task_1s(void);
void Task_Idle(void);



#endif /* TASK_H_ */