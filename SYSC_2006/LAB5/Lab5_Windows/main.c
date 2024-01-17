/* main.c - SYSC 2006 Lab 5 
 *
 * Do not modify any of the code in this file.
 */

#include <stdlib.h>  // 
#include <stdio.h>   // 
#include"array_pointers.h"

void print_array(int a[], int n);

// Exercise 2
void test_exercise_2(void);
void test_count_in_array(int a[], int n, int target, int expected);

// Exercise 3
void test_exercise_3(void);
void test_array_compare(int arr1[],int arr2[], int n, _Bool expected);


int main(void)
{
    // Exercise  1

	// We start by finding the maximum element in the first "n" elements of an array three different ways.
	int anArray[] = {7,2,-5,100,3};

	// test find_max_v0
	printf("find_max_v0: The largest element in the first 5 elements of anArray is: %d\n",find_max_v0(anArray,5));
	printf("find_max_v0: The largest element in the first 3 elements of anArray is: %d\n",find_max_v0(anArray,3));
	printf("find_max_v0: The largest element in the first -2 elements of anArray is: %d\n\n",find_max_v0(anArray,-2));

	// test find_max_v1 (You have to complete this function)
	printf("find_max_v1: The largest element in the first 5 elements of anArray is: %d\n",find_max_v1(&anArray[0],5));
	printf("find_max_v1: The largest element in the first 3 elements of anArray is: %d\n",find_max_v1(&anArray[0],3));
	printf("find_max_v1: The largest element in the first -2 elements of anArray is: %d\n\n",find_max_v1(&anArray[0],-2));

	// test find_max_v2 (You have to complete this function)
	printf("find_max_v2: The largest element in the first 5 elements of anArray is: %d\n",find_max_v2(&anArray[0],5));
	printf("find_max_v2: The largest element in the first 3 elements of anArray is: %d\n",find_max_v2(&anArray[0],3));
	printf("find_max_v2: The largest element in the first -2 elements of anArray is: %d\n\n",find_max_v2(&anArray[0],-2));
    
    //Exercise 2
    test_exercise_2();

    //Exercise 3    
    test_exercise_3();
}

// Exercise  2
/* Exercise the recursive count_in_array function. 
 * Display the result we expect count_in_array() to return, followed by
 * the actual value calculated by the function.
 *
 * Parameter a is the array that will be passed to count_in_array().
 * Parameter n is the number of elements in the array.
 * Parameter target is the value that count_in_array() will search for.
 * Parameter expected is the result that a correct implementation of 
 * count_in_array() will return.
 */
void test_count_in_array(int a[], int n, int target, int expected)
{
    printf("Calling count_in_array with a = ");
    print_array(a, n);
    printf(", n = %d, target = %d\n", n, target);
    printf("Expected result: %d, ", expected);
    int actual = count_in_array(a, n, target);
    printf("actual result: %d, ", actual);
    if (expected == actual) {
        printf("pass\n\n");
    } else {
        printf("ERROR!\n\n");
    }
}

void test_exercise_2(void)
{
    printf("*** Exercise 2: Testing count_in_array ***\n");
    int x[] = { 1, 3, 3, 4, 4, 5, 4, 6 };
    int n = sizeof(x) / sizeof(n);

    /* Test case: count_in_array(x, n, 1) should return 1. */
    test_count_in_array(x, n, 1, 1);

    /* Test case: count_in_array(x, n, 2) should return 0. */
    test_count_in_array(x, n, 2, 0);

    /* Test case: count_in_array(x, n, 3) should return 2. */
    test_count_in_array(x, n, 3, 2);

    /* Test case: count_in_array(x, n, 4) should return 3. */
    test_count_in_array(x, n, 4, 3);

    /* Test case: count_in_array(x, n, 5) should return 1. */
    test_count_in_array(x, n, 5, 1);

    /* Test case: count_in_array(x, n, 6) should return 1. */
    test_count_in_array(x, n, 6, 1);
    printf("\n");
}

// Exercise 3
void test_array_compare(int arr1[],int arr2[], int n, _Bool expected)
{
    printf("Calling array_compare with arr1 = ");
    print_array(arr1, n);
    printf("\n");

    printf("Calling array_compare with arr2 = ");
    print_array(arr2, n);
    printf("\n");

    printf(", n = %d \n", n);
    printf("Expected result: %d, ", expected);
    int actual = array_compare(arr1,arr2,n);
    printf("actual result: %d, ", actual);
    if (expected == actual) {
        printf("pass\n\n");
    } else {
        printf("ERROR!\n\n");
    }
}

void test_exercise_3(void)
{
    printf("*** Exercise 3: Testing array_compare ***\n");
    int arr1[] = {1, 2, 3, 4, 5};
    int arr2[] = {1, 2, 3, 4, 5};
    int arr3[] = {1, 2, 3, 4, 6};
    int arr4[] = {1, 2, 3, 4};
    int arr5[] = {1, 2, 3, 4, 5, 6};
   
    // Test case: array_compare(arr1, arr2, 5) should return 1.
    test_array_compare(arr1, arr2, 5,1);

    // Test case: array_compare(arr1, arr3, 5) should return 0. 
    test_array_compare(arr1, arr3, 5, 0);

    // Test case: array_compare(arr1, arr3, 4) should return 1. 
    test_array_compare(arr1, arr3, 4, 1);

    // Test case: array_compare(arr1, arr4, 4) should return 1.
    test_array_compare(arr1, arr4, 4,1);

    // Test case: array_compare(arr1, arr5, 4) should return 1. 
    test_array_compare(arr1, arr5, 4, 1);



    printf("\n");
}


/*
 * Print then integers in array a in the form: {a[0] a[1] .. a[n-1]}.
 */
void print_array(int a[], int n)
{
    if (n < 0) {
        return;
    }

    if (n == 0) {
        printf("{}");
        return;
    }

    printf("{%d", a[0]);
    for (int i = 1; i < n; i += 1) {
        printf(" %d", a[i]);
    }
    printf("}");
}
