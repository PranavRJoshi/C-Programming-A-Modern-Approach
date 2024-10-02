// Q. A queue is similar to a stack, except that items are added at one end but removed from the other in a FIFO (first-in, first-out) fashion. Operations on a queue might include:
//    Inserting an item at the end of the queue.
//    Removing an item from the beginning of the queue.
//    Returning the first item in the queue (without changing the queue).
//    Returning the last item in the queue (without changing the queue).
//    Testing whether the queue is empty.
// Write an interface for a queue module in the form of a header file named queue.h.

#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>      /* C99 Only */

typedef int Item;

//  Here, we are assuming to use a queue of fixed size. So, the struct queue_type will have the following members:
//    struct queue_type {
//      Item content[100];    /* Consider a queue of 100 items */
//      int current_items;    /* Current number of Items in queue */
//    }
//  We can change it as we wish, using dynamic storage (using Item *content), or linked list (similar to stack).
//  Using dynamic storage as well, we can use the concept of current_items to keep track of the size of the queue.
//  If we plan to use Linked list, we need to check the last node (which needs to be dequeued) and the first node (recently enqueued)
typedef struct queue_type *Queue;

Queue create          (void);               /* Create a queue */
void  enqueue         (Queue q, Item i);    /* To add item in the queue (at the end) */
Item  dequeue         (Queue q);            /* To remove item in the queue (from the beginning) */
Item  get_first_item  (Queue q);            /* Get the first item in the queue, one that will be dequeued */
Item  get_last_item   (Queue q);            /* Get the last item in the queue, one that is recently enqueued */
bool  is_empty        (Queue q);            /* Check if the queue is empty */
void  destroy         (Queue q);            /* Destroy the queue */

#endif 
