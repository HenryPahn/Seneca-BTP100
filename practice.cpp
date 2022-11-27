#include<iostream>
#include<math.h>
using namespace std;

int CheckPositive(int n) {
    if(n > 0) return 1;
    return 0;
}

void ConvertPositiveToBinary(int n) {
    for(int i = 7;  i > 0; i--) {
        if(n < pow(2, i) && n > pow(2, i - 1)) {
            n -= 
        }
    }
}

int main() {
    int n;
    cout << "Enter n." << endl;
    cin >> n;

    if(CheckPositive(n)) 
        ConvertPositiveToBinary(n);
    else 
        ConvertNegativeToBinary(n);
}