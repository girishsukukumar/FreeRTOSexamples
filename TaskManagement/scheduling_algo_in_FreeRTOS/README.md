# Scheduling Algorithms in Free RTOS

Scheduling algorithm in FreeRTOS is configurable to a certain extend, in this session we will be discussing about it

The scheduling alogrithm in FreeRTOS can be configured by modifying three constants 
 
  * configUSE_TIME_SLICING 
  * configUSE_PREEMPTION 
  * configUSE_TICKLESS_IDLE 

These are defined in in configuration File FreeRTOSConfig.h. 

In all possible configurations the FreeRTOS scheduler will ensure tasks that share a priority are 
selected to enter the Running state in turn.  This ‘take it in turn’ policy is often referred to 
as ‘Round Robin Scheduling’.  A Round Robin scheduling algorithm does not guarantee time is shared
equally between tasks of equal priority, only that Ready state tasks of equal priority will enter 
the Running state in turn

#### Based the way Free RTOS is configured we can discuss three types of scheduling algorithms

 * Prioritized Pre-emptive Scheduling with Time Slicing 
 * Prioritized Pre-emptive Scheduling (without Time Slicing) 
 * Co-operative Scheduling 
 
## Prioritized Pre-emptive Scheduling with Time Slicing 
This method is very similar to the Fixed priority Pre-emptive scheduling we disucssed earlier.

##  Prioritized Pre-emptive Scheduling (without Time Slicing) 
This is where the concept of time slicing is not active. Means if two task of same priority 
gets in READY STATE Processor will not do a round robin based time sharing of the process and execute
the process.  Instead scheduler will handle scheduling the following way

* 1. When TASK1 is RUNNING STATE, a second task TASK2 of same priority got into READY STATE. Since Time Slicing is disabled
there won't be Round Robin kind of scheduling. Instead TASK1 will continue to RUN till it enters BLOCKED STATE. That is 
when TASK2 get scheduled and starts execution till it enters BLOCKED STATE

* 2. When TASK1 is in RUNNING STATE a second task TASK2 of higher priority got into  READY STATE. Since TASK2 is of higher
priority TASK1 is preempted out and TASK2 will start executing till it enters a BLOCKED STATE.

The advantage of disabling TIME Slicing is, it will reduce context switching a lot,which result in saving power. 
But each task to be written by keeping the fact that Time slicing is disabled, so that non of the task will hold 
the processor for longer time resulting in starvation of other tasks


##  Co-operative Scheduling 
