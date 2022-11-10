#include<stdio.h>
#include<iostream>
#define MAX_NAME 32
#define MAX_PATIENTS 16
using namespace std;
// 1. Struct: Patient 
struct Patient {
    int id;
    // char *name;
    string name;
    float weight;
    float height;
};

// 2. Struct: Database
struct Database {
    int num_patients = 0;
    struct Patient clients[16];
};

int main() {
    struct Database list;
    list.num_patients = 2;

    list.clients[0].id = 21;
    list.clients[0].name = "Hoang";

    list.clients[1].id = 12;
    list.clients[1].name = "Hau";

    for(int i = 0; i < list.num_patients; i++) {
        printf("ID: %i\n", list.clients[0].id);
        printf("Name: %s\n", list.clients[0].name);
    }
}