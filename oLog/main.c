/*
 * oLog.c
 *
 * Created: 23.11.2019 12:34:44
 * Author : lipsk
 */ 

#include <avr/io.h>
#include "Task.h"
#include "CommonTypes.h"

extern task_t taskIsActive;

int main(void)
{
	/* Call init function with all modules */
	Task_Init();
	
    /* Main loop with simple scheduler */
    while (1) 
    {
		if(TRUE == taskIsActive.Task_10ms)
		{
			Task_10ms();
			taskIsActive.Task_10ms = FALSE;
		}
		
		if(TRUE == taskIsActive.Task_100ms)
		{
			Task_100ms();
			taskIsActive.Task_100ms = FALSE;
		}
		
		if(TRUE == taskIsActive.Task_1s)
		{
			Task_1s();
			taskIsActive.Task_1s = FALSE;
		}
		
		if(TIME_ENTER_IDLE_TASK == (taskIsActive.Task_10ms | taskIsActive.Task_100ms | taskIsActive.Task_1s))
		{
			Task_Idle();
		}
    }
}

