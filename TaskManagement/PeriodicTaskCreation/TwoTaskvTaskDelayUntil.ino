int mainDELAY_LOOP_COUNT = 1000;
TaskHandle_t   Task1 ;
TaskHandle_t   Task2 ;
#define PRIORITY_ONE 1
#define PRIORITY_TWO 2
#define TEN_MILLI_SECONDS 10 
void setup() 
{
    Serial.begin(115200);

 xTaskCreate(myTaskOne, /* Pointer to the function that implements the task. */
             "TaskOne",/* Text name for the task. This is to facilitate debugging only. */
             10000, /* Stack depth - small microcontrollers will use much less stack than this. */
             NULL, /* This example does not use the task parameter. */
             PRIORITY_TWO, /* This task will run at priority 2. */
             &Task1); /* This example does not use the task handle. */


 xTaskCreate(myTaskTwo, /* Pointer to the function that implements the task. */
              "TaskTwo",/* Text name for the task. This is to facilitate debugging only. */
              10000, /* Stack depth - small microcontrollers will use much less stack than this. */
              NULL, /* This example does not use the task parameter. */
              PRIORITY_ONE, /* This task will run at priority 1. */
              &Task2 ); /* This example does not use the task handle. */

}
 void myTaskOne( void *pvParameters )
{
    const char *pcTaskName = "Task 1 is running\r\n";
    TickType_t xLastWakeTime; 
    volatile uint32_t ul; /* volatile to ensure ul is not optimized away. */
    /* As per most tasks, this task is implemented in an infinite loop. */
        xLastWakeTime = xTaskGetTickCount();
    /* The xLastWakeTime variable needs to be initialized 
       with the current tick     count.  Note that this is the 
       only time the variable is written to explicitly.     
       After this xLastWakeTime is automatically updated 
       within vTaskDelayUntil(). */ 

    for( ;; )
    {
     /* Print out the name of this task. */
        /* Delay for a period. */
        for( ul = 0; ul < mainDELAY_LOOP_COUNT; ul++ )
         {
            Serial.printf( "Task1 \n");
            int ticks ;
            ticks = pdMS_TO_TICKS(TEN_MILLI_SECONDS);
            //vTaskDelay(ticks);
             vTaskDelayUntil( &xLastWakeTime, ticks );
             /*  The reason why  xLastWakeTime is passed by reference is to
              *  update the values automatically 
              */            
         }
     }
}
void myTaskTwo( void *pvParameters )
{
    const char *pcTaskName = "Task 2 is running\r\n";
    TickType_t xLastWakeTime; 
    volatile uint32_t ul; /* volatile to ensure ul is not optimized away. */

    xLastWakeTime = xTaskGetTickCount();
    /* The xLastWakeTime variable needs to be initialized 
       with the current tick     count.  Note that this is the 
       only time the variable is written to explicitly.     
       After this xLastWakeTime is automatically updated 
       within vTaskDelayUntil(). */ 
    for( ;; )
    {
     /* Print out the name of this task. */
        /* Delay for a period. */
        for( ul = 0; ul < mainDELAY_LOOP_COUNT; ul++ )
         {
            Serial.printf( "Task2 \n");
            int ticks ;
            ticks = pdMS_TO_TICKS(TEN_MILLI_SECONDS);
            //vTaskDelay(ticks);
             vTaskDelayUntil( &xLastWakeTime, ticks );
             /* The reason why  xLastWakeTime is passed by reference is to
              *  update the values automatically 
              */
         }
     }
}
void loop() { }
