#include <stdio.h>


//Define your struct here
struct student
{
    int id; 
    char name[32];
    float gpa;
};

void get_name (char *name) {
    scanf("%[^\n]%*c", name);
}

//Define save_student here
void save_student(struct student *temp) {
    printf("Enter id: "); 
    scanf("%i", &temp->id);
    while((getchar()) != '\n');
    printf("Enter name: ");
    get_name(temp->name);
    printf("Enter gpa: ");
    scanf("%f", &temp->gpa);
}

//Define Print_student here
void print_student(struct student temp) {
    printf("Id: %i\n", temp.id); 
    printf("Name: %s\n", temp.name);
    printf("GPA: %.2f\n", temp.gpa);
}

void save(struct student temp) {
    FILE *f = NULL;
    char file[100];
    while((getchar()) != '\n');
    printf("enter file name: "); 
    get_name(file);
    f = fopen(file, "w");
    if (f != NULL) {
        fprintf(f, "%i,%s,%f", temp.id, temp.name, temp.gpa);
        fclose(f);
    } else 
        printf("error\n");
}

void open(struct student *temp) {
    FILE *f = NULL;
    char file[100];
    printf("enter file name: "); 
    get_name(file);
    f = fopen(file, "r");
    if (f != NULL) {
        fscanf(f, "%i,%[^,],%f", &temp->id, &temp->name, &temp->gpa);
        fclose(f);
    } else 
        printf("error\n");
}

int main() {
    
    struct student individual; 

    // save_student(&individual);
    
    // save(individual);
    open(&individual);
    print_student(individual);
    return 0;
}