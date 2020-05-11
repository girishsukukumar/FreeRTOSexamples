# Concept of Idle Task in FREE RTOS

Let us assume two tasks are running in FreeRTOS environment. There will be times when both the tasks will enter into BLOCKED STATE, during this time the CPU/processor should not be kept idle.  Being a operating system responsible for many activites, lot of administartaive task are take up during time when all tasks are in BLOCKED STATE. 

So moment the FreeRTOS boots up and scheduler starts running it automatically creates a idle task in the background. The idle task has the lowest priority. That is priority if idle task is set to ZERO. This makes it possible for other tasks to Preempt Idle tasks when they moved from BLOCKED STATE to READY STATE.

## Common Uses of Idle Task
Common uses for the Idle task hook include: 

* Executing low priority, background, or continuous processing functionality. 
* Measuring the amount of spare processing capacity. (The idle task will run only when all higher priority application tasks have no work to perform; so measuring the amount of processing time allocated to the idle task provides a clear indication of how much processing time is spare.) 
* Placing the processor into a low power mode, providing an easy and automatic method of saving power whenever there is no application processing to be performed (although the power saving that can be achieved using this method is less than can be achieved by using the tick-less idle mode described in, Low Power Support). 

## Application Specific Functionality in Idle Task

PRogrammers can  add application specific functionality directly into the idle task through the use of an idle hook (or idle callback) function—a function that is called automatically by the idle task once per iteration of the idle task loop.  

 ## How to write a application specific hook function for idle Task
 
One of the common uses of idle task to find out free CPU/Processor Time. This is true with Windows too.  So if we get to know how many time the idle task function has been looped, we can get to know for how much time equivalent to ticks the CPU/processor was free. This is how it is done

####In Arduino the loop() function is hooked to freeRtos, loop() function  will be called whenever the scheduler runs its Idle Task.



