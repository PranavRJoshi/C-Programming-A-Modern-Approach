// Write a linked-list implementation of the queue module described in Exercise 1. Use two pointers, one pointing to the first node in the list and the other pointing to the last node. When an item is inserted into the queue, add it to the end of the list. When an item is removed from the queue, delete the first node in the list.

#include <stdio.h>
#include <stdlib.h>
#include "queue_2.h"

#define MALLOC_IS_NULL(x)                                                                           \
if(!(x)) {                                                                                          \
fprintf(stderr, "[ERROR] Memory Allocation Failed in file %s on line %d\n", __FILE__, __LINE__);    \
exit(EXIT_FAILURE);                                                                                 \
}

#define IS_PARAM_NULL(x)                                                \
if (!(x)) {                                                             \
fprintf(stderr, "[ERROR] The Queue is not initialized.\n");             \
exit(EXIT_FAILURE);                                                     \
}

struct node {
  Item_ll content;
  struct node *next;
};

struct queue_type_ll {
  struct node *enqueue_ref;
  struct node *dequeue_ref;
};  /* typedef of Queue_ll */

static void terminate (const char *message) {
  printf("%s\n", message);
  exit(EXIT_FAILURE);
}

/* Create a queue */
Queue_ll create_ll (void) {
  struct queue_type_ll *queue_ll;
  queue_ll = malloc(sizeof(struct queue_type_ll));
  MALLOC_IS_NULL(queue_ll);
  queue_ll->enqueue_ref = NULL;
  queue_ll->dequeue_ref = NULL;

  return queue_ll;
}

/* Check if the queue is empty */
bool is_empty_ll (Queue_ll q) {
  IS_PARAM_NULL(q);
  if (q->enqueue_ref == NULL && q->dequeue_ref == NULL) {
    return true;
  }
  return false;
}

/* Check if the queue is full */
bool is_full_ll (Queue_ll q) {
  IS_PARAM_NULL(q);
  return false;
}

/* To add item in the queue (at the end) */
void enqueue_ll (Queue_ll q, Item_ll i) {
  IS_PARAM_NULL(q);
  struct node *temp;
  temp = malloc(sizeof(struct node));
  MALLOC_IS_NULL(temp);

  temp->content   = i;
  temp->next      = q->enqueue_ref;
  q->enqueue_ref  = temp;
}

/* To remove item in the queue (from the beginning) */
Item_ll dequeue_ll (Queue_ll q) {
  IS_PARAM_NULL(q);

  if (is_empty_ll(q)) {
    terminate("[ERROR] Queue_ll is empty.");
  }

  struct node *prev, *cur;

  cur   = q->enqueue_ref;
  prev  = cur;

  /*
   * Traverse through the linked list to make cur point to the last node, and
   * prev point to the node before the last node
  */
  while (cur->next != NULL) {
    prev  = cur;
    cur   = cur->next;
  }

  /*
   * q->enqueue_ref will point to the node which is recently being added, and 
   * q->dequeue_ref will point to the node which is one before the node being dequeued.
   * cur != q->dequeue_ref means the node is not the last node in the queue.
  */
  if (cur != q->dequeue_ref) {
    prev->next      = NULL;
    q->dequeue_ref  = prev;
  } 

  /*
   * The first condition is to check if the queue only has one item and that is the one being removed.
   * The second condition is to check if the queue has dequeued all but one item, which is being dequeued, making the queue empty.
  */
  if (q->dequeue_ref == NULL || cur == q->dequeue_ref) {
    q->dequeue_ref = NULL;
    q->enqueue_ref = NULL;
  }

  Item_ll dequeue_item = cur->content;
  free(cur);
  
  return dequeue_item;
}

/* Get the first item in the queue, one that will be dequeued */
Item_ll get_first_item_ll (Queue_ll q) {
  IS_PARAM_NULL(q);
  if (is_empty_ll(q)) {
    terminate("[ERROR] Queue_ll is empty.");
  }

  struct node *temp = q->enqueue_ref;
  Item_ll first_item;

  /* Case when no dequeue has taken place, so the value of q->dequeue_ref will be NULL initially. */
  if (q->dequeue_ref == NULL) {
    while (temp->next != NULL) {
      temp = temp->next;
    }
    first_item = temp->content;
  } else {
    first_item = q->dequeue_ref->content;
  }
  
  return first_item;
}

/* Get the last item in the queue, one that is recently enqueued */
Item_ll get_last_item_ll (Queue_ll q) {
  IS_PARAM_NULL(q);
  if (is_empty_ll(q)) {
    terminate("[ERROR] Queue_ll is empty.");
  }

  return q->enqueue_ref->content;
}

/* Destroy the queue */
void destroy_ll (Queue_ll *q) {
  IS_PARAM_NULL(*q);
  if (is_empty_ll(*q)) {
    return ;
  }
  struct node *temp;
  while ((*q)->enqueue_ref != NULL) {
    temp = (*q)->enqueue_ref;
    (*q)->enqueue_ref = (*q)->enqueue_ref->next;
    free(temp);
  }
  (*q)->dequeue_ref = NULL;
  free(*q);
  *q = NULL;
}
