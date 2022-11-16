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
    scanf("%[^\n]%*c", name); 
}

// Add patient function
// void add_patient(struct Database *temp) { 
//     if(temp->num_patients < MAX_PATIENTS) {
//         printf("Enter patient's id.\n");
//         scanf("%i", &temp->clients[temp->num_patients].id);
//         while ((getchar()) != '\n');
        //    printf("Enter patient's name.\n"); 
//         get_name(temp->clients[temp->num_patients].name); // Get full names having spaces.

//         printf("Enter patient's height.\n");
//         scanf("%f", &temp->clients[temp->num_patients].height);
//         printf("Enter patient's weight.\n");
//         scanf("%f", &temp->clients[temp->num_patients].weight);

//         temp->num_patients++; // Increase the number of patients in the database
//     } else 
//         printf("Database is full!\n");
// }

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
void display(struct Patient temp, int pos) {
    printf("Patient's id: %i\n", temp.id);
    printf("Patient's name: %s\n", temp.name);
    printf("Patient's height: %.2f\n", temp.height);
    printf("Patient's weight: %.2f\n", temp.weight);
    printf("Patient's BMI: %f\n", temp.weight / (temp.height * temp.height));
}

void display_patient(struct Database temp) {
    int patient_ID;
    printf("Enter patient's id.\n");
    scanf("%d", &patient_ID);
    int pos = -1;
    if(checkID(temp.clients, temp.num_patients, patient_ID, &pos)) { // Check whether the input ID is valid or not
        display(temp.clients[pos], pos);
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
        printf("Enter patient's name.\n");
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

// B. 3. add_patient section
void add_patient(struct Database *temp) { 
    if(temp->num_patients < MAX_PATIENTS) {
        int patient_ID;
        printf("Enter patient's id.\n");
        scanf("%d", &patient_ID);
        int pos = -1;

        while(checkID(temp->clients, temp->num_patients, patient_ID, &pos)) { // Check whether the provided ID is unique or not
            printf("There is a patient with the provided ID!\n");
            printf("Enter patient's id.\n");
            scanf("%d", &patient_ID);
        }

        temp->clients[temp->num_patients].id = patient_ID; // Assign the provided ID
        while ((getchar()) != '\n');
        
        printf("Enter patient's name.\n");
        get_name(temp->clients[temp->num_patients].name); // Get full names having spaces.

        printf("Enter patient's height.\n");
        scanf("%f", &temp->clients[temp->num_patients].height);
        printf("Enter patient's weight.\n");
        scanf("%f", &temp->clients[temp->num_patients].weight);

        temp->num_patients++; // Increase the number of patients in the database
    } else 
        printf("Database is full!\n");
}

// C. 1. save_databse section
void save_database(struct Database temp) {
    char file_name[100];
    printf("Enter file's name.\n");
    scanf("%s", file_name);

    FILE  *f = fopen(file_name, "w");

    // add content to file
    fprintf(f, "%i\n", temp.num_patients); 
    for(int i = 0; i < temp.num_patients; i++) 
        fprintf(f, "%i,%s,%i,%.2f,%.2f\n", temp.clients[i].id, temp.clients[i].name, 30, temp.clients[i].weight, temp.clients[i].height);
        
    fclose(f); // close file 
}

// C. 2. retrieve_database 
void retrieve_database(struct Database *temp) {
    char file_name[100];
    printf("Enter file's name.\n");
    scanf("%s", file_name); 

    FILE *f = fopen(file_name, "r");
    if (f == NULL) // check whether the file is exist
        printf("Error! Doesn't exist %s", file_name); 
    
    // assign the content to variables
    int unknown_variable;
    fscanf(f, "%i\n", &temp->num_patients);
    for(int i = 0; i < temp->num_patients; i++) 
        fscanf(f, "%i,%[^,],%i,%f,%f\n", &temp->clients[i].id, temp->clients[i].name, &unknown_variable, &temp->clients[i].weight, &temp->clients[i].height);
    
    fclose(f); // close file 
}


// C. 3. display_critical_patients section
void display_critical_patients(struct Database temp) {
    float BMI[temp.num_patients]; 
    
    int count = 0;
    for(int i = 0; i < temp.num_patients; i++) {
        BMI[i] = temp.clients[i].weight / (temp.clients[i].height * temp.clients[i].height); // caculate all patients' BMI
        if(BMI[i] < 18 && BMI[i] > 30) { // validate
            display(temp.clients[i], i);
            printf("\n");
        } else 
            count++;
    }

    if(count > 0) 
        printf("No critical patient!\n");
}

int main() {
    struct Database list;
    list.num_patients = 0;

    char option = 'a';
    while (option != 'x') {
        printf("Enter [a] to add a patient, [d] to display a patient, [e] to edit a patient, [r] to remove a patient, [s] to save, [o] to retrieve database, [c] to display critical patient, [x] to exit\n");
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
        case 's':
            // C. 1. Save database
            save_database(list);
            break;
        case 'o':
            // C. 2. Retrieve database
            retrieve_database(&list);
            break;
        case 'c':
            // C. 3. Display critical patients
            display_critical_patients(list);
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

