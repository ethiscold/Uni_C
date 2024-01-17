/********* main.c ********
    Student Name 	= Ethan Robitaille
    Student Number	= 101233797
*/

// Includes go here
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "a2_nodes.h"
#include "a2_functions.h"

int main()
{
    /******** DONT MODIFY THIS PART OF THE CODE ********/
    /* THIS CODE WILL LOAD THE DATABASE OF USERS FROM THE FILE
       AND GENERATE THE STARTING LINKED LIST.
    */
    FILE *csv_file = fopen("user_details.csv", "r");
    if (csv_file == NULL)
    {
        perror("Error opening the CSV file");
        return 1;
    }
    // Parse CSV data and create users
    user_t *users = read_CSV_and_create_users(csv_file, 50);

    fclose(csv_file);
    /******** DONT MODIFY THIS PART OF THE CODE ********/

    /* IMPORTANT: You must use the users linked list created in the code above.
                  Any new users should be added to that linked list.
    */

    // Your solution goes here
    int option = 0;
    printf("--------------------------\n");
    printf("Text based Facebook\n");
    printf("--------------------------\n");
    while (option != 6){
        user_t *searchu = users;
        print_menu();
        printf("Enter your choice: \n");
        scanf("%d", &option);
        // make sure the option is between 1 and 6
        while (option < 1 || option > 6){
            printf("Invalid choice. Please try again. \n");
            print_menu();
            scanf("%d", &option);
        }
        char username[30];
        char password[15];
        // Register new user
        if (option == 1){
            printf("Please enter a username under 30 chacaters: ");
            scanf("%s", username);
            printf("\n");
            printf("Please enter a password under 15 characters:");
            scanf("%s", password);
            printf("\n");
            add_user(users, username, password);
        }
        // Edit user
        if (option == 2){
            printf("Please enter a username to update their password: ");
            scanf("%s", username);
            printf("\n");
            searchu = find_user(users, username);
            //confirm that user exists
            if (searchu == NULL){
                printf("Invalid username! \n");
            }
            else{
            printf("Please enter a new password under 15 characters: ");
            scanf("%s", password);
            printf("\n");
            strcpy(searchu->password, password);
            }
        }
        //manage a user's posts
        if (option == 3){
            int choice = 0;
            printf("Please enter a username to manage their posts: ");
            scanf("%s", username);
            printf("\n");
            searchu = find_user(users, username);
            //confirm that user exists
            if (searchu == NULL){
                printf("Invalid username! \n");
                choice = 3;
            }
            // if no exit clause is reached
            while (choice != 3){
                printf("--------------------------\n");
                printf("%s's posts \n", searchu->username);
                display_user_posts(searchu);
                printf("--------------------------\n");
                printf("\n");

                printf("1. Add a new post \n");
                printf("2. Remove a post \n");
                printf("3. Return to menu \n");
                printf("Your Choice:");
                scanf("%d", &choice);
                printf("\n");
                // make a post
                if (choice == 1){
                    char text[250];
                    printf("Enter post content: ");
                    scanf("%s[^\n]", text);
                    printf("\n");
                    create_post(text);
                    add_post(searchu, text);
                    printf("Post created. \n");
                }
                //delete a post
                else if (choice == 2){
                    int delp = 0;
                    _Bool a = false;
                    while (a == false){
                        printf("Enter which post to delete: \n");
                        scanf("%d", &delp);
                        a = delete_post(searchu, delp);
                    }
                    
                }
            }
        }
        //manage a user's friends
        if (option == 4){
            char fname[30];
            int choice = 0;
            printf("Please enter a username to manage their friends: ");
            scanf("%s", username);
            printf("\n");
            searchu = find_user(users, username);
            //confirm that user exists
            if (searchu == NULL){
                printf("Invalid username! \n");
                choice = 4;
            }
            // if exit clause is not reached
            while (choice != 4){
                printf("--------------------------\n");
                printf("%s's Friends \n", searchu->username);
                printf("--------------------------\n");
                printf("\n");

                printf("1. Display all of the user's friends \n");
                printf("2. Add a new Friend \n");
                printf("3. Remove a Friend \n");
                printf("4. Return to menu \n");
                printf("Your Choice:");
                scanf("%d", &choice);
                printf("\n");
                // display all friends for a user
                if (choice == 1){
                    display_user_friends(searchu);
                }
                // add a friend
                else if (choice == 2){
                    printf("Please enter a username to manage their friends: \n");
                    scanf("%s", fname);
                    if (strcmp(searchu->username, fname) < 0){
                        printf("Invalid Username \n");
                        choice = 4;
                    }
                    else{
                    add_friend(searchu, fname);
                    printf("Added friend successfully \n");
                    }
                }
                // remove a friend
                else if (choice == 3){
                    _Bool a = false;
                    char fname[30]; 
                    // if the desire user to delete doesnt exist, dont just error and return no change
                    display_user_friends(searchu);
                    printf("Enter which Friend to remove: ");
                    scanf("%s", fname);
                    printf("\n");
                    a = delete_friend(searchu, fname);
                    if (a == false){
                        choice = 4;
                    }
                }
            }
        }
        //display all posts (code in a2_functions)
        if (option == 5){
            display_all_posts(users);
        }
        // if option is 6, exit the while loop and terminate the program
    }
    // remove all users from the linked list of users to eliminate any memory drain / leaks
    teardown(users);
    printf("---------------------------------------\n");
    printf("Thanks for using Text based Facebook! \n");
    printf("              Goodbye! \n");
    printf("---------------------------------------\n");
}