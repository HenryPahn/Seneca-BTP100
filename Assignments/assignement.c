// Assignment - Hoang Phan 
#include <stdio.h>
#define MAX_NAME 32
#define MAX_PATIENTS 16

void clearInputBuffer(void)
{
    while (getchar() != '\n')
    {
        ; 
    }
}

// A. 1. Struct Patient
struct Patient
{
    int id;
    char name[MAX_NAME];
    int age;
    float weight;
    float height;
};

// A. 2. Struct Database
struct Database
{
    struct Patient clients[MAX_PATIENTS];
    int num_patients;
};

// A. 3. add_patient section
// Get full names having spaces.
void get_name(char *name)
{
    scanf("%[^\n]%*c", name);
}

// Add patient function
void add_patient(struct Database *temp)
{
    if (temp->num_patients < MAX_PATIENTS)
    {
        printf("Enter patient's id.\n");
        scanf("%i", &temp->clients[temp->num_patients].id);
        clearInputBuffer();
        printf("Enter patient's name.\n");
        get_name(temp->clients[temp->num_patients].name); // Get full names having spaces.
        printf("Enter patient's age.\n");
        scanf("%i", &temp->clients[temp->num_patients].age);
        printf("Enter patient's weight.\n");
        scanf("%f", &temp->clients[temp->num_patients].weight);
        printf("Enter patient's height.\n");
        scanf("%f", &temp->clients[temp->num_patients].height);

        temp->num_patients++; // Increase the number of patients in the database
    }
    else
        printf("Database is full!\n");
}

// A. 4. display_patient section
// Check whether the input ID is valid or not
int checkID(const struct Patient *arr, int n, int key, int *pos)
{
    for (int i = 0; i < n; i++)
        if (arr[i].id == key)
        {
            *pos = i;
            return 1;
        }
    return 0;
}

// Display patient function
void display(const struct Patient *temp, int pos)
{
    printf("Patient's id: %i\n", temp->id);
    printf("Patient's name: %s\n", temp->name);
    printf("Patient's age: %i\n", temp->age);
    printf("Patient's weight: %.2f\n", temp->weight);
    printf("Patient's height: %.2f\n", temp->height);
    printf("Patient's BMI: %f\n", temp->weight / (temp->height * temp->height));
}

void display_patient(const struct Database *temp)
{
    int patient_ID;
    printf("Enter patient's id.\n");
    scanf("%d", &patient_ID);
    int pos = -1;
    if (checkID(temp->clients, temp->num_patients, patient_ID, &pos)) // Check whether the input ID is valid or not
    { 
        display(&temp->clients[pos], pos);
    }
    else
        printf("Error! Invalid patient's ID!!!\n");
}

int main()
{
    struct Database list;
    list.num_patients = 0;

    char option = 'a';
    while (option != 'x')
    {
        printf("Enter [a] to add a patient, [d] to display a patient, [x] to exit\n");
        scanf("%c", &option);

        switch (option)
        {
        case 'a':
            // A. 3. Add a patient
            add_patient(&list);
            break;
        case 'd':
            // A. 4. Display a patient
            display_patient(&list);
            break;
        case 'x':
            // A. 5. Exit the program
            printf("Quiting the application. Bye.\n");
            break;
        default:
            printf("Error! invalid option.\n");
            break;
        }
        while ((getchar()) != '\n');
    }
    return 0;
}
