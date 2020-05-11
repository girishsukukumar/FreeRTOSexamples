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

![alt text](https://github.com/girishsukukumar/FreeRTOSexamples/blob/master/TaskManagement/taskCreationOnMultipleCores/output.jpg "Logo Title Text 1") Dual Core

