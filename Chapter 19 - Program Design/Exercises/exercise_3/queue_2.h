#ifndef QUEUE_2_H
#define QUEUE_2_H

#include <stdbool.h>      /* C99 Only */

typedef int Item_ll;

typedef struct queue_type_ll *Queue_ll;

Queue_ll  create_ll             (void);                     /* Create a queue */
void      enqueue_ll            (Queue_ll q, Item_ll i);    /* To add item in the queue (at the end) */
Item_ll   dequeue_ll            (Queue_ll q);               /* To remove item in the queue (from the beginning) */
Item_ll   get_first_item_ll     (Queue_ll q);               /* Get the first item in the queue, one that will be dequeued */
Item_ll   get_last_item_ll      (Queue_ll q);               /* Get the last item in the queue, one that is recently enqueued */
bool      is_empty_ll           (Queue_ll q);               /* Check if the queue is empty */
bool      is_full_ll            (Queue_ll q);               /* Check if the queue is full */
void      destroy_ll            (Queue_ll *q);              /* Destroy the queue */

#endif 

