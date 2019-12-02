/*
 * oLog.c
 *
 * Created: 23.11.2019 12:34:44
 * Author : lipsk
 */ 

#include <avr/io.h>
#include "Task.h"
#include "CommonTypes.h"

extern uint8_t taskEnter;

int main(void)
{
	/* Call init function with all modules */
	Task_Init();
	
    /* Main loop with simple scheduler */
    while (1) 
    {
		if(taskEnter & TASK_ENTER_1S)
		{
			Task_1s();
			taskEnter &= ~TASK_ENTER_1S;
		}
				
		if(taskEnter & TASK_ENTER_100MS)
		{
			Task_100ms();
			taskEnter &= ~TASK_ENTER_100MS;
		}
				
		if(taskEnter & (TASK_ENTER_100MS | TASK_ENTER_1S))
		{
			Task_Idle();
		}
    }
}

