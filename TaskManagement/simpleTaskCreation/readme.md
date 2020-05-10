# An Example of creating two task in FreeRTOS on the same core
Create FreeRTOS application which willl create two tasks of the same priority using
the API xTaskCreate()

When this program runs, the two tasks will be created and they  run in parellel on the same core, on a time shared basis.
FREERTOS scheduler will keep switching, between the tasks. 
## How the task executes
[logo]: https://github.com/girishsukukumar/FreeRTOSexamples/blob/master/TaskManagement/simpleTaskCreation/example1.jpg "Logo Title Text 2"
![alt text]([https://github.com/girishsukukumar/FreeRTOSexamples/blob/master/TaskManagement/simpleTaskCreation/example1.jpg])

## Output of program 

 Task1
 
 Task1 
 
 Task1
 
 Task1

 Task2
 
 Task2 
 
 Task2
 
 Task2
 
 Task1
 
 Task1 
 
 Task1
 
 Task1

 
 
