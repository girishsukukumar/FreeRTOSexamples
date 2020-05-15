# Memory Management in FREERTOS
## 1. What are Kernal Objects
Kernal Objects which are frequently used in FREERTOS are:
* Tasks
* Queues
* Semaphores
* Event groups.  

These Kernal Objects are dynamically created and destroyed during run time.  Each Kernal Object,  needs memory. When we says Kernal Objects are dynamically created it means the memory needed for these Kernal Objects are dynamically allocated at run-time ie when we call the respective API eg [ xTaskCreate () etc.] they are not allocated at the time of Compile Time.

FreeRTOS allocates RAM each time a kernel object is created, and frees RAM each time a kernel object is deleted.  This policy reduces design and planning effort, simplifies the API, and minimizes the RAM footprint. 

## 2. Scope of Dynamic Memory Allocation in FreeRTOS
Standard memory management libraries  malloc() and free() functions, are not suitable, for RTOS,
The reason why these functions cannot be used in RTOS is because
* They are not always available on small embedded systems. 
* Their implementation can be relatively large, taking up valuable code space. 
* They are rarely thread-safe. 
* They are not deterministic; the amount of time taken to execute the functions will differ from call to call. 
* They can suffer from fragmentation1.   
* They can complicate the linker configuration. 
* They can be the source of difficult to debug errors if the heap space is allowed to grow into memory used by other variables.  

## 3. Memory Allocation schemes in FreeRTOS
