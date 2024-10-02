#ifndef QUEUE_1_H
#define QUEUE_1_H

#include <stdbool.h>      /* C99 Only */

typedef int Item;

typedef struct queue_type *Queue;

Queue create          (int size);           /* Create a queue */
void  enqueue         (Queue q, Item i);    /* To add item in the queue (at the end) */
Item  dequeue         (Queue q);            /* To remove item in the queue (from the beginning) */
Item  get_first_item  (Queue q);            /* Get the first item in the queue, one that will be dequeued */
Item  get_last_item   (Queue q);            /* Get the last item in the queue, one that is recently enqueued */
bool  is_empty        (Queue q);            /* Check if the queue is empty */
bool  is_full         (Queue q);            /* Check if the queue is full */
void  destroy         (Queue *q);           /* Destroy the queue */

#endif 
