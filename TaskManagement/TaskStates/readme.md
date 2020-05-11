#Task States (Different States in which a FreeRTOS task will be in)
At any point of time a task in FreeRTOS will be either in 
*Running State
*Not Running State.

We saw in the previous examples when there two tasks, with same priorities, they both executed one after the other on a CPU time sharing basis. Where as if one of them has a higher priority, the higher prioirty will starve the lower priority task. Like this there are many reasone why a task will be in a NOT RUNNING state. In this section we are going to see what the different reasons why as task is in not running state and based on which we will assign different states to the task.

## Not Running State.
