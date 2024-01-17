/********* a1_data_structures.c	 ********
	
	Student Name 	= Ethan Robitaille
	Student Number	= 101233797
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "a1_functions.h"


void number_of_employees(milestone_t *project_details){
	float temp;
	float time, cost;
	time = project_details->time; 
	cost = project_details->cost;
	temp =  cost / (time*40*25); //𝑆𝑎𝑙𝑎𝑟𝑦𝑓𝑢𝑙𝑙𝑡𝑖𝑚𝑒 𝑒𝑚𝑝𝑙𝑜𝑦𝑒𝑒 = 𝐷𝑢𝑟𝑎𝑡𝑖𝑜𝑛𝑤𝑒𝑒𝑘𝑠 × 𝐻𝑜𝑢𝑟𝑠 𝑝𝑒𝑟 𝑊𝑒𝑒𝑘 × 𝑆𝑎𝑙𝑎𝑟𝑦 𝑝𝑒𝑟 𝐻𝑜𝑢𝑟
	temp = round(temp);
	project_details -> num_employees = temp;
}

milestone_t init_milestone(char stage_name[], float assigned_budget){
	milestone_t mile;
  	{strcpy(mile.name, stage_name);
  	mile.cost = assigned_budget;
  	mile.time = 0.00;
  	mile.num_employees = 0;
  	mile.completed =0;};
  	return mile;
}

unsigned short int get_input_usi(void){
	int tempi;
	scanf("%d", &tempi);
	while (tempi < 0){
		printf("The value you entered is invalid. \n");
		printf("Please input a Positive number: ");
		scanf("%d", &tempi);
		}
	return tempi;
}

float get_input_f(void){
	float cost;
	scanf("%f", &cost);
	while (cost < 0){
		printf("The value you entered is invalid. \n");
		printf("Please input a Positive number: ");
		scanf("%f", &cost);
	}
	return cost;
}

void print_menu(void){
	printf("Which Milestone would you like to edit? Enter 0 to exit. \n");
	printf("1. Technical requirements \n");
	printf("2. System design \n");
	printf("3. Software development \n");
	printf("4. Testing \n");
	printf("5. Product release \n");
}


void print_stats(milestone_t details){
	printf("\n");
	// display the stats per milestone
	printf("-----------------Milestone stats----------------- \n");
	printf("Below is the status of the %s: \n", details.name);
	printf("------------------------------------------------- \n");
	printf("\n");
	printf("Actual time:  %0.2f weeks \n", details.time);
	printf("Actual number of employees:  %d \n", details.num_employees);
	printf("Actual cost:  %0.2f$ \n", details.cost);
	if (details.completed == 0) printf("Completed: No \n");
	if (details.completed == 1) printf("Completed: Yes \n");
}

void update_stats(milestone_t milestone_array[], int milestone_num){
	float tempf;
	if (milestone_array[milestone_num].completed == 0){
		printf("--------------- Update Stats --------------- \n");
		printf("\n");
		printf("Enter the milestone's actual time:  ");
		milestone_array[milestone_num].time = get_input_f();

		printf("Enter the milestone's actual number of employees:  ");
		milestone_array[milestone_num].num_employees = get_input_usi();

		char tempc[] = "p";
		char Y[] = "Y";
    	char N[] = "N";
        printf("Is this milestone complete?: (Y/N) ");
		scanf("%s", &tempc);
		while (strcmp(tempc, N) != 0 && strcmp(tempc, Y) != 0){
			printf("The value you entered is invalid. \n");
			printf("Please input Y or N: ");
			scanf("%s", &tempc);
        }
		if (strcmp(tempc,Y) == 0) milestone_array[milestone_num].completed = 1;

		tempf = milestone_array[milestone_num].num_employees*milestone_array[milestone_num].time*40*25;
		milestone_array[milestone_num].cost = round(tempf);

		printf("Stats updated!");
	}
	else {
		printf("\n---------------------------------------------------------- \n");
		printf("%s milestone is completed", milestone_array[milestone_num].name);
		printf("\n");
		printf("Completed milestones cannot be updated \n");
		printf("---------------------------------------------------------- \n");
	}
}

void check_project_completion(milestone_t milestone_array[], int num_milestones){
	int counter = 0;
	for (int i=0; i < num_milestones+1; i++){
	if (milestone_array[i].completed == 1){
	 counter ++;
	}
	}
	if (counter == 5) milestone_array[0].completed = 1;
}