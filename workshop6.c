// Workshop 6 - Hoang Phan
#include<stdio.h>
#define SIZE 6


//your maximum function goes here
int maximum(int a, int b) {
    if (a > b) return a;
    return b;
}

//your weeks function goes here
void weeks(int days) {
    int dates = days % 7;
    int weeks = (days - dates) / 7;
    printf("%i days is equivalent to %i weeks and %i days\n\n", days, weeks, dates);
}

//your print_evens function goes here
void print_evens(int *arr, int n) {
    printf("The even-indexed elements are: ");
    for (int i = 0; i < 5; i++) 
        if (i % 2 == 0) 
            printf("%i ", arr[i]);
}

int main() {

    printf("max(4,9) = %i\n", maximum(4, 9));
    printf("max(8,7) = %i\n", maximum(8, 7));
    printf("max(2,2) = %i\n", maximum(2, 2));

    weeks(16);
    weeks(24);
    weeks(47);

    int list[SIZE] = { 10, 20, 30, 40, 50, 60 };
    print_evens(list, SIZE);

    return 0;
}