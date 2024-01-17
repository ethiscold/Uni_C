/* SYSC 2006 Lab 10 Test Harness */

/* Test harness to exercise the functions in the singly_linked_list.c module.
 */

#include <assert.h>  // assert
#include <stdlib.h>  // malloc, free
#include <stdbool.h>
#include <stdio.h>   // printf

#include "singly_linked_list.h"

/* Returns a pointer to the head of the new linked list:
   1 -> 1 -> 2 -> 3 -> 3 -> 4 -> 5 -> 5 -> 5
 */
intnode_t *setup(void)
{
    intnode_t *head = NULL;  // start with an empty list
    head = push(head, 5);
    head = push(head, 5);
    head = push(head, 5);
    head = push(head, 4);
    head = push(head, 3);
    head = push(head, 3);
    head = push(head, 2);
    head = push(head, 1);
    head = push(head, 1);
    return head;
}

/* Returns a pointer to the head of the new linked list:
   5 -> 5 -> 5 -> 4 -> 3 -> 3 -> 2 -> 1 -> 1
 */
intnode_t *setup2(void)
{
    intnode_t *head = NULL;  // start with an empty list
    head = push(head, 1);
    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 3);
    head = push(head, 3);
    head = push(head, 4);
    head = push(head, 5);
    head = push(head, 5);
    head = push(head, 5);
    return head;
}

/* Returns a pointer to the head of the new linked list:
   1 -> 2 -> 3 -> 4 -> 5 -> 4 -> 3 -> 2 -> 1
 */
intnode_t *setup3(void)
{
    intnode_t *head = NULL;  // start with an empty list
    head = push(head, 1);
    head = push(head, 2);
    head = push(head, 3);
    head = push(head, 4);
    head = push(head, 5);
    head = push(head, 4);
    head = push(head, 3);
    head = push(head, 2);
    head = push(head, 1);
    return head;
}

/* Free all the nodes in the linked list pointed to by head.
 */
void teardown(intnode_t *head)
{
    intnode_t *node_to_delete;

    while (head != NULL) {
        node_to_delete = head;
        head = head->next;
        free(node_to_delete);
    }
}


/* Tests for Exercise 1. */
void test_count(void)
{
    printf("=== Exercise 1: Testing count ===\n\n");

    int occurrences;
    intnode_t *empty = NULL; // Empty list

    printf("Calling count with list: ");   // Test 1
    print_list(empty);
    printf("\nCounting 1's.\n");
    occurrences = count(empty, 1);
    printf("Expected result: 0\n");
    printf("Actual result: %d\n\n", occurrences);

    printf("Calling count with list: ");  // Test 2
    print_list(empty);
    printf("\nCounting 7's.\n");
    occurrences = count(empty, 7);
    printf("Expected result: 0\n");
    printf("Actual result: %d\n\n", occurrences);

    intnode_t *head = setup();

    printf("Calling count with list: ");  // Test 3
    print_list(head);
    printf("\nCounting 1's.\n");
    occurrences = count(head, 1);
    printf("Expected result: 2\n");
    printf("Actual result: %d\n\n", occurrences);

    printf("Calling count with list: ");  // Test 4
    print_list(head);
    printf("\nCounting 2's.\n");
    occurrences = count(head, 2);
    printf("Expected result: 1\n");
    printf("Actual result: %d\n\n", occurrences);

    printf("Calling count with list: ");  // Test 5
    print_list(head);
    printf("\nCounting 3's.\n");
    occurrences = count(head, 3);
    printf("Expected result: 2\n");
    printf("Actual result: %d\n\n", occurrences);

    printf("Calling count with list: ");  // Test 6
    print_list(head);
    printf("\nCounting 4's.\n");
    occurrences = count(head, 4);
    printf("Expected result: 1\n");
    printf("Actual result: %d\n\n", occurrences);

    printf("Calling count with list: ");   // Test 7
    print_list(head);
    printf("\nCounting 5's.\n");
    occurrences = count(head, 5);
    printf("Expected result: 3\n");
    printf("Actual result: %d\n\n", occurrences);

    printf("Calling count with list: ");   // Test 8
    print_list(head);
    printf("\nCounting 7's.\n");
    occurrences = count(head, 7);
    printf("Expected result: 0\n");
    printf("Actual result: %d\n\n", occurrences);

    teardown(head);
}

/* Tests for Exercise 2. */
void test_max_value(void)
{
    printf("=== Exercise 2: Testing max ===\n\n");
    int largest;

    /* We can't test the empty-list case, because it should cause max to
     * terminate via assert.
     */

    intnode_t *head = setup();  // Test 9
    printf("Calling max with list: ");
    print_list(head);
    largest = max_value(head);
    printf("\n");
    printf("Expected result: 5\n");
    printf("Actual result: %d\n\n", largest);
    teardown(head);

    head = setup2();   // Test 10
    printf("Calling max with list: ");
    print_list(head);
    largest = max_value(head);
    printf("\n");
    printf("Expected result: 5\n");
    printf("Actual result: %d\n\n", largest);
    teardown(head);

    head = setup3();  // Test 11
    printf("Calling max with list: ");
    print_list(head);
    largest = max_value(head);
    printf("\n");
    printf("Expected result: 5\n");
    printf("Actual result: %d\n\n", largest);
    teardown(head);
}

/* Tests for Exercise 3. */
void test_value_index(void)
{
    printf("=== Exercise 3: Testing index ===\n\n");

    int posn;
    intnode_t *empty = NULL; // Empty list

    printf("Calling index with list: ");  // Test 12
    print_list(empty);
    printf("\nSearching for 1.\n");
    posn = value_index(empty, 1);
    printf("Expected result: -1\n");
    printf("Actual result: %d\n\n", posn);

    intnode_t *head = setup();

    printf("Calling index with list: ");  // Test 13
    print_list(head);
    printf("\nSearching for 1.\n");
    posn = value_index(head, 1);
    printf("Expected result: 0\n");
    printf("Actual result: %d\n\n", posn);

    printf("Calling index with list: ");  // Test 14
    print_list(head);
    printf("\nSearching for 2.\n");
    posn = value_index(head, 2);
    printf("Expected result: 2\n");
    printf("Actual result: %d\n\n", posn);

    printf("Calling index with list: ");  // Test 15
    print_list(head);
    printf("\nSearching for 3.\n");
    posn = value_index(head, 3);
    printf("Expected result: 3\n");
    printf("Actual result: %d\n\n", posn);

    printf("Calling index with list: ");  // Test 16
    print_list(head);
    printf("\nSearching for 4.\n");
    posn = value_index(head, 4);
    printf("Expected result: 5\n");
    printf("Actual result: %d\n\n", posn);

    printf("Calling index with list: ");  // Test 17
    print_list(head);
    printf("\nSearching for 5.\n");
    posn = value_index(head, 5);
    printf("Expected result: 6\n");
    printf("Actual result: %d\n\n", posn);

    printf("Calling index with list: ");  // Test 18
    print_list(head);
    printf("\nSearching for 7.\n");
    posn = value_index(head, 7);
    printf("Expected result: -1\n");
    printf("Actual result: %d\n\n", posn);

    teardown(head);
}


/* Tests for Exercise 4. */
void test_extend(void)
{
    printf("=== Exercise 4: Testing extend ===\n\n");

    /* Build 1 -> 2 -> 3 -> 4 */  // Test 19
    intnode_t *first = NULL;
    first = push(first, 4);
    first = push(first, 3);
    first = push(first, 2);
    first = push(first, 1);

    intnode_t* second = NULL;

    printf("Calling extend with list: ");
    print_list(first);
    printf("\nother list: ");
    print_list(second);
    printf("\n");
    extend(first, second);
    printf("Expected list after extend: 1 -> 2 -> 3 -> 4\n");
    printf("Actual list after extend:   ");
    print_list(first);
    printf("\n\n");

    teardown(first);

    /* Build 1 -> 2 -> 3 -> 4 */  // Test 20
    first = NULL;
    first = push(first, 4);
    first = push(first, 3);
    first = push(first, 2);
    first = push(first, 1);

    /* Build 5 -> 6 -> 7 -> 8 */
    second = push(second, 8);
    second = push(second, 7);
    second = push(second, 6);
    second = push(second, 5);

    printf("Calling extend with list: ");
    print_list(first);
    printf("\nother list: ");
    print_list(second);
    printf("\n");
    extend(first, second);
    printf("Expected list after extend: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8\n");
    printf("Actual list after extend:   ");
    print_list(first);
    printf("\n\n");

    teardown(first);
    teardown(second);
}

/* Tests for Exercise 5. */
void test_pop(void)
{
    printf("=== Exercise 5: Testing pop ===\n\n");

    /* We can't test the empty-list case, because it should cause pop to
     * terminate via assert.
     */

    int popped;

    intnode_t *head = setup();

    printf("Calling pop with list: ");  // Test 21
    print_list(head);
    printf("\n");
    head = pop(head, &popped);
    printf("Expected popped value: 1\n");
    printf("Actual popped value: %d\n", popped);
    printf("Expected list after pop: 1 -> 2 -> 3 -> 3 -> 4 -> 5 -> 5 -> 5\n");
    printf("Actual list after pop:   ");
    print_list(head); 
    printf("\n\n");

    teardown(head);
    head = setup();

    printf("Calling pop twice with list: ");  // Test 22
    print_list(head);
    printf("\n");
    head = pop(head, &popped);
    head = pop(head, &popped);
    printf("Expected second popped value: 1\n");
    printf("Actual second popped value: %d\n", popped);
    printf("Expected list after pop: 2 -> 3 -> 3 -> 4 -> 5 -> 5 -> 5\n");
    printf("Actual list after pop:   ");
    print_list(head);
    printf("\n\n");

    teardown(head);
    head = setup();

    printf("Calling pop 8 times (results not shown)\n\n");  // Test 23
    for (int i = 0; i < 8; i += 1) {
        head = pop(head, &popped);
    }

    printf("Calling pop with list: ");
    print_list(head);
    printf("\n");
    head = pop(head, &popped);
    printf("Expected popped value: 5\n");
    printf("Actual popped value: %d\n", popped);
    printf("Expected list after pop: empty list\n");
    printf("Actual list after pop:   ");
    print_list(head);
    printf("\n");

    teardown(head);
}

int main(void)
{
    printf("Running test harness for SYSC 2006 Lab 10\n\n");

    test_count();
    test_max_value();
    test_value_index();
    test_extend();
    test_pop();
}
