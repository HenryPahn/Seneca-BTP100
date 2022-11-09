#include <stdio.h>

int main()
{
    // 1. Initialize 4 integer variables
    int feet, inches, meters, centimeters;

    // 2. Ask users for height in feet and inches
    printf("Enter your height in feet and inches:");
    scanf("%d", &feet);
    scanf("%d", &inches);

    //  3. Create a floating-point variable
    double overalHeight;
    overalHeight = (double) feet * 30.48 + inches * 2.54;

    // 4. Value of meter
    meters = (int) overalHeight / 100;

    // 5. Value of centimeter
    centimeters = (int) overalHeight - (100 * meters);

    // 6. Display height in meters and centimeters
    printf("\n%dm %d cm\n", meters, centimeters);
    return 0;
}