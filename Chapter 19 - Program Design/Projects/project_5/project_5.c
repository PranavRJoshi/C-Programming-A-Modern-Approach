// Q. Starting from the queue.h header of Exercise 1, create a file named queueADT.h that defines the following Queue type:
//      typedef struct queue_type *Queue;
//    queue_type is an incomplete structure type. Create a file named queueADT.c that contains the full definition of queue_type as well as definitions for all the functions in queue.h. Use a fixed-length array to store the items in a queue (see Exercise 3(a)). Create a file named queueclient.c (similar to the stackclient.c file of Section 19.4) that creates two queues and performs operations on them. Be sure to provide create and destroy functions for your ADT.


#include <stdio.h>
#include "queueADT.h"

int main (void) {

  Queue q1, q2;

  q1 = create();

  enqueue(q1, 10);
  enqueue(q1, 20);

  q2 = create();

  enqueue(q2, dequeue(q1));

  printf("[LOG] The dequeued item in q2 is: %d\n", dequeue(q2));
  printf("[LOG] The dequeued item in q1 is: %d\n", dequeue(q1));

  destroy(&q1);
  destroy(&q2);

  return 0;
}
