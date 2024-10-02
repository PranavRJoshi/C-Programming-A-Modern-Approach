// Write an array based implementation of the queue module described in Exercise 1. Use three integers to keep track of the queue's status, with one integer storing the position of the first empty slot in the array (used when an item is inserted), the second storing the position of the next item to be removed, and the third storing the number of items in the queue. An insertion or removal that would cause either of the first two integers to be incremented past the end of the array should instead reset the variable to zero, thus causing it to "wrap around" to the beginning of the array.

#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

#define QUEUE_SIZE 100

#define MALLOC_IS_NULL(x)                                                                           \
if(!(x)) {                                                                                          \
fprintf(stderr, "[ERROR] Memory Allocation Failed in file %s on line %d\n", __FILE__, __LINE__);    \
exit(EXIT_FAILURE);                                                                                 \
}

struct queue_type {
  Item contents[QUEUE_SIZE];
  int enqueue_number;     /* to track the number of insertion */
  int dequeue_number;     /* to track the number of removal */
};

static void terminate (const char *message) {
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

/* Create a queue */
Queue create (void) {
  struct queue_type *queue_create;
  queue_create = malloc(sizeof(struct queue_type));
  MALLOC_IS_NULL(queue_create);  

  queue_create->enqueue_number  = 0;
  queue_create->dequeue_number  = 0;

  return queue_create;
}

/* Check if the queue is empty */
bool is_empty (Queue q) {
  return q->enqueue_number == q->dequeue_number;
}

/* Check if the queue is full */
bool is_full (Queue q) {
  return q->enqueue_number == QUEUE_SIZE;
}

/* To add item in the queue (at the end) */
void enqueue (Queue q, Item i) {
  if (is_full(q)) {
    terminate("[ERROR] Queue is full.");
  }
  q->contents[q->enqueue_number++] = i;
}

/* To remove item in the queue (from the beginning) */
Item dequeue (Queue q) {
  if (is_empty(q)) {
    terminate("[ERROR] Queue is empty.");
  }
  return q->contents[q->dequeue_number++];
}

/* Get the first item in the queue, one that will be dequeued */
Item get_first_item (Queue q) {
  if (is_empty(q)) {
    terminate("[ERROR] Queue is empty.");
  }
  return q->contents[q->dequeue_number];
}

/* Get the last item in the queue, one that is recently enqueued */
Item get_last_item (Queue q) {
  if (is_empty(q)) {
    terminate("[ERROR] Queue is empty.");
  }
  int item_index = q->enqueue_number - 1;
  return q->contents[item_index];
}

/* Destroy the queue */
void destroy (Queue *q) {
  free(*q);
  *q = NULL;
}

