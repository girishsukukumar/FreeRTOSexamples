# Priority to a Task
The uxPriority parameter of the xTaskCreate() API function assigns an initial priority to the task being created.  

During Run time, (ie after scheduler has started the task) priority can be changed using the vTaskPrioritySet() API function. 
The maximum number of priorities available is set by the application-defined configMAX_PRIORITIES compile time 
configuration constant within FreeRTOSConfig.h.  Low numeric priority values denote low-priority tasks,
with priority 0 being the lowest priority possible. 

The range of available priorities is 0 to (configMAX_PRIORITIES – 1).  Any number of tasks can share the same 
priority—ensuring maximum design flexibility. 

```
#ifdef SMALL_TEST
#define configMAX_PRIORITIES			( 7 )
#else
#define configMAX_PRIORITIES			( 25 )
#endif

```

## Experiementing with Task priorities
### What happen when two tasks in a system has two different priorities.

The scheduler will always ensure that the highest priority task that is able to run is the task selected to enter the Running state. 
To understand this, in previous example we will change the task priotiries and see the difference in outputs

## Task1 is Given priority TWO and Task2 is given prioroty ONE
![Task1 > Task2 ]( https://github.com/girishsukukumar/FreeRTOSexamples/blob/master/TaskManagement/priority/output.jpg
  "Logo Title Text 1") 
  The scheduler will always select the highest priority task that is able to run.  Task 1 has a higher priority than Task 2 and is always able to run; therefore, Task 1 is the only task to ever enter the Running state.  As Task 2 never enters the Running state, it never prints out its string.  Task 2 is said to be ‘starved’ of processing time by Task 1.  
  
    
![Task1 > Task2 ]( https://github.com/girishsukukumar/FreeRTOSexamples/blob/master/TaskManagement/priority/different_priority.jpg
  "Logo Title Text 1") 

  
 ___ 
  
## Task1 is Given priority ONE and Task2 is given prioroty TWO
![Task2 > Task1 ]( https://github.com/girishsukukumar/FreeRTOSexamples/blob/master/TaskManagement/priority/output2.jpg
  "Logo Title Text 1")
  
  
## Task1 is Given priority TWO and Task2 is given prioroty TWO (Both Tasks are given same priority)
![Task1 == Task2]( https://github.com/girishsukukumar/FreeRTOSexamples/blob/master/TaskManagement/priority/output3.jpg
  "Logo Title Text 1") 
  
![Task1 == Task2]( https://github.com/girishsukukumar/FreeRTOSexamples/blob/master/TaskManagement/priority/same_priority.jpg

