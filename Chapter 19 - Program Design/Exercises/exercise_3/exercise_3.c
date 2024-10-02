// Q. a. Write an array based implementation of the queue module described in Exercise 1. Use three integers to keep track of the queue's status, with one integer storing the position of the first empty slot in the array (used when an item is inserted), the second storing the position of the next item to be removed, and the third storing the number of items in the queue. An insertion or removal that would cause either of the first two integers to be incremented past the end of the array should instead reset the variable to zero, thus causing it to "wrap around" to the beginning of the array.
//    b. Write a linked-list implementation of the queue module described in Exercise 1. Use two pointers, one pointing to the first node in the list and the other pointing to the last node. When an item is inserted into the queue, add it to the end of the list. When an item is removed from the queue, delete the first node in the list.

#include <stdio.h>
#include "queue_1.h"
#include "queue_2.h"

void clear_input_stream (void);

int main (void) {
  int scanf_return_count = 0;
  Queue q1;

  int queue_size;

  for (;;) {
    printf("Enter the size of the queue: ");
    if ((scanf_return_count = scanf("%d", &queue_size)) != 1) {
      fprintf(stderr, "[ERROR] Insufficient Input Field Provided. Try Again.\n");
      clear_input_stream();
      continue;
    }
    clear_input_stream();
    scanf_return_count = 0;
    break;
  }

  q1 = create(queue_size);

  /*
   *  q1 is a wrap around queue, when the user enters 2 as the queue size,
   *  the resulting queue will hold { 50, 40 }, the steps are like this:
   *  First enqueue:  { 10 }
   *  Second enqueue: { 10, 20 }
   *  Third enqueue:  { 30, 20 }
   *  Fourth enqueue: { 30, 40 }
   *  Fifth enqueue:  { 40, 50 }
  */
  enqueue(q1, 10);
  enqueue(q1, 20);
  enqueue(q1, 30);
  enqueue(q1, 40);
  enqueue(q1, 50);

  int dequeue_item;
  dequeue_item = dequeue(q1);
  printf("[LOG] The dequeued item is: %d\n", dequeue_item);

  dequeue_item = dequeue(q1);
  printf("[LOG] The dequeued item is: %d\n", dequeue_item);

  destroy(&q1);

  Queue_ll qll;

  qll = create_ll();

  printf("[LOG] The address of qll is: %p\n", (void *) qll);

  enqueue_ll(qll, 123);
  enqueue_ll(qll, 456);

  int dequeue_ll_item;
  dequeue_ll_item = dequeue_ll(qll);
  printf("[LOG] The dequeued item in linked list is: %d\n", dequeue_ll_item);

  dequeue_ll_item = dequeue_ll(qll);
  printf("[LOG] The dequeued item in linked list is: %d\n", dequeue_ll_item);

  enqueue_ll(qll, 789);
  enqueue_ll(qll, 12);
  enqueue_ll(qll, 34);
  enqueue_ll(qll, 56);
  int first_item = get_first_item_ll(qll);
  printf("[LOG] The first item is: %d\n", first_item);
  int last_item = get_last_item_ll(qll);
  printf("[LOG] The last item is: %d\n", last_item);
  destroy_ll(&qll);

  printf("[LOG] The address of qll is: %p\n", (void *) qll);

  dequeue_ll_item = dequeue_ll(qll);
  printf("[LOG] The dequeued item in linked list is: %d\n", dequeue_ll_item);

  return 0;
}

void clear_input_stream (void) {
  int ch = getchar();

  while (ch != '\n' && ch != EOF) {
    ch = getchar();
  }
}

