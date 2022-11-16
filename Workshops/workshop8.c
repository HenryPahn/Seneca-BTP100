// Workshop 08 - Hoang Phan
#include <stdio.h>
#define MAX_NAME 32

// Define your struct here
struct student
{
    int id;
    char name[MAX_NAME];
    float GPA;
};

// Define save_student here
void get_name(char *name)
{
    scanf("%[^\n]%*c", name);
}

void save_student(struct student *temp)
{
    printf("Enter student's id.\n");
    scanf("%i", &temp->id);
    while ((getchar()) != '\n');
    printf("Enter student's name.\n");
    get_name(temp->name);
    printf("Enter student's gpa.\n");
    scanf("%f", &temp->GPA);
}

// Define Print_student here
void print_student(struct student temp)
{
    printf("Student's id: %i\n", temp.id);
    printf("Student's name: %s\n", temp.name);
    printf("Student's gpa: %.2f\n", temp.GPA);
}

int main()
{
    struct student individual;
    save_student(&individual);
    print_student(individual);
    return 0;
}