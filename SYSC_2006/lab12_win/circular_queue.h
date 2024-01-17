#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__
/* SYSC 2006 Lab 12
 *
 * circular_queue.h - circular linked-list implementation of a queue.
 */

/* A queue consists of exactly one instance of the queue_t struct,
 * which points to a linked list containing 0 or more instances of the
 * node_t struct.
 * All instances are allocated from the heap.
 */

/* A node in the queue's linked list. */

typedef struct node
{
    int data;
    struct node *next;
} node_t;

typedef struct
{
    node_t *rear; // Points to the node at the tail of the
                  // queue's linked list
    int size;     // The # of nodes in the queue's linked list
} queue_t;

queue_t *alloc_queue(void);
_Bool queue_is_empty(const queue_t *queue);
int queue_size(const queue_t *queue);
void queue_print(const queue_t *queue);

void enqueue(queue_t *queue, int value);
_Bool dequeue(queue_t *queue, int *element);
_Bool front(const queue_t *queue, int *element);

#endif