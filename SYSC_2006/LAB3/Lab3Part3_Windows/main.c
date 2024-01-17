#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include "recursive_functions.h"


/* Exercise the recursive num_digits() function. 
 * Display the result we expect num_digits() to return, followed by
 * the actual value calculated by the function.
 *
 * Parameter k is the argument that will be passed to num_digits().
 * Parameter expected is the result that a correct implementation of 
 * num_digits() will return.
 */
void test_num_digits(int k, int expected)
{
    printf("Calling num_digits(k) with k = %d\n", k);
    printf("Expected result: %d, ", expected);
    int actual = num_digits(k);
    printf("actual result: %d, ", actual);
    if (expected == actual) {
        printf("pass\n\n");
    } else {
        printf("ERROR!\n\n");
    }
}

void test_exercise_1(void)
{
    printf("*** Exercise `: Testing num_digits ***\n");
    /* Test case: num_digits(5) should return 1. */
    test_num_digits(5, 1);

    /* Test case: num_digits(9) should return 1. */
    test_num_digits(9, 1);

    /* Test case: num_digits(10) should return 2. */
    test_num_digits(10, 2);

    /* Test case: num_digits(99) should return 2. */
    test_num_digits(99, 2);

    /* Test case: num_digits(100) should return 3. */
    test_num_digits(100, 3);

    /* Test case: num_digits(999) should return 3. */
    test_num_digits(999, 3);

    /* Test case: num_digits(1000) should return 4. */
    test_num_digits(1000, 4);
    printf("\n");
}

/* Extra-practice exercises. */

/* Exercise the recursive power2() function.
 * Display the values returned by C's pow() function and our
 * recursive power2() function. If power2() is correct, the two values
 * should be the same, or differ at most by a small amount.
 */
void test_power2(double x, int k)
{
    printf("Calling power2(x, k) with x = %.2f, k = %d\n", x, k);
    double expected = pow(x, k);
    printf("Expected result: %.2f, ", expected);
    double actual = power2(x, k);
    printf("actual result: %.2f, ", actual);
    if (fabs(actual - expected) < 0.001) {
        printf("pass\n\n");
    } else {
        printf("ERROR!\n\n");
    }
}

void test_exercise_2(void)
{
    /* Test cases that allow us to verify if power2() correctly calculates 
     * 3.5 ^ 0, 3.5 ^ 1, 3.5 ^ 2, 3.5 ^ 3 and 3.5 ^ 4.
     */
    printf("*** Exercise 2: Testing power2 ***\n");
    test_power2(3.5, 0);
    test_power2(3.5, 1);
    test_power2(3.5, 2);
    test_power2(3.5, 3);
    test_power2(3.5, 4);
    printf("\n");
}

int main(void)
{
    printf("SYSC 2006 Lab 3, part 3 Test Harness\n\n");

    test_exercise_1();
    
    printf("Testing solutions to the extra-practice exercise.\n\n");

    test_exercise_2();
    return EXIT_SUCCESS;
}
