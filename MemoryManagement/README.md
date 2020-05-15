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
FreeRTOS is when need to  memory it wont use malloc(), instead it calls pvPortMalloc().  FOr freeing memory instead of calling free(), it calls vPortFree().  pvPortMalloc() has the same prototype as the standard C library malloc() function, and vPortFree() has the same prototype as the standard C library free() function. 
pvPortMalloc() and vPortFree() are public functions, so can also be called from application code. 

Unlike in Linux,  pvPortMalloc() and vPortFree() are not a single implementation for memory allocation and freeing.  Instead there are five different implementations of these apis which are available in FreeRTOS. Each implementation is used for differnt contexts. Each implmentation is implemented in five different source files, heap_1.c, heap_2.c, heap_3.c, heap_4.c and heap_5.c. Each one of them are five different  memory allocation schemes in FreeRTOS.

## 4. Memory allocation scheme in details
### 4.1 Heap_1
This is a very basic version which implement only pvPortMalloc() and does not implements pvPortFree(). This is designed for applications which allocates all the memory in the beginning and does not allocate memory after or delete a task. In such apps, there  is no need to allocate memory and free it later and again allocate. These are meant for time and  critical application which uses a very simple and flat memory model which is very deterministic. They cannot handle a memory allocation failure during the start.  Hence there is not concept of fragmentation of memory in this model. 

The heap_1 allocation scheme subdivides a simple array of memory into smaller blocks, as calls to pvPortMalloc() are made.  The array is called the FreeRTOS heap.   The total size (in bytes) of the array is set by the definition configTOTAL_HEAP_SIZE within FreeRTOSConfig.h.  Defining a large array in this manner can make the application appear to consume a lot of RAM—even before any memory has been allocated from the array. 

### 4.2 Heap_2
### 4.3 Heap_3
### 4.4 Heap_4
### 4.5 Heap_5




