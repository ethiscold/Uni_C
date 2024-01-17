/* fraction.c - SYSC 2006 Lab 6 */

#include <stdlib.h>  // abs(x)
#include <stdio.h>   // printf

#include "fraction.h"

/* Print fraction f in the form a/b. */
void print_fraction(fraction_t f)
{
    printf("%d/%d", f.num, f.den);
}

/* Return the greatest common divisor of integers a and b; 
   i.e., return the largest positive integer that evenly divides 
   both values.
*/
int gcd(int a, int b)
{
	/* Euclid's algorithm, using iteration and calculation of remainders. */
    int q = abs(a);
    int p = abs(b);
    int r = q % p;

    while(r != 0){
        q = p;
        p = r;
        r = q % p;
    }
	return p;
}

/* Return the reduced form of fraction f.

   This means that:
   (1) if the numerator is equal to 0 the denominator is always 1.
   (2) if the numerator is not equal to 0 the denominator is always
       positive, and the numerator and denominator have no common
       divisors other than 1.

   In other words,
   (1) if the numerator is 0 the denominator is always changed to 1.
   (2) if the numerator and denominator are both negative, both values
       are made positive, or if the numerator is positive and the 
       denominator is negative, the numerator is made negative and the 
       denominator is made positive.
   (3) the numerator and denominator are both divided by their greatest
       common divisor. 
*/
fraction_t reduce(fraction_t f)
{ 
    if (f.num == 0){
        f.den = 1;
        return f;
    }
	else{
        int div = gcd(f.num, f.den);
        f.num /= div;
        f.den /= div;

        if ((f.den < 0 && f.num > 0) || (f.den < 0 && f.num < 0)){
             f.den *= -1;
             f.num *= -1;
        }
    }
    return f;
}

/* Return a fraction with numerator a and denominator b.
   Print an error message and terminate the calling program via exit()
   if the denominator is 0.
   The fraction returned by this function is always in reduced form
   (see documentation for reduce).
*/
fraction_t make_fraction(int a, int b)
{
	fraction_t f = {a, b};
    f = reduce(f);
    return f;
}

/* Return the sum of fractions f1 and f2.
   The fraction returned by this function is always in reduced form
   (see documentation for reduce).
 */
fraction_t add_fractions(fraction_t f1, fraction_t f2)
{
    /*
    sum = 3/
    */
    fraction_t sum;

    if(f1.den != f2.den){
        sum.num = (f1.num * f2.den) + (f2.num * f1.den);
        sum.den = f1.den * f2.den;
    }
    else{
        sum.num = sum.num = f1.num + f2.num;
        sum.den = f1.den;   
    }
    sum = reduce(sum);
	return sum ;
}

/* Return the product of fractions f1 and f2.
   The fraction returned by this function is always in reduced form
   (see documentation for reduce).
 */
fraction_t multiply_fractions(fraction_t f1, fraction_t f2)
{
    fraction_t product;
    product.num = f1.num * f2.num;
    product.den = f1.den * f2.den;
	return make_fraction(product.num, product.den);
}
