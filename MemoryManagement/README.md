# Memory Management in FREERTOS
## 1. What are Kernal Objects
Kernal Objects which are frequently used in FREERTOS are:
* Tasks
* Queues
* Semaphores
* Event groups.  

These Kernal Objects are dynamically created and destroyed during run time.  Each Kernal Objects is needs memory. When we says Kernal Objects are dynamically created it means the memory needed for these Kernal Objects are dynamically allocated at run-time, they are not allocated at the time of Compile Time.

FreeRTOS allocates RAM each time a kernel object is created, and frees RAM each time a kernel object is deleted.  This policy reduces design and planning effort, simplifies the API, and minimizes the RAM footprint. 

## 2. Scope of Dynamic Memory Allocation in FreeRTOS
## 3. Memory Allocation schemes in FreeRTOS
