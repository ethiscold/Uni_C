#ifndef __SINGLY_LINKED_LIST_H__
#define __SINGLY_LINKED_LIST_H__


/* SYSC 2006 Lab 10 */

/* A node in a singly-linked list that stores values of type int. */

typedef struct intnode {
    int    value;
    struct intnode *next;
} intnode_t;


/* Functions presented in lectures. */

intnode_t *push(intnode_t *head, int value);
int length(intnode_t *head);
void print_list(intnode_t *head);

/* Functions that are implemented in this lab. */

int count(intnode_t *head, int target);
int max_value(intnode_t *head);
int value_index(intnode_t *head, int target);
void extend(intnode_t *head, intnode_t *other);
intnode_t *pop(intnode_t *head, int *popped_value);

#endif


