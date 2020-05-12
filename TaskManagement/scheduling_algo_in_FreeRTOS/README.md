# Scheduling Algorithms in Free RTOS

Scheduling algorithm in FreeRTOS is configurable to a certain extend, in this session we will be discussing about it

The scheduling alogrithm in FreeRTOS can be configured by modifying three constants 
 
  configUSE_TIME_SLICING 
  configUSE_PREEMPTION 
  configUSE_TICKLESS_IDLE 
  
 These are defined in in configuration File FreeRTOSConfig.h. 

In all possible configurations the FreeRTOS scheduler will ensure tasks that share a priority are 
selected to enter the Running state in turn.  This ‘take it in turn’ policy is often referred to 
as ‘Round Robin Scheduling’.  A Round Robin scheduling algorithm does not guarantee time is shared
 equally between tasks of equal priority, only that Ready state tasks of equal priority will enter 
 the Running state in turn
 
 * Prioritized Pre-emptive Scheduling with Time Slicing 
 * Prioritized Pre-emptive Scheduling (without Time Slicing) 
 * Co-operative Scheduling 
 
 
