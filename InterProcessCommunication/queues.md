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
QueueHandle_t xQueueCreate( UBaseType_t uxQueueLength, UBaseType_t uxItemSize ); 
```

## MailBox
MailBox is a term used for inter task communication in Real Time OS. In FREERTOS a queue of unit length 
