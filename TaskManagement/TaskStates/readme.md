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

