//SYSC 2006 - Lab 2 Solution template

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Include the necessary header for _Bool

/* Replace these lines with your information */ 
  const char* author = "Ethan Robitaille"; 
  const char* student_number = "101233797"; 

// function headers for lab2
int alarm_clock(int,_Bool); 
void count_replace(int); 
_Bool is_prime(int); 
int sumEven(int); 


int main(void)
{
  // Test exercise 1
  int day;
  _Bool vacation;

  day = 0; //day of the week (0=Sun, 1=Mon, ..., 6=Sat)
  vacation = 0; // 0 for No, 1 for Yes 
  
  int alarm_time = alarm_clock(day, vacation);

  if (alarm_time == -1) {
        printf("The alarm is off.\n");
    } else {
        printf("The alarm will ring at %d:00 AM.\n", alarm_time);
    }



// Test exercise 2
count_replace(16);
count_replace(15);

// Test exercise 3
printf("  ");
printf("%d", is_prime(1));
printf("%d", is_prime(2));
printf("%d", is_prime(7));
printf("%d", is_prime(9));


// Test exercise 4
printf("  ");
printf("%d", sumEven(6)); 
printf("%d", sumEven(10));
printf("%d", sumEven(11));  
printf("  ");
printf("All done\n");
return EXIT_SUCCESS;
}

// Type your solution to exercise 1 after this line
int alarm_clock(int day,_Bool vacation) {
  int time = 0;

  if ((day==0 || day==6) && (vacation == 0)){
    time = 10;
  }
  else if ((day>0 && day<6) && (vacation == 0)){
    time = 7;
  }
  else if ((day>0 && day<6) && (vacation == 1)){
    time = 10;
  }
  else if ((day==0 || day==6) && (vacation == 1)){
    time = -1;
  }
  return time;
}

// Type your solution to exercise 2 after this line
void count_replace(int num){
  int i = 1;
  int n;
  char result[100];

  while (i<=num){
    if (((i) % 3 == 0) && ((i) % 5 ==0)){
     printf("FizzBuzz");
    }
    else if ((i) % 3 == 0){
     printf("Fizz");
    }
    else if ((i) % 5==0){
     printf("Buzz");
    }
    else{
     printf("%d",i);
    }
    printf(" ");
    i = i+1;
  } 
}

// Type your solution to exercise 3 after this line
_Bool is_prime(int num){
  int i = 2;
  if (num == 1){
    return false;
  }
  while (i < num){
   if (num % i == 0){
     return false;
   }
   i = i+1;
  }
  return true;
}

// Type your solution to exercise 4 after this line
int sumEven(int num){
  int t;
  for(int j = 0 ; j <= num; j++) {
    if (j % 2 == 0){
      t = t + j;
    }
  }
  return t;
}