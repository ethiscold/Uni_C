/* SYSC 2006 Lab 8
 *
 * array_list.c 
 *
 * A dynamically allocated, fixed-capacity list collection that supports a subset of the 
 * operations provided by Python's list type.
 */ 

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "array_list.h"

/* Construct a new, empty list, and return a pointer to it
 * Parameter capacity is the # of elements that can be stored in the list.
 *
 * Terminate the program via assert if capacity is <= 0.
 * Terminate the program via assert if memory for the list cannot be 
 * allocated from the heap.
 */
list_t *list_construct(int capacity) {   
    //check if capacity > 0
    assert(capacity > 0);
    //alocate space for list
    list_t *list = NULL;
    list = malloc(sizeof(list_t));
    //check if list != NULL
    assert(list != NULL);
    //initialize list elements
    list->elems = malloc(capacity * sizeof(int)); //alocate space for backing array
    list->capacity = capacity;
    list->size = 0;
    //check if elems != NULL
    assert(list->elems != NULL);

    return list;
}

/* Destroy the list pointed to by parameter list, deallocating all memory 
 * that was allocated from the heap.
 *
 * Terminate the program via assert if list is NULL.
 */
void list_destroy(list_t *list)
{
    assert(list != NULL);
    free(list->elems);  /* Return the array to the heap. */
    free(list);         /* Return the structure to the heap. */
}

/* Print the list pointed to by parameter list on the console.
 *
 * Terminate the program via assert if list is NULL.
 * Terminate the program via assert if the pointer to the list's backing array is NULL.
 * Terminate the program via assert if the list's capacity and size are invalid.
 */
void list_print(const list_t *list)
{    
    assert(list != NULL);
    assert(list->elems != NULL);
    assert(list->capacity > 0 && list->size >= 0 && list->size <= list->capacity);

	printf("[");
    int n = list->size;
    if (n > 0) {
        /* Print all the array elements, with a leading space before
         * all but the first element. 
         */
	    printf("%d", list->elems[0]);

        for (int i = 1; i < n; i += 1) {
	        printf(" %d", list->elems[i]);
	    }
	}
	printf("]");
    printf(", capacity: %d, size: %d\n", list->capacity, list->size);
}

/* Insert element at the end of the list pointed to by list.
 * Return true if element is appended; otherwise return false
 * (which indicates that the list is full.)
 *
 * Terminate the program via assert if list is NULL.
 */
_Bool list_append(list_t *list, int element) {
    //check if list != NULL
    assert(list != NULL);
    if (list->size < list->capacity) { //check for room in list
        list->elems[list->size] = element; //add element in the next availabe position
        list->size++; //increment size
        return true;
    }
    return false;
}

/* Return the maximum number of integers that can be stored in the list 
 * pointed to by parameter list.
 *
 * Terminate the program via assert if list is NULL.
 */
int list_capacity(const list_t *list) {
    assert(list != NULL);
    return list->capacity;
}

/* Return the number of integers in the list pointed to by parameter list.
 *
 * Terminate the program via assert if list is NULL.
 */
int list_size(const list_t *list) {
    assert(list != NULL);
    return list->size;
}

/* Return the element located at the specified index, in the list
 * pointed to by parameter list.
 *
 * Terminate the program via assert if list is NULL, 
 * or if index is not in the range 0 .. list_size() - 1.
 */
int list_get(const list_t *list, int index) {
    assert(list != NULL);
    return list->elems[index];
}

/* Store element at the specified index, in the list pointed to by 
 * parameter list. Return the integer that was previously 
 * stored at that index.
 *
 * Terminate the program via assert if list is NULL, 
 * or if index is not in the range 0 .. list_size() - 1.
 */
int list_set(list_t *list, int index, int element) {
    assert(list != NULL);
    int previous_elem = list->elems[index];
    list->elems[index] = element;
    return previous_elem;
}

/* Empty the list pointed to by parameter list.
 * Memory allocated to the list is not freed, so the emptied list can 
 * continue to be used.
 *
 * Terminate the program via assert if list is NULL.
 */
void list_removeall(list_t *list) {
    assert(list != NULL);
    list->size = 0;
}

/* Return the index (position) of the first occurrence of an integer
 * equal to target in the list pointed to by parameter list. 
 * Return -1 if target is not in the list.
 *
 * Terminate the program via assert if list is NULL.
 */
int list_index(const list_t *list, int target) {
    assert(list != NULL);
    for (int i = 0; i < list->capacity; i++) {
        if (list->elems[i] == target) {//compare current value to target
            return i; //return index of current value
        } 
    }
    return -1;
}

/* Count the number of integers that are equal to target, in the list 
 * pointed to by parameter list, and return that number.
 *
 * Terminate the program via assert if list is NULL.
 */
int list_count(const list_t *list, int target) {
    assert(list != NULL);
    int count = 0;
    for (int i = 0; i < list->capacity; i++) {
        if (list->elems[i] == target) {
            count++;
        }
    }
    return count;
}

/* Determine if an integer in the list pointed to by parameter list 
 * is equal to target.
 * Return true if target is in the list, otherwise return false.
 *
 * Terminate the program via assert if list is NULL.
 */
_Bool list_contains(const list_t *list, int target) {
    assert(list != NULL);
    return list_index(list, target) != -1 ? true : false;
}
