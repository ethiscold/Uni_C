/********* main.c ********
	
	Student Name 	= Ethan Robitaille
	Student Number	= 101233797
*/

// Includes go here
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "a1_functions.h"

milestone_t mile[5];

void main()
{
printf("Welcome to ABC Project Tracker! \n");

printf("Please input the project's total budget: ");
mile[0].cost = get_input_f();


mile[0] = init_milestone("Planned Details", mile[0].cost);
printf("Please input the project's total duation in weeks: ");
mile[0].time = get_input_usi();

number_of_employees(&mile[0]);

printf("The planned number of employees needed is: %d", mile[0].num_employees);
printf("\n");


mile[1] = init_milestone("Technical Requirements", mile[0].cost/5);
mile[2] = init_milestone("System Design", mile[0].cost/5);
mile[3] = init_milestone("Software Development", mile[0].cost/5);
mile[4] = init_milestone("Testing", mile[0].cost/5);
mile[5] = init_milestone("Project Deployment", mile[0].cost/5);

while (mile[0].completed == 0){
	int option1;
	printf("\n");
	printf("---------------------------------------------------------- \n");
	printf("\n");
	
	print_menu();

	scanf("%d", &option1);
	while ((option1 < 0) || (option1 > 5)){
	printf("The value you entered is invalid. \n");
	printf("Please input a number between 0 and 5: ");
	scanf("%d", &option1);
	}
	printf("Your choice is: %d", option1);

	while (option1 == 0){
		char tempc[] = "p";
		char Y[] = "Y";
		char N[] = "N";
		printf("\n------------------------------------- \n");
		printf("---- Final Project's Preformance ---- \n");
		printf("------------------------------------- \n");		
		print_stats(mile[0]);
		printf("\n");
		printf("All milestones are not completed, would you like to continue working? (Y/N)");
		scanf("%s", &tempc);
		while (strcmp(tempc, N) != 0 && strcmp(tempc, Y) != 0){
			printf("\n");
			printf("The value you entered is invalid. \n");
			printf("Please input Y or N: ");
			scanf("%s", &tempc);
		}
		if (strcmp(tempc, Y) == 0) {
			print_menu();
			scanf("%d", &option1);
			while ((option1 < 0) || (option1 > 5)){
				printf("The value you entered is invalid. \n");
				printf("Please input a number between 0 and 5: ");
				scanf("%d", &option1);
			}
			printf("Your choice is: %d", option1);
		}
		else break;
	}
	if (option1 == 0) break;

print_stats(mile[option1]);

if (option1 != 0){
	update_stats(mile, option1);
	print_stats(mile[option1]);
}	

check_project_completion(mile, 5);

}

printf("\n------------------------------------- \n");
printf("---- Final Project's Preformance ---- \n");
printf("------------------------------------- \n");
printf("\n");
float actual = 0;
for (int i=1; i < 5; i++){
	actual = actual + mile[i].cost;
}
if (mile[0].cost > actual){
	printf("The Project is below budget!");
}
else if (mile[0].cost == actual){
	printf("The project is right on target!");
}
else{
	printf("The Project is above budget!");
}
printf("\n");
printf("Planned budget: %0.2f", mile[0].cost);
printf("\n");
printf("Actual budget: %0.2f", actual);
printf("\n");
printf("\n");
printf("------------------------------------------- \n");
printf("--- The Project will quit now! Goodbye! --- \n");
printf("------------------------------------------- \n");
}