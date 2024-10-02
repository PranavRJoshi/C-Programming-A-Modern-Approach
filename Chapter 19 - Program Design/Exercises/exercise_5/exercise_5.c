// Q. Modify the queue.h header of Exercise 1 so that it defines a Queue type, where Queue is a structure containing a fixed-length array (see Exercise 3(a)). Modify the functions in queue.h to take a Queue * parameter.

#include <stdio.h>
#include "queue.h"

int main (void) {
  Queue q1;

  q1 = create();

  enqueue(q1, 1);
  enqueue(q1, 10);
  enqueue(q1, 100);

  int dequeue_item;

  dequeue_item = dequeue(q1);
  printf("[LOG] The dequeued item is: %d\n", dequeue_item);

  dequeue_item = dequeue(q1);
  printf("[LOG] The dequeued item is: %d\n", dequeue_item);

  destroy(&q1);

  dequeue_item = dequeue(q1);
  printf("[LOG] The dequeued item is: %d\n", dequeue_item);
}
