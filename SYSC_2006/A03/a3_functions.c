/********* definitions.c ********
    Student Name 	= Ethan Robitaille
    Student Number	= 101233797
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "a3_nodes.h"
#include "a3_functions.h"

// Your solution goes here

/*
   Function that creates a new user and adds it to a sorted (ascending order) linked list at
   the proper sorted location. Return the head of the list.
*/
user_t *add_user(user_t *users, const char *username, const char *password)
{
    //initialize the user in the linked list of users
    user_t *user = malloc(sizeof(user_t));
    assert(user != NULL);
    strcpy(user->username, username);
    strcpy(user->password, password);
    user->friends = NULL;
    user->posts = NULL;

    // If the list is empty or the new node length is less than the head node length
    if (users == NULL || strcmp(user->username, users->username) < 0)
    {
        user->next = users;
        return user;
    }

    user_t *temp = users;
    while (temp->next != NULL && strcmp(user->username, temp->next->username) > 0){
        temp = temp->next;
    }
    user->next = temp->next;
    temp->next = user;
    return users;
}
/*
   Function that searches if the user is available in the database
   Return a pointer to the user if found and NULL if not found.
*/
user_t *find_user(user_t *users, const char *username)
{
    assert(users != NULL);
    for (; users != NULL && strcmp(users->username, username) != 0; users = users->next){}
    return users;
}
/*
   Function that creates a new friend's node.
   Return the newly created node.
*/
friend_t *create_friend(const char *username)
{
    friend_t *friend = malloc(sizeof(friend_t));
    assert(friend != NULL);

    strcpy(friend->username, username);
    return friend;
}

/*
   Function that links a friend to a user. The friend's name should be added into
   a sorted (ascending order) linked list.
*/
void add_friend(user_t *user, const char *friend)
{
    friend_t *nfriend = create_friend(friend);

    // If the list is empty
    if (user->friends == NULL || strcmp(friend, user->friends->username) < 0){
        nfriend->next = user->friends;
        user->friends = nfriend;
    }
    // If the new data is less then the head data
    else{
        friend_t *curr = user->friends;
        while (curr->next != NULL && strcmp(nfriend->username, curr->next->username) > 0){
            curr = curr->next;
        }

        nfriend->next = curr->next;
        curr->next = nfriend;
    }
}

/*
   Function that removes a friend from a user's friend list.
   Return true of the friend was deleted and false otherwise.
*/
_Bool delete_friend(user_t *user, char *friend_name)
{
    friend_t *curr = user->friends;
    friend_t *prev = NULL;
    while (curr != NULL && strcmp(curr->username, friend_name) != 0){
        prev = curr;
        curr = curr->next;
    }

    // Check if the position is valid
    if (curr != NULL){
        // Update the next pointer of the previous node
        if (prev != NULL)
        {
            prev->next = curr->next;
        }
        else
        {
            // If the first node is wanted to be deleted, update the head
            user->friends = curr->next;
        }
        // Free the memory of the deleted node
        free(curr);
        return true;
    }
    else{
        printf("Invalid friend's name\n");
        return false;
    }
}

/*
   Function that creates a new user's post.
   Return the newly created post.
*/
post_t *create_post(const char *text)
{
    post_t *post = malloc(sizeof(post_t));
    assert(post != NULL);

    strcpy(post->content, text);
    post->next = NULL;
    return post;
}

/*
   Function that adds a post to a user's timeline. New posts should be added following
   the stack convention (LIFO) (i.e., to the beginning of the Posts linked list).
*/
void add_post(user_t *user, const char *text)
{
    post_t *post = create_post(text);
    post->next = user->posts;
    user->posts = post;
}

/*
   Function that removes a post from a user's list of posts.
   Return true if the post was deleted and false otherwise.
*/
_Bool delete_post(user_t *user, int number)
{
    post_t *curr = user->posts;
    int count = 0;
    //If no posts exist
    if (number - 1 == 0){
        user->posts = curr->next;
        free(curr);
        printf("Post %d was deleted\n", number);
        return true;
    }
    //Find pointer for the post to delete 
    while (curr != NULL && count < number - 2){
        curr = curr->next;
        count++;
    }
    if (curr == NULL || curr->next == NULL){
        printf("Invalid post number\n");
        return false;
    }
    // delete the found node
    post_t *doublefwrd = curr->next->next;
    free(curr->next);
    curr->next = doublefwrd;
    printf("Post %d was deleted\n", number);
    return true;
}

/*
   Function that  displays a specific user's posts
*/
void display_user_posts(user_t *user)
{
    int pos = 1;
    post_t *post = user->posts;
    //If no posts exist
    if (post == NULL){ 
        printf("No posts available for %s.\n", user->username);
    }
    //Display all posts one by one
    while (post != NULL){
        printf("%d- %s: %s\n", pos, user->username, post->content);
        post = post->next;
        pos++;
    }
}

/*
   Function that displays a specific user's friends
*/
void display_user_friends(user_t *user)
{
    printf("\nList of %s's friends: \n", user->username);
    int counter = 1;
    friend_t *friend = user->friends;
    // if no friends exist
    if (friend == NULL){
        printf("No friends available for %s.\n\n", user->username);
    }
    //print friends one by one
    while (friend != NULL){
        printf("%d- %s\n", counter, friend->username);
        friend = friend->next;
        counter++;
    }
}

void display_friend_posts(user_t *user){
    friend_t *friendc = user->friends;
    post_t *fpost = user->posts;
    friendc->posts = &fpost;
    // I have no idea why this is returning FilchVernon and not ArthurHermione
    // It should be returning ArthurHermione when its inputted but its not
    int pos = 1;
    //If no posts exist
    if (friendc->posts == NULL){ 
        printf("No posts available for %s.\n", friendc->username);
    }
    //Display all posts one by one
    while (friendc->posts != NULL){
        printf("%d- %s: %s\n", pos, friendc->username, fpost->content);
        fpost = fpost->next;
        pos++;
    }
}
/*
   Function that displays all the posts of 2 users at a time from the database.
   After displaying 2 users' posts, it prompts if you want to display
   posts of the next 2 users.
   If there are no more post or the user types “n” or “N”, the function returns.
*/
void display_all_posts(user_t *users)
{
    int counter = 0;
    _Bool exit = true;
    char choice;
    user_t *user = users;
    while (user != NULL){
        //display posts
        if (counter < 2 && exit)
        {
            display_user_posts(user);
            user = user->next;
            counter++;
        }
        //ask to continue
        else
        {
            printf("\n\nDisplay next 2 users posts (Y/N): ");
            scanf(" %c", &choice);
            if (choice == 'Y' || choice == 'y'){
                counter = 0;
                printf("\n\n");
            }
            else if (choice == 'N' || choice == 'n'){
                return;
            }
            else{
                printf("Invalid input\n");
            }
        }
    }
}

/*
   Fucntion that free all users from the database before quitting the application.
*/
void teardown(user_t *users, post_t *posts, friend_t *friends)
{
    user_t *delete;
    post_t *deletep;
    friend_t *deletef;
    
    
    while (posts != NULL)
    {
        deletep = posts;
        posts = posts->next;
        free(deletep);
    }
    while (friends != NULL)
    {
        deletef = friends;
        friends = friends->next;
        free(deletef);
    }
    while (users != NULL)
    {
        delete = users;
        users = users->next;
        free(delete);
    }
}

/*
   Function that prints the main menu with a list of options for the user to choose from
*/
void print_menu()
{
    printf("\n***********************************************\n");
    printf("                   MAIN MENU:\n");
    printf("***********************************************\n");
    printf("1. Register a new user\n");
    printf("2. Login with existing info\n");
    printf("3. Exit\n");
}

void print_user_menu(user_t*user){
    printf("\n***********************************************\n");
    printf("                   Welcome %s:\n", user->username);
    printf("***********************************************\n");
    printf("1. Manage a %s's profile (change the password)\n", user->username);
    printf("2. Manage a %s's posts (display or add or remove)\n", user->username);
    printf("3. Manage a %s's friends (display or add or remove)\n", user->username);
    printf("4. Display All Posts\n");
    printf("5. Logout\n");
}
/*
   ******** DONT MODIFY THIS FUNCTION ********
   Function that reads users from the text file.
   IMPORTANT: This function shouldn't be modified and used as is
   ******** DONT MODIFY THIS FUNCTION ********
*/
user_t *read_CSV_and_create_users(FILE *file, int num_users)
{
    user_t *users = NULL;
    char buffer[500];
    fgets(buffer, sizeof(buffer), file); // Read and discard the header line
    int count = 0;
    for (int i = 0; i < num_users; i++)
    {
        fgets(buffer, sizeof(buffer), file);
        buffer[strcspn(buffer, "\r\n")] = 0; // Remove newline characters

        char *token = strtok(buffer, ",");
        char *token2 = strtok(NULL, ",");
        users = add_user(users, token, token2);
        char *username = token;

        token = strtok(NULL, ",");

        user_t *curr_user = users;
        for (; curr_user != NULL && strcmp(curr_user->username, username) != 0; curr_user = curr_user->next)
            ;

        while (token != NULL && strcmp(token, ",") != 0 && count < 3)
        {
            if (strcmp(token, " ") != 0)
            {
                add_friend(curr_user, token);
            }
            token = strtok(NULL, ",");
            count++;
        }
        count = 0;

        // token = strtok(NULL, ",");
        while (token != NULL && strcmp(token, ",") != 0)
        {
            add_post(curr_user, token);
            token = strtok(NULL, ",");
        }
    }
    return users;
}
