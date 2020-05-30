# Queues in FREERtos
In FreeRTOS we do not use the Term IPC or interprocess communication, rather we call  it Communication Mechanisum there three categories communication Mechanisum
1. Task to Task Communication
2. Interrupt to Task Communication
3. Task to Interrupt Communication

A Queue in FreeRTOS is very simillar to the queues what we had learned in data structure. It s FIFO list with a small difference. It is pretty easy to use and code the easy to understand.

A queue can hold a finite number of fixed size data items.  The maximum number of items a queue can hold is called its ‘length’.  Both the length and the size of each data item are set when the queue is created. 

Queues are normally used as First In First Out (FIFO) buffers, where data is written to the end (tail) of the queue and removed from the front (head) of the queue. 

Queues are objects in their own right that can be accessed by any task or ISR that knows of their existence.  Any number of tasks can write to the same queue, and any number of tasks can read from the same queue.  In practice it is very common for a queue to have multiple writers, but much less common for a queue to have multiple readers. 

A queue is created using the API  xQueueCreate()  it Returns a queue handle

```
**QueueHandle_t**  xQueueCreate( UBaseType_t uxQueueLength, UBaseType_t uxItemSize ); 
**uxQueueLength** : The maximum number of items that the queue being created can hold 
**uxItemSize**    : The size in bytes of each data item that can be stored in the queue. 
```
One unique property of the queues in FreeRTOS  where it differes from the traditonal queues is, in A traditional queue, you can only add a new element to the back of the queue and not any where else. Where in FreeRTOS you can add an element either to the back of the queue or to front of QUEUE.

To add an element to the front of queue:

```
BaseType_t xQueueSendToFront( QueueHandle_t xQueue, 
                              const void * pvItemToQueue,
                              TickType_t xTicksToWait );
```

To add an element to the back of the queue

```
BaseType_t xQueueSendToBack(QueueHandle_t xQueue,
                            const void * pvItemToQueue,
                            TickType_t xTicksToWait ); 
```

In both the cases, the first parameter is the handle to the queue, second parameter is the data that need to be added into the queue. In case queue is full, the task cannot write so it has to wait, this parameter specifies the amount of time the task need to wait before the queue has a space to write. In case this parameter is zero, the writting task will not wait.

To receive data from a queue a task has to use the following API

```
BaseType_t xQueueReceive( QueueHandle_t xQueue,                           
                          void * const pvBuffer,                           
                          TickType_t xTicksToWait ); 
```

An Example of Task to Task communication with Queues
```
static void vSenderTask( void *pvParameters ) 
{ 
     int32_t lValueToSend; BaseType_t xStatus; 
 
      lValueToSend = ( int32_t ) pvParameters; 
 
    /* As per most tasks, this task is implemented within an infinite loop. */     

    while(1)     
    {         
         xStatus = xQueueSendToBack( xQueue, &lValueToSend, 0 ); 
 
        if( xStatus != pdPASS )         
        {             
          /* The send operation could not complete because the queue was full -             
             this must be an error as the queue should never contain more than              
             one item! 
           */             
           vPrintString( "Could not send to the queue.\r\n" );         
        }     
    } 
} 
```

```
static void vReceiverTask( void *pvParameters )
{ 
    int32_t lReceivedValue; 
    BaseType_t xStatus; 
    
    const TickType_t xTicksToWait = pdMS_TO_TICKS( 100 ); 
  
    while(1)     
    {         
      
         if( uxQueueMessagesWaiting( xQueue ) != 0 )         
         {             
            vPrintString( "Queue is empty\r\n" );         
         } 
 
         xStatus = xQueueReceive( xQueue, &lReceivedValue, xTicksToWait ); 
 
        if( xStatus == pdPASS )   		
        {             
          vPrintStringAndNumber( "Received = ", lReceivedValue );         
        }         
        else         
        {             
            vPrintString( "Could not receive from the queue.\r\n" );         
        }     
    } 
} 
```

## MailBox
MailBox is a term used for inter task communication in Real Time OS. In FREERTOS a queue of unit length 
