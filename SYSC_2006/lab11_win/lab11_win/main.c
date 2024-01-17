/* SYSC 2006 Lab 11 */

/* Test harness to exercise the functions in the sl_list.c module. 
 */

#include <assert.h>             // assert
#include <stdlib.h>             // malloc, free
#include <stdbool.h>
#include <stdio.h>              // printf

#include "sl_list.h"

/* Returns a pointer to the head of a new linked list
   containing 10 nodes:

   1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9
 */
intnode_t *setup(void)
{
    intnode_t *head = NULL;     // start with an empty list
    head = push(head, 9);
    head = push(head, 8);
    head = push(head, 7);
    head = push(head, 6);
    head = push(head, 5);
    head = push(head, 4);
    head = push(head, 3);
    head = push(head, 2);
    head = push(head, 1);
    return head;
}

/* Free all the nodes in the linked list pointed to by head. */
void teardown(intnode_t *head)
{
    intnode_t *current;
    intnode_t *node_to_delete;

    for (current = head; current != NULL;) {
        node_to_delete = current;
        current = current->next;
        free(node_to_delete);
    }
}


/* Tests for Exercise 1. */

void test_add(void)
{
    printf("=== Exercise 1: Testing add ===\n\n");

    intnode_t *head = NULL;    // An empty linked list.

    printf("Calling add with list: ");
    print_list(head);
    printf("\nInserting 10 at index 0.\n");
    head = add(head, 10, 0);
    printf("Expected list after add: 10\n");
    printf("Actual list after add:   ");
    print_list(head);
    printf("\n\n");
    teardown(head);

    /* Build head -> 10 */
    head = intnode_construct(10, NULL);

    printf("Calling add with list: ");
    print_list(head);
    printf("\nInserting 20 value at index 0.\n");
    head = add(head, 20, 0);
    printf("Expected list after add: 20 -> 10\n");
    printf("Actual list after add:   ");
    print_list(head);
    printf("\n\n");
    teardown(head);

    /* Build head -> 20 -> 10 */
    head = intnode_construct(10, NULL);
    head = intnode_construct(20, head);

    printf("Calling add with list: ");
    print_list(head);
    printf("\nInserting 30 at index 1.\n");
    head = add(head, 30, 1);
    printf("Expected list after add: 20 -> 30 -> 10\n");
    printf("Actual list after add:   ");
    print_list(head);
    printf("\n\n");
    teardown(head);

    /* Build head -> 20 -> 30 -> 10 */
    head = intnode_construct(10, NULL);
    head = intnode_construct(30, head);
    head = intnode_construct(20, head);

    printf("Calling add with list: ");
    print_list(head);
    printf("\nInserting 40 at index 3.\n");
    head = add(head, 40, 3);
    printf("Expected list after add: 20 -> 30 -> 10 -> 40\n");
    printf("Actual list after add:   ");
    print_list(head);
    printf("\n\n");
    teardown(head);

    /* Build head -> 20 -> 30 -> 10 -> 40 */
    head = intnode_construct(40, NULL);
    head = intnode_construct(10, head);
    head = intnode_construct(30, head);
    head = intnode_construct(20, head);

    printf("Calling add with list: ");
    print_list(head);
    printf("\nInserting 50 at index 3.\n");
    head = add(head, 50,3);
    printf("Expected list after add: 20 -> 30 -> 10 -> 50 -> 40\n");
    printf("Actual list after add:   ");
    print_list(head);
    printf("\n\n");
    teardown(head);
}

/* Tests for Exercise 2. */

void test_every_other(void)
{
    printf("=== Exercise 2: Testing every_other ===\n\n");

    // Test empty list.
    intnode_t *head = NULL;
    printf("Calling every_other with list: ");
    print_list(head);
    every_other(head);
    printf("\nExpected list after every_other: empty list\n");
    printf("Actual list after every_other:   ");
    print_list(head);
    printf("\n\n");
    teardown(head);

    // Test list with one node.
    head = push(NULL, 1);
    printf("Calling every_other with list: ");
    print_list(head);
    every_other(head);
    printf("\nExpected list after every_other: 1\n");
    printf("Actual list after every_other:   ");
    print_list(head);
    printf("\n\n");
    teardown(head);

    // Test list with two nodes.
    head = push(NULL, 2);
    head = push(head, 1);
    printf("Calling every_other with list: ");
    print_list(head);
    every_other(head);
    printf("\nExpected list after every_other: 1\n");
    printf("Actual list after every_other:   ");
    print_list(head);
    printf("\n\n");
    teardown(head);

    // Test list with an odd number of nodes.
    head = setup();             // head points to a list with 9 nodes
    printf("Calling every_other with list: ");
    print_list(head);
    every_other(head);
    printf("\nExpected list after every_other: 1 -> 3 -> 5 -> 7 -> 9\n");
    printf("Actual list after every_other:   ");
    print_list(head);
    printf("\n\n");
    teardown(head);

    // Test list with an even number of nodes.
    head = setup();
    head = push(head, 0);       // Now the list has 10 nodes
    printf("Calling every_other with list: ");
    print_list(head);
    every_other(head);
    printf("\nExpected list after every_other: 0 -> 2 -> 4 -> 6 -> 8\n");
    printf("Actual list after every_other:   ");
    print_list(head);
    printf("\n\n");
    teardown(head);
}

/* Exercise the recursive count_in_sll function. 
 * Display the result we expect count_in_sll() to return, followed by
 * the actual value calculated by the function.
 *
 * Parameter head is the list that will be passed to count_in_sll().
 * Parameter target is the value that count_in_sll() will search for.
 * Parameter expected is the result that a correct implementation of 
 * count_in_sll() will return.
 */
void test_count_in_sll(intnode_t *head, int target, int expected)
{
    printf("Calling count_in_sll with list = ");
    print_list(head);
    printf(", target = %d\n", target);
    printf("Expected result: %d, ", expected);
    int actual = count_in_sll(head, target);
    printf("actual result: %d, ", actual);
    if (expected == actual) {
        printf("pass\n\n");
    } else {
        printf("ERROR!\n\n");
    }
}

void test_exercise_3(void)
{
    printf("*** Exercise 3: Testing count_in_sll ***\n");

    // Build the linked list {1, 3, 3, 4, 4, 5, 4, 6}
    intnode_t *list = push(NULL, 6);
    list = push(list, 4);
    list = push(list, 5);
    list = push(list, 4);
    list = push(list, 4);
    list = push(list, 3);
    list = push(list, 3);
    list = push(list, 1);

    /* Test case: count_in_sll(list, 1) should return 1. */
    test_count_in_sll(list, 1, 1);

    /* Test case: count_in_sll(list, 2) should return 0. */
    test_count_in_sll(list, 2, 0);

    /* Test case: count_in_sll(list, 3) should return 2. */
    test_count_in_sll(list, 3, 2);

    /* Test case: count_in_sll(list, 4) should return 3. */
    test_count_in_sll(list, 4, 3);

    /* Test case: count_in_sll(list, 5) should return 1. */
    test_count_in_sll(list, 5, 1);

    /* Test case: count_in_sll(list, 6) should return 1. */
    test_count_in_sll(list, 6, 1);
    printf("\n");
}

/* Exercise the recursive last_in_sll function. 
 * Display the result we expect last_in_sll() to return, followed by
 * the actual value calculated by the function.
 *
 * Parameter head is the list that will be passed to last_in_sll().
 * Parameter expected is the result that a correct implementation of 
 * last_in_sll() will return.
 */
void test_last_in_sll(intnode_t *head, int expected)
{
    printf("Calling last_in_sll with list = ");
    print_list(head);
    printf("\nExpected result: %d, ", expected);
    int actual = last_in_sll(head);
    printf("actual result: %d, ", actual);
    if (expected == actual) {
        printf("pass\n\n");
    } else {
        printf("ERROR!\n\n");
    }
}

void test_exercise_4(void)
{
    printf("*** Exercise 4: Testing last_in_sll ***\n");

    // Build the linked list {1}
    intnode_t *list = push(NULL, 1);

    /* Test case: last_in_sll(list) should return 1. */
    test_last_in_sll(list, 1);

    // Build the linked list {1, 2}
    list = push(push(NULL, 2), 1);

    /* Test case: last_in_sll(list) should return 2. */
    test_last_in_sll(list, 2);

    // Build the linked list {1, 2, 4, 4}
    list = push(push(push(push(NULL, 4), 4), 2), 1);

    /* Test case: last_in_sll(list) should return 4. */
    test_last_in_sll(list, 4);

    // Build the linked list {1, 2, 4, 4, 5}
    list = push(push(push(push(push(NULL, 5), 4), 4), 2), 1);

    /* Test case: last_in_sll(list) should return 5. */
    test_last_in_sll(list, 5);

    printf("\n");
}

int main(void)
{
    printf("Running test harness for SYSC 2006 Lab 11\n\n");

    test_add();
    test_every_other();
    test_exercise_3();
    test_exercise_4();
}
