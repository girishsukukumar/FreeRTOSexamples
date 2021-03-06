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
![alt text](https://github.com/girishsukukumar/FreeRTOSexamples/blob/master/MemoryManagement/heap_1_1.jpg
 "Logo Title Text 1")
 #### Before creating a task and after creating the first task
 ![alt text](https://github.com/girishsukukumar/FreeRTOSexamples/blob/master/MemoryManagement/heap_1_2.jpg
 "Logo Title Text 1")
 #### After creating two tasks

### 4.2 Heap_2
Heap_2.c works by subdividing an array that is dimensioned by configTOTAL_HEAP_SIZE.  It uses a best fit algorithm to allocate memory it allows freering of memory .  Again, the array is statically declared, so will make the application appear to consume a lot of RAM, even before any memory from the array has been assigned. This model is discoutinued at is used only for backward compatability. 

### 4.3 Heap_3
Heap implemeted  library malloc() and free() functions. Just like in stadard C  the size of the heap is defined by the linker configuration, and the configTOTAL_HEAP_SIZE is not used.
The calls malloc() and free() are thread-safe, but the thread saftey is achived by temporarily suspending the Scheduler.  

### 4.4 Heap_4
heap_4 works by subdividing an array into smaller blocks. Key difference here is  it uses a first fit algorithm to allocate memory.
One major advantage of Heap_4 is it reduces Memory Fragmentation. To achive this it combines, pieces of free memory blocks in larger pieces.

IT uses a first fit algorithm to allocate memory.  When pvPortMalloc() it called, it searches for the  first free block of memory that is large enough to hold the requested  number of bytes. Then "Chops out" the requsted number of bytes from the free block,and balance amount of free memory is marked as free block. To demonstarte this
 Let us assume at  a give point there are 
 1. Three blocks of free memory in the system. 30 Bytes, 200 bytes and 310 bytes.
 2. Now call to pvPortMalloc() is made for 50 bytes of memory.
 3. The system will look at the the first block which is 30 bytes which is of course not enough. Then it looks at the next byte which is 200 bytes, it cuts out 50 bytes from this block and leave the rest 150 bytes as free memory. 
 4. Now another call to pvPortMalloc() is made for 100 bytes.
 5. System will look in the first block, skip it and then look at the next block which is 150 bytes and "cuts out" 100 bytes and mark the balance 50 bytes as free. 
 This way the system keeps allocating memory.
 The same memory scheme looks for ajacent free memory blocks and merge them into  single block to make them into a bigger block.
 In the above example
 Let us say the first the 100 bytes memroy is freed. That point of there will be two blocks of memory.
 (a) the one just now freed which is 100 bytes
 (b) the 50 bytes which was marked as free earlier.
 Now the memory allocation scheme will merge the 50 bytes free block and 100 bytes free block into one and declare as a single 150 byte block.
 
 

### 4.5 Heap_5
Heap_5 works very simillar to Heap_4 but over comes some of the limitation which Heap_4 has. Heap_4 looks for a block which is either equal to the size of the requested number of bytes or larger than the requested amount.  Heap_5 also works in a simillar way but it has tbe ability to pick up the requested memory from multiple free blocks, in case the requested amount is not available from a single free block.

## Memory Management Utility Functions
FreeRTOS is designed to run in Microcontrollers with Limited memory. Mostly it is targetted for Microcontroller which are designed as a SoC, hence during the development, testing and field deploymnet stage of any Real time applicaiton, is a  MUST to know the amout of free RAM available. So a dedicated API is implemented for this purpose.
 xPortGetFreeHeapSize() 
All call to this API returns the number of bytes which are unallocated in the Heap at the time it is called. 
 
During the execution cycle of an Real time System, if we call  *xPortGetFreeHeapSize()* it will return different values. THis is becuase the memeory needs of the system will vary from time to time. Some times there will be more amount of free memory and at other times there will be less amount of free memory. We can have to keep calling this function to get big picture of memory consumption pattern. For example a system designer wants to know what was  the lowest amout of free memory that was avaialble during the last 24 hours or 48 hours of operation. For this applicaiton need to make periodic calls to xPortGetFreeHeapSize() and keep a record.

But this is not an effective way to know the status of free memory becuase each call to xPortGetFreeHeapSize() will results in additional CPU resource and we have to take this execution time of this function call also into consideration during the system design time.
So there is another API which exactly solves this problem which is *xPortGetMinimumEverFreeHeapSize()*
When this API is called, it returns the number of unallocated bytes ever existed in the system since the application was started or since the system was powered on Till now. 
Which means over a period of time if we call this API it give us a complete picture of the amount of Free Heap that was available. It also answer the question whether the system has ran out of heap at any point of time or not. 
