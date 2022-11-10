#include <stdio.h>
#define MAX_NAME 32
#define MAX_PATIENTS 16

// 1. Struct: Patient 
struct Patient {
    int id;
    char name[MAX_NAME];
    float weight;
    float height;
};

// 2. Struct: Database
struct Database {
    int num_patients;
    struct Patient clients[MAX_PATIENTS];
};

// 3. Add patient section
void get_name(char *name){
    printf("Enter patient's name.\n");
    scanf("%[^\n]%*c", name); 
}

void add_patient(struct Database list) {
    if(list.num_patients < MAX_PATIENTS) {
        printf("Enter patient's id.\n");
        scanf("%i", &list.clients[list.num_patients].id);
        while ((getchar()) != '\n');
        

        get_name(list.clients[list.num_patients].name);
        

        printf("Enter patient's weight.\n");
        scanf("%f", &list.clients[list.num_patients].weight);
        while ((getchar()) != '\n');
        printf("Enter patient's height.\n");
        scanf("%f", &list.clients[list.num_patients].height);
        while((getchar()) != '\n');
        list.num_patients++;
    } else {
        printf("Database is full!\n");
    }
}

// 4. Display patient section
int getID() {
    int id;
    printf("Enter patient'id.\n");
    scanf("%i", &id);
    return id;
}

void checkID(struct Patient *arr, int n) {
    // for(int i = 0; i < n; i++) 
    //     if(arr[i].id == patient_id)
    //         return 1;
    // return 0;
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i].name);
}

void display_patient(struct Database list) {
    // int patient_id = getID();
    // if(checkID(list.clients, list.num_patients, patient_id)) {
    //     printf("Patient's id: %i\n", list.clients[patient_id].id);
    //     printf("Patient's name: %s\n", list.clients[patient_id].name);
    //     printf("Patient's weight: %f\n", list.clients[patient_id].weight);
    //     printf("Patient's height: %f\n", list.clients[patient_id].height);
    //     printf("Patient's BMI: %f\n", list.clients[patient_id].weight * list.clients[patient_id].height);
    // } else 
    //     printf("Patient's id is invalid!\n");

    // checkID(list.clients, list.num_patients);
    for(int i = 0; i < list.num_patients; i++) {
        printf("%i. %s", list.clients[i].id, list.clients[i].name);
    }
}

int main() {
    struct Database list;
    list.num_patients = 0;
    
    char option = 'a';
    while (option != 'x') {
        printf("What do you want to do? [a] add a user, [d] display all users, [e] edit a user?, [x] exit\n");
        scanf("%c", &option); 
        while ((getchar()) != '\n');

        switch (option)
        {
            int changeID;
        case 'a':
            // 3. add_patient
            add_patient(list);
            break;
        case 'd':
            // 4. display_patient
            display_patient(list);
            break;
        case 'x':
            // 5. exist
            printf("Quiting the application. Bye.\n");
            break;
        default:
            printf("Error! invalid option.\n");
            break;
        }
    }
    return 0;
}