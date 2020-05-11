# Priority to a Task
The uxPriority parameter of the xTaskCreate() API function assigns an initial priority to the task being created.  

During Run time, (ie after scheduler has started the task) priority can be changed using the vTaskPrioritySet() API function. 
The maximum number of priorities available is set by the application-defined configMAX_PRIORITIES compile time 
configuration constant within FreeRTOSConfig.h.  Low numeric priority values denote low-priority tasks,
with priority 0 being the lowest priority possible. 

The range of available priorities is 0 to (configMAX_PRIORITIES – 1).  Any number of tasks can share the same 
priority—ensuring maximum design flexibility. 

'
#ifdef SMALL_TEST
#define configMAX_PRIORITIES			( 7 )
#else
#define configMAX_PRIORITIES			( 25 )
#endif

'
