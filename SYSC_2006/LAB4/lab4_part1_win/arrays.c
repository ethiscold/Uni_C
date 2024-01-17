/* SYSC 2006 Lab 4. 

 * Incomplete implementations of the functions that will be coded during the lab.
 */

#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "arrays.h"

/* Exercise 1. */

/* Return the average magnitude of the signal represented by
 * the n doubles in x[]. 
 * This function assumes that parameter n is >= 1.
 */
double avg_magnitude(double x[], int n)
{
    double y, z, total;
    for (int i = 0;i<n;i++){
        y = x[i];
        z = fabs(y);
        total = total+z;
    }
    return total/8;
}

/* Exercise 2. */

/* Return the average power of the signal represented by
 * the n doubles in x[].
 * This function assumes that parameter n is >= 1.
 */
double avg_power(double x[], int n)
{
    double y, total;
    for (int i = 0;i<n;i++){
        y = x[i]*x[i];
        total = total+y;
    }
    return total/8;
}

/* Exercise 3. */

/* Return the largest of the n doubles in arr[]. 
 * This function assumes that parameter n is >= 1.
 */
double maxi(double arr[], int n)
{
    double y,total;
    y = arr[0];
    for (int i = 0;i<n;i++){
        if (arr[i] > y){
            y = arr[i];
        }
    }
    return y;
}

/* Exercise 4. */

/* Return the smallest of the n doubles in arr[]. 
 * This function assumes that parameter n is >= 1.
 */
double mini(double arr[], int n)
{
    double y,total;
    y = arr[0];
    for (int i = 0;i<n;i++){
        if (arr[i] < y){
            y = arr[i];
        }
    }
    return y;
}

/* Exercise 5. */

/* Normalize the n doubles in x[]. 
 * This function assumes that parameter n is >= 2, and that at least
 * two of the values in x[] are different.
 */
void normalize(double x[], int n)
{//normalized value of xk = (xk ─ minx) /(maxx ─ minx)
    double y,min,max;
    min = mini(x, n);
    max = maxi(x,n);
    for (int i = 0;i<n;i++){
        y = x[i];
        x[i] = (y - min) / (max - min);
    }
}
