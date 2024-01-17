/********* definitions.c ********
	
	Student Name 	= Ahmed Rashid
	Student Number	= 101256081
*/

// Your solution goes here

#include <stdlib.h> 
#include <stdio.h>  
#include <math.h>
#include "a1_functions.h"
#include <stdbool.h>

void number_of_employees(milestone_t *project_details){

	float time, cost, employees;
	int num;
	time = project_details->time; 
	cost = project_details->cost;
	employees = (cost) / (time * 40 * 25);
	num = round(employees);
	project_details->num_employees = num;
}

milestone_t init_milestone(char stage_name[], float assigned_budget){
	milestone_t milestone;
	milestone.cost = assigned_budget / 5;                         
	milestone.num_employees = 0;
	milestone.time = 0;
	milestone.completed = 0;
	strcpy(milestone.name, stage_name); // initialze all the varaibles inside each struct to zero.
	return milestone;
}

unsigned short int get_input_usi(void){
	int num;
	scanf("%d", &num);
	if(num < 0){
		printf("The value you entered is wrong\n");
		printf("Enter a positive value: ");
		get_input_usi();
	}
	return num;
}

float get_input_f(void){
	float num;
	scanf("%f", &num);
	if(num < 0){
		printf("The value you entered is wrong\n");
		printf("Enter a positive value: ");
		get_input_f();
	}
	return num;
}

void print_menu(void){
	printf("\nWhich milestone you want to update? (0 to exit): \n");
	printf("1. Technical Requirements\n");
	printf("2. System Design\n");
	printf("3. Software development\n");
	printf("4. Testing\n");
	printf("5. Product Realase\n");
}


void print_stats(milestone_t details){
	printf("------------Milestone Stats----------\n");
	printf("Below is the '%s' stats\n", details.name);
	printf("-------------------------------------\n");
	printf("Actual time: %0.2f weeks", details.time);
	printf("\nActual number of employees: %d", details.num_employees);
	printf("\nActual cost: %0.2f$", details.cost);
	printf("\nCompleted: %s", details.completed ? "Yes" : "No");
}

void update_stats(milestone_t milestone_array[], int milestone_num){
	printf("\n------------Update Stats----------\n");
	if(milestone_array[milestone_num].completed){
		printf("Milestone is completed \n Cannot be updated \n");
	}
	else{
		char complete;
		printf("\nEnter the milestone's actual time: ");
		milestone_array[milestone_num].time = get_input_f();
		printf("\nEnter the milestone's actual number of employees: ");
		milestone_array[milestone_num].num_employees = get_input_usi();
		printf("\nIs thus milestone complete?: (Y/N)");
		while(true){
			scanf(" %c", &complete);
			if(complete == 'Y'){
				milestone_array[milestone_num].completed = true;
			break;
			}
			else if(complete == 'N'){
				milestone_array[milestone_num].completed = false;
			break;
			}
			else{
				printf("Please enter either Y or N: ");
			}
		}
		milestone_array[milestone_num].cost = milestone_array[milestone_num].num_employees * milestone_array[milestone_num].time * 25 * 40;
		printf("Status Updated!\n");
		print_stats(milestone_array[milestone_num]);
	}
	
}

   
//Check if all milestones are completed or not. If completed, updated the project's details to completed.
void check_project_completion(milestone_t milestone_array[], int num_milestones){
	float total_cost = 0.0;
	for(int i = 1; i <= num_milestones; i++){
		total_cost += milestone_array[i].cost; // NOT GETTING THE CORRECT ACTUAL COST
	}
	if(total_cost < milestone_array[0].cost){
		printf("Project cost below Budget\n");
	}
	else{
		printf("Project cost above Budget\n");
	}
	printf("Planned Budget: %0.2f \nActual Cost: %0.2f \n", milestone_array[0].cost, total_cost);
	
}

void quit_program_text(){ // text to print when ending the program
	printf("-------------------------------------------\n");
	printf("----The program will quit now! Goodbye!----\n");
	printf("-------------------------------------------\n");
}

void projects_performance(){ // text to print when ending the program
	printf("-----------------------------------------\n");
	printf("----------Project's Performance----------\n");
	printf("-----------------------------------------\n");
}
