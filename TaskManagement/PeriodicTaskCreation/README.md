## How to create Periodic Task using FreeRTOS API [without using delay() or vTaskDelay() ]

vTaskDelay() parameter specifies the number of tick interrupts that should occur between a task calling vTaskDelay(), and the same task once again transitioning out of the Blocked state. 

If we want to create Periodic task which gets executed as very accurate intervals, it is not a good idea to use vTaskDelay(). This is becuase the length of time the task remains in the blocked state is specified by the vTaskDelay() parameter, *but the time at which the task leaves the blocked state is relative to the time at which vTaskDelay() was called*. This relative timing can use timing issues. This exactly where we use a differnt API  vTaskDelayUntil() 

 vTaskDelayUntil() takes two  parameter which specify the exact number of "Ticks" after which the task has to be moved from BLOCKED state to READY STATE
 
 vTaskDelayUntil() is the API function that should be used when a fixed execution period is required (where you want your task to execute periodically with a fixed frequency), as the time at which the calling task is unblocked is absolute, rather than relative to when the function was called (as is the case with vTaskDelay()). 
 
 
[Using vTaskDelay() to solve starvation ](https://github.com/girishsukukumar/FreeRTOSexamples/blob/master/TaskManagement/PeriodicTaskCreation/TwoTaskvTaskDelayUntil.ino)

![alt text](https://github.com/girishsukukumar/FreeRTOSexamples/blob/master/TaskManagement/PeriodicTaskCreation/ouput3.jpg "Logo Title Text 1")  Output

 
 

