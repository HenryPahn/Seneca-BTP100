#include <stdio.h>
#define SIZE 32

//Enter your get_length function here

//Enter your break_names function here

void get_name(char *name){
    printf("Enter your full name: ");
    //scanf("%[^\n]%*c", name);
    scanf_s("%[^\n]%*c", name, SIZE); //Visual Studio
}

int main(){
    
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