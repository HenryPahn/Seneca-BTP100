// Assignment - Hoang Phan 
#include <stdio.h>
#define MAX_NAME 32
#define MAX_PATIENTS 16

void clearInputBuffer(void) // clear buffer
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

// A. 3. & B. 3. add_patient section
// Get full names having spaces.
void get_name(char *name)
{
    scanf("%[^\n]%*c", name);
}

// add_patient function
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
        printf("Enter patient's age.\n");
        scanf("%i", &temp->clients[temp->num_patients].age);
        printf("Enter patient's weight.\n");
        scanf("%f", &temp->clients[temp->num_patients].weight);
        printf("Enter patient's height.\n");
        scanf("%f", &temp->clients[temp->num_patients].height);

        temp->num_patients++; // Increase the number of patients in the database
    } else 
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
void display(const struct Patient *temp)
{
    printf("***************\n");
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
        display(&temp->clients[pos]);
    }
    else
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
        printf("Enter patient's age.\n");
        scanf("%i", &temp->clients[pos].age);
        printf("Enter patient's weight.\n");
        scanf("%f", &temp->clients[pos].weight);
        printf("Enter patient's height.\n");
        scanf("%f", &temp->clients[pos].height);
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
        printf("Remove sucess!\n");
    } else 
        printf("Error! No patient with provided ID found!!!\n");
}

// C. 1. save_databse section
void save_database(const struct Database *temp) {
    char file_name[100];
    printf("Enter file's name.\n");
    scanf("%s", file_name);

    FILE  *f = NULL;
    f = fopen(file_name, "w");

    // add content to file
    fprintf(f, "%i\n", temp->num_patients); 
    for(int i = 0; i < temp->num_patients; i++) 
        fprintf(f, "%i,%s,%i,%.2f,%.2f\n", temp->clients[i].id, temp->clients[i].name, temp->clients[i].age, temp->clients[i].weight, temp->clients[i].height);
    fclose(f); // close file 
}

// C. 2. retrieve_database 
void retrieve_database(struct Database *temp) {
    char file_name[100];
    printf("Enter file's name.\n");
    scanf("%s", file_name); 

    FILE *f = NULL;
    f = fopen(file_name, "r");
    if(f != NULL) {
        // assign the content to variables
        int number, tp;
        fscanf(f, "%i\n", &number);
        int i = temp->num_patients;
        temp->num_patients += number;
        for(; i < temp->num_patients; i++) 
        fscanf(f, "%i,%[^,],%i,%f,%f\n", &temp->clients[i].id, temp->clients[i].name, &temp->clients[i].age, &temp->clients[i].weight, &temp->clients[i].height);
    } else
        printf("Error! Doesn't exist %s\n", file_name); // check whether the file is exist
    fclose(f); // close file 
}


// C. 3. display_critical_patients section
void display_critical_patients(const struct Database *temp) {
    int count = 0;
    for(int i = 0; i < temp->num_patients; i++) {
        float BMI = temp->clients[i].weight / (temp->clients[i].height * temp->clients[i].height); // caculate all patients' BMI
        if(BMI < 18 || BMI > 30) {// validate
            display(&temp->clients[i]);
            count++;
        }
    }
    if(count == 0) 
        printf("No critical patient!\n");
}

int main()
{
    struct Database list;
    list.num_patients = 0;

    char option = 'a';
    while (option != 'x')
    {
        printf("****************************\n");
        printf("Enter [a] to add a patient, [d] to display a patient, [e] to edit a patient, [r] to remove a patient, [s] to save, [o] to retrieve database, [c] to display critical patient, [x] to exit\n");
        scanf("%c", &option);

        switch (option)
        {
        case 'a':
            // B. 3. Add a patient
            add_patient(&list);
            break;
        case 'd':
            // A. 4. Display a patient
            display_patient(&list);
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
            save_database(&list);
            break;
        case 'o':
            // C. 2. Retrieve database
            retrieve_database(&list);
            break;
        case 'c':
            // C. 3. Display critical patients
            display_critical_patients(&list);
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
