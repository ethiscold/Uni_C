/* SYSC 2006 Lab 10
   A module that implements a singly-linked list of integers. 
 */

#include <assert.h>  // assert
#include <stdlib.h>  // malloc, free
#include <stdbool.h>
#include <stdio.h>   // printf

#include "singly_linked_list.h"

/*************************************************************
 * Functions presented in lectures.
 *************************************************************/

/* Parameter head points to the first node in a linked list, or is NULL
   if the linked list is empty. Insert a node containing the specified 
   integer value at the front of the linked list, and return a pointer to 
   the first node in the modified list.

   Terminate (via assert) if memory for the node cannot be allocated.
 */
intnode_t *push(intnode_t *head, int value)
{
    intnode_t *p = malloc(sizeof(intnode_t));
    assert (p != NULL);
    p->value = value;
    p->next = head;
    return p;
}

/* Parameter head points to the first node in the list.
   Return the length of a linked list (0 if the linked list is empty). 
 */
int length(intnode_t *head)
{
    int count = 0;
    for (intnode_t *curr = head; curr != NULL; curr = curr->next) {
        count += 1;
    }
    return count;
}

/* Parameter head points to the first node in a linked list.
   Print the linked list, using the format:
       value1 -> value2 -> value3 -> ... -> last_value
 */
void print_list(intnode_t *head)
{
    if (head == NULL) {
        printf("empty list");
        return; 
    }

    intnode_t *curr;

    /* The loop prints a every node in the linked list except the last one,
       using the format "value -> ", where "->" represents the link from each node
       to the following node.

       Notice that the loop condition is:
           curr->next != NULL
       and not:
           curr != NULL

       During the last iteration, the value in the second-last node is
       printed, then curr is updated to point to the last node. The
       condition curr->next != NULL now evaluates to false, so the 
       loop exits, with curr pointing to the last node (which has  
       not yet been printed.) 
     */

    for (curr = head; curr->next != NULL; curr = curr->next) {
        printf("%d -> ", curr->value);
    }

    /* Print the last node. */
    printf("%d", curr->value);
}



/*****************************************************************
 * Solutions to New Exercises
 *****************************************************************/

// Exercise 1

/* Parameter head points to the first node in a linked list, or is
 * NULL if the list is empty.
 *
 * Count the number of nodes in the linked list that contain an integer
 * equal to target, and return that count.
 * 
 * Return 0 if the linked list is empty.
 */ 

int count(intnode_t *head, int target)
{
    int counting = 0;
    if (head == NULL) {
        return 0; 
    }

    intnode_t *curr;
    /* Check the nodes in the length of the linked list. */
    for (curr = head; curr->next != NULL; curr = curr->next) {
        if (curr->value == target) counting++;
    }

    /* Check the last node. */
    if (curr->value == target) counting++;
    return counting;
} 

// Exercise 2

/* Parameter head points to the first node in a linked list, or is
 * NULL if the list is empty.
 *
 * Return the largest integer in the linked list.
 *
 * The function terminates (via assert) if the linked list is empty.
 */
int max_value(intnode_t *head)
{
    int max = 0;
     intnode_t *p = malloc(sizeof(intnode_t));
    assert (p != NULL);
    intnode_t *curr;
    /* Check the nodes in the length of the linked list. */
    for (curr = head; curr->next != NULL; curr = curr->next) {
        if (curr->value > max) max = curr->value;
    }
    /* Check the last node. */
    if (curr->value > max) max = curr->value;
    return max;
}


// Exercise 3

/* Parameter head points to the first node in a linked list, or is
 * NULL if the list is empty.
 *
 * Return the index (position) of the first node that contains an 
 * integer equal to target. The first node is at index 0, the second node
 * is at index 1, etc.
 *
 * Return -1 if target is not in the linked list, or if the linked list
 * is empty.
 */
int value_index(intnode_t *head, int target)
{
    int inter = -1;
    intnode_t *curr;
    if (head == NULL) return -1; 
    /* Check the nodes in the length of the linked list. */
    for (curr = head; curr->next != NULL; curr = curr->next) {
        inter++;
        if (curr->value == target) return inter;
    }
    /* Check the last node. */
    if (curr->value == target) return inter;
    return -1;
}


// Exercise 4

/* Parameter head points to the first node in a linked list, or is
 * NULL if the list is empty.
 *
 * Parameter other points to the first node in a linked list, or is
 * NULL if the list is empty.
 *
 * Extend the linked list pointed to by head so that it contains
 * copies of the values stored in the linked list pointed to by other.
 *
 * The function terminates (via assert) if the the linked list 
 * pointed to by head is empty.
 */
void extend(intnode_t *head, intnode_t *other)
{
    if(head == NULL) assert(1);
    while (head -> next != NULL) head = head -> next;
    while(other != NULL){
        head -> next = push(NULL, other -> value);
        head = head -> next;
        other = other -> next;
    }
}

// Exercise 5

/* Parameter head points to the first node in a linked list, or is
 * NULL if the list is empty.
 *
 * The function terminates (via assert) if the linked list is empty.
 *
 * Copy the value in the head node to the location pointed to by
 * parameter popped_value, delete the head node, and return a pointer
 * to the first node in the modified list.
 */
intnode_t *pop(intnode_t *head, int *popped_value)
{
   *popped_value = head->value;
    //intnode_t *curr;
    intnode_t *temp;
    assert(head != NULL);
    temp = head;
    head = head->next;
    free(temp);
    return head;
    // /* Check the nodes in the length of the linked list. */
    // /* for (curr = head; curr != NULL; curr = curr->next) {
    //    */ if (curr != NULL && curr->value == *popped_value) { 
    //         temp = head;
    //         head = curr->next; // Changed head 
    //         free(temp); // free old head 
    //         return head;
    //      } 
    // return head;
}

