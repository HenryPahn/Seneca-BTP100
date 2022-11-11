#include <stdio.h>
#define MAX_NAME 32
#define MAX_PATIENTS 16


// A. 1. Struct Patient
struct Patient {
    int id; 
    char name[MAX_NAME];
    float weight;
    float height;
};

// A. 2. Struct Database
struct Database {
    struct Patient clients[MAX_PATIENTS];
    int num_patients;
};

// A. 3. add_patient section
// Get full names having spaces.
void get_name(char *name){ 
    printf("Enter patient's name.\n");
    scanf("%[^\n]%*c", name); 
}

// Add patient function
void add_patient(struct Database *temp) { 
    if(temp->num_patients < MAX_PATIENTS) {
        printf("Enter patient's id.\n");
        scanf("%i", &temp->clients[temp->num_patients].id);
        while ((getchar()) != '\n');
        
        get_name(temp->clients[temp->num_patients].name); // Get full names having spaces.

        printf("Enter patient's height.\n");
        scanf("%f", &temp->clients[temp->num_patients].height);
        printf("Enter patient's weight.\n");
        scanf("%f", &temp->clients[temp->num_patients].weight);

        temp->num_patients++; // Increase the number of patients in the database
    } else 
        printf("Database is full!\n");
}

// A. 4. display_patient section
// Check whether the input ID is valid or not
int checkID(struct Patient *arr, int n, int key, int *pos) { 
    for(int i = 0; i < n; i++) 
        if(arr[i].id == key) {
            *pos = i;
            return 1;
        }
    return 0;
}

// Display patient function
void display_patient(struct Database temp) {
    int patient_ID;
    printf("Enter patient's id.\n");
    scanf("%d", &patient_ID);
    int pos = -1;
    if(checkID(temp.clients, temp.num_patients, patient_ID, &pos)) { // Check whether the input ID is valid or not
        printf("Patient's id: %i\n", temp.clients[pos].id);
        printf("Patient's name: %s\n", temp.clients[pos].name);
        printf("Patient's height: %.2f\n", temp.clients[pos].height);
        printf("Patient's weight: %.2f\n", temp.clients[pos].weight);
        printf("Patient's BMI: %f\n", temp.clients[pos].weight / (temp.clients[pos].height * temp.clients[pos].height));
    } else 
        printf("Error! Invalid patient's ID!!!\n");
}

// B. 1. edit_patient section
void edit_patient(struct Database *temp) {
    int patient_ID;
    printf("Enter patient's id.\n");
    scanf("%d", &patient_ID);
    int pos = -1;
    if(checkID(temp->clients, temp->num_patients, patient_ID, &pos)) { // Check whether the input ID is valid or not
        while ((getchar()) != '\n');
        get_name(temp->clients[pos].name); // Get full names having spaces.

        printf("Enter patient's height.\n");
        scanf("%f", &temp->clients[pos].height);
        printf("Enter patient's weight.\n");
        scanf("%f", &temp->clients[pos].weight);
    } else 
        printf("Error! No patient with provided ID found!!!\n");
}

// B. 2. remove_patient section
void remove_patient(struct Database *temp) {
    int patient_ID;
    printf("Enter patient's id.\n");
    scanf("%d", &patient_ID);
    int pos = -1;
    if(checkID(temp->clients, temp->num_patients, patient_ID, &pos)) { // Check whether the input ID is valid or not
        for(int i = pos; i < temp->num_patients - 1; i++) // Remove patient's id at the current position
            temp->clients[i] = temp->clients[i + 1];
        temp->num_patients--;
    } else 
        printf("Error! No patient with provided ID found!!!\n");
}

int main() {
    struct Database list;
    list.num_patients = 0;

    char option = 'a';
    while (option != 'x') {
        printf("Enter [a] to add a patient, [d] to display a patient, [e] to edit a patient, [r] to remove a patient, [x] to exit\n");
        scanf("%c", &option); 

        switch (option)
        {
        case 'a':
            // A. 3. Add a patient
            add_patient(&list);
            break;
        case 'd':
            // A. 4. Display a patient
            display_patient(list);
            break;
        case 'e':
            // B. 1. Edit a patient
            edit_patient(&list);
            break; 
        case 'r':
            // B. 2. Remove a patient
            remove_patient(&list);
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

