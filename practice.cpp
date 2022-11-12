#include <iostream>
#define MAX_NAME 32
using namespace std;

struct Patient{
    int id; 
    char name[MAX_NAME];
    float weight; 
    float height; 
};

struct Database {
    Patient *clients;
    int num_patient = 0;
};