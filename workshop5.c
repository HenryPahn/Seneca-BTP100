//Workshop 6 - Hoang Phan
#include <stdio.h>
#define SIZE 16

int main() {
    int ids[4];
    char names[4][SIZE];
    int num_users = 0;

    char option = 'a';
    while (option != 'x') {
        printf("What do you want to do? [a] add a user, [l] list all users, [e] edit a user?, [x] exit\n");
        scanf("%c", &option); 
        while ((getchar()) != '\n');

        switch (option)
        {
            int changeID;
        case 'a':
            if (num_users <= 4) {
                printf("Enter the user's name.\n");
                scanf("%s", names[num_users]);
                while ((getchar()) != '\n');
                ids[num_users] = num_users + 1;
                num_users += 1;
            }
            else {
                printf("Database full.\n");
            }
            break;
        case 'l':
            // 1. List all users
            for (int i = 0; i < num_users; i++) {
                printf("%d-", i + 1); // Display users' ID 

                for (int j = 0; names[i][j] != '\0'; j++) //  Display users' names
                    printf("%c", names[i][j]);
                printf("\n");
            }
            break;
        case 'e':
            // 2. Edit a user
            printf("Enter the user's id.\n");
            scanf("%d", &changeID);
            while ((getchar()) != '\n');
            
            changeID--; 
            if (changeID >= 0 && changeID < num_users) {
                printf("Enter the user's name.\n");
                scanf("%s", names[changeID]);
                while ((getchar()) != '\n');
            } else 
                printf("The user does not exist!");
            break;
        case 'x':
            printf("Quiting the application. Bye.\n");
            break;
        default:
            printf("Error! invalid option.\n");
            break;
        }
    }
    return 0;
}