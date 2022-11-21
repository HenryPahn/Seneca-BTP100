// Workshop 07 - Hoang Phan
#include <stdio.h>
#define SIZE 32

// Enter your get_length function here
int get_length(char *name)
{
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
        count++;
    return count;
}

// Enter your break_names function here
void break_names(char *name, char *first_name, char *last_name)
{
    // for(int i = 0; ; i++) {
    //     if(name[i] == ' ') {
    //         int k = 0;
    //         for(int j = i + 1; name[j] != '\0'; j++) {
    //             last_name[k] = name[j];
    //             k++;
    //         }
    //         last_name[k] = '\0';
    //         first_name[i] = '\0';
    //         break;
    //     } else
    //         first_name[i] = name[i];
    // }
    
    while (*name != ' ')
        *first_name++ = *name++;
    *first_name = '\0';
    name++;
    while (*name != '\0')
        *last_name++ = *name++;
}

void get_name(char *name)
{
    printf("Enter your full name: ");
    scanf("%[^\n]%*c", name);
}

int main()
{

    char name[SIZE] = {"Marcel Jar"}, first_name[SIZE], last_name[SIZE];

    get_name(name);
    printf("Your character array has %i characters.\n",

           get_length(name));
    printf("Full name: %s\n", name);

    break_names(name, first_name, last_name);
    printf("First name: %s\n", first_name);
    printf("Last name: %s\n", last_name);

    return 0;
}