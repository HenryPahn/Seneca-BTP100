// Assignment - John Mubeezi Ochieng
#include<stdio.h>
#pragma warning(disable:4996)
//patient struct 
struct patient {
	int id;
	char name[32];
	int age;
	float weight, height;

};

// database struct
struct database {
	struct patient patients[16];
	int count_patient;
};

// add_patient
void add_patient(struct database *patient){
	int index = patient->count_patient;
	printf("enter the patient's id : \n");
	scanf("%i", &patient->patients[index].id);
	while ((getchar()) != '\n');
	printf("enter the patient's name : \n");
	scanf("%32[^\n]", patient->patients[index].name);
	
	printf("enter the patient's age  : \n");
	scanf("%i", &patient->patients[index].age);
	
	printf("enter the patient's weight : \n");
	scanf("%f", &patient->patients[index].weight);
	
	printf("enter the patient's height : \n");
	scanf("%f", &patient->patients[index].height);
	
	
	patient->count_patient++;
}

// display_patient
void display_patient(struct database patient) {
	int index;
	int x = 0,y=0;
    while ((getchar()) != '\n');
	printf("enter the id of the patient whose information you want to display: \n");
	scanf("%i", &index);
	for (int i = 0; i < patient.count_patient; i++) {
		if (patient.patients[i].id == index) {
			printf("id: %i, name: %s, age: %i, weight: %f, heigth: %f, bmi: %f \n", patient.patients[y].id, patient.patients[y].name, patient.patients[y].age, patient.patients[y].weight, patient.patients[y].height, patient.patients[y].weight / (patient.patients[y].height * patient.patients[y].height));
		}
		else {
			printf("That patient does not exist! Try again \n");
		}
	}
	/*if (index == y) {
		printf("id: %i, name: %s, age: %i, weight: %f, heigth: %f, bmi: %f \n", patient.patients[y].id, patient.patients[y].name, patient.patients[y].age, patient.patients[y].weight, patient.patients[y].height, patient.patients[y].weight / (patient.patients[y].height * patient.patients[y].height));
	}
	else {
		printf("That patient does not exist! Try again \n");
	}*/
}

int main() {
	char option;
	struct database patient;
	patient.count_patient = 0;

	do {
		printf("enter [a] to add a patient, [d] to display info about a given patient ,or [q] to exit: \n ");
		scanf("%c", &option);
		while ((getchar()) != '\n');
		switch (option) {
		case 'a':
			add_patient(&patient);
				//
			break;
		case 'd':
			display_patient(patient);
				//
			break;
		case 'q':
				//
				break;
		default:
			printf("Invalid option! Please  ");

		}
		

	} while (option != 'q');


	return 0;
}