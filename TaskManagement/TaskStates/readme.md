# 4.0 Task States (Different States in which a FreeRTOS task will be in)

At any point of time a task in FreeRTOS will be either in 

* Running State
* Not Running State.

We saw in the previous examples when there two tasks, with same priorities, they both executed one after the other on a processor time sharing basis. When one of them has a higher priority, the higher prioirty task will starve the lower priority task. 
That means we just two reason why a task does not run

* While Processor Sharing while they alternate, one of them will be in not running state
* When two task with different priority comes, lower priority will not be in running state due to starvation

Like this there are many reasons why a task will be in a NOT RUNNING state. In this section we are going to see what the different reasons why as task is in not running state and based on which we will assign different states to the task.

## 4.1 How do we make two task of differnt priority run (with out causing starvation)
The Solution to this problem of starvation is, in the world of Real time systems do not leave everything to control of scheduler. Becuase scheduler is like a very focused person just use priority and run.  Instead of scheduler driven we make all task as Event driven This means every task runs as a response to an event. An event may be interrupt or message send to the task or any IPC related events. So all the tasks will be waiting for a specfic event to happen to start execution. This is called *Event Driven Programming*. A task which is waiting for an event is called in *BLOCKED STATE* . A task can be in *BLOCKED STATE* while waiting for two types of events

* Time related event (Waiting for delay to complete, Waiting for timer to expire etc) (Also know as Temporal Events)
* Waiting for an interrupt of a some data to arrive through IPC, they called Synchronization events

Synchronization event in FreeRTOS are from, queues, binary semaphores, counting semaphores, mutexes, recursive mutexes, event groups and direct to task notifications.

Let us see how to use a simple temporal event (time related) to over come starvation in the previous example where Task1 was starving task2

Here the example where we added a small delay to both the tasks this allowed Task1 and Task2 to execute in an alternate fashion
[Using Delay to solve starvation ](https://github.com/girishsukukumar/FreeRTOSexamples/blob/master/TaskManagement/TaskStates/TwoTaskDifferentPriorityTemporal.ino)

![alt text](https://github.com/girishsukukumar/FreeRTOSexamples/blob/master/TaskManagement/TaskStates/ouput.jpg "Logo Title Text 1") Removing Starvation of task using temporal delays

## Suspended State
The moment a task is created by using one of the Task craation APIs, the task will enter into the *list scheduled tasks*. This is the list  used by Scheduler to schedule the tasks. As long as a task is there in this list, the task will get scheduled. 

Now let us say, a we want to remove  a task from this list of scheduled tasks, so that we can reduce the scheduling over head. For example a task which is used for Debugging need to be temporarly disabled for a long period of time, we can ask FreeRTOS to take the task out of the *list of scheduled tasks*. When task is removed from the list of scheduled task we can says that task is in *Suspended state*.

The OS API used for suspending as task is *vTaskSuspend()* -> Removes the task from the schedulers list
Simillarly the API to put the task back in the list of scheduled task is *vTaskResume()* - Add the task back to scheduler list

This API is not used much only in special cases.

## Ready State
Tasks that are in the Not Running state but are not Blocked or Suspended are said to be in the Ready state.  They are able to run, and therefore ‘ready’ to run, but are not currently in the Running state. 

## State Transition Digaram

![alt text](https://github.com/girishsukukumar/FreeRTOSexamples/blob/master/TaskManagement/TaskStates/state_Transition_digram.jpg "Logo Title Text 1")  State Transition Diagram

##  FreeRTOS API vTaskDelay() 
In the previous example we have used the arduino SDK api called ***. delay()*** to temporarly put a task into BLOCKED STATE. The API that is recommeded by FreeRTOS for putting a task into BLOCKED STATE is  vTaskDelay() . The advantage of use  vTaskDelay()  is that we can specify delay is terms of Tick Interrupts, the periodic clock used by Scheduler to schedule tasks. This gives better control in the timing as we are depending the same clock used by the scheduler. But the salient point that need to keep in mind here is, it does not take the parameters in absolute time units like Seconds, milliseconds or Microseconds.

vTaskDelay() places the calling task into the Blocked state for a fixed number of tick interrupts.  The task does not use any processing time while it is in the Blocked state, so the task only uses processing time when there is actually work to be done. 

vTaskDelay() takes only one parameter as its input which the number of "Ticks" by which the task has to be kept in the BLOCKED STATE.
For example if call the api vTaskDelay(200) the task will remain in BLOCKED STATE for time period equivalent of 200 ticks. One tick in ESP is  1 millisecond. Hence the tasks will remain in BLOCKED STATE for 200 milliseconds without taking any CPU cycles. There is a easy way to call vTaskDelay() where you convert the amount of time the task has to be blocked state to equivalent Ticks. The fucntion is 
pdMS_TO_TICKS(). This API takes one input which is time in milliseconds and convert that into equivalent Ticks. Which can be used for providing the needed delay.

For example 
vTaskDelay( pdMS_TO_TICKS( 100 ) )  will keep the task in BLOCKED STATE for 100milliseconds

[Using vTaskDelay() to solve starvation ](https://github.com/girishsukukumar/FreeRTOSexamples/blob/master/TaskManagement/TaskStates/TwoTaskvTaskDelay.ino)

![alt text](https://github.com/girishsukukumar/FreeRTOSexamples/blob/master/TaskManagement/TaskStates/output2.jpg "Logo Title Text 1")  Output




