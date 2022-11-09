#include<iostream>
using namespace std; 

int main() {
    for(int i = 0; i < 30; i++) {
        if (i != 15) {
            for (int j = 0; j < 50; j++) {
                cout << "*";
            }
            cout << endl;
        } else {
            for(int k = 0; k < 20; k++)
                cout << "*";
            cout << "I love you";
            for(int k = 0; k < 20; k++)
                cout << "*";
            cout << endl;
        }
            
    }
}