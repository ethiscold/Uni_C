#include<stdio.h>
#include<stdlib.h>
#include "lab4test.h"

int variable1;
int main(void){
    variable1 = 0;
    int i = 100;
    for (int i = 0; i < 8; i++){
        printf("The value of variable1 is: %d\n", variable1);
        variable1++;
    }

    i = test1(variable1);

    return EXIT_SUCCESS;
}

// What is the scope of variable1 defined inside main.c?
//  Line 7 to line 14
// 
// Are any of the variables variable1 defined inside lab4test.c the same as the variable defined inside main.c?
//  Yes in test1 the varables are the same
//
// Does the assignment statement inside lab4test.c (line 7) modify the content of variable1 inside main.c?
//  NO
//
// How many distinct variables i there are in main.c? If more than one, what is the scope of each of them?
//  2 the first is declared as 100 in the initialization and the other is equal to the last assigned # to variable 1 multiplied by 6
//
// How many distinct variables variable1 there are in main.c? If more than one, what is the scope\of each of them?
//  There is 8 of them, and the scope of the first is from 5 to 11, the next 6 are 10 to 11 and the last is from 10 to 14
//
// In lab4test.c, is the variable1 inside test2 the same as the variable inside test1?
//  No 
//