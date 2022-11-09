// Workshop 4 - Hoang Phan
#include <stdio.h>

int main()
{
	// 1. Initialize 3 variables
	int initialInt, finalInt;
	int sum = 0;

	// 2. Assign and 3. Validiation
	do
	{
		printf("Initial integer has to be smaller than final integer\n");
		printf("Enter the initial number: ");
		scanf("%d", &initialInt);
		while ((getchar()) != '\n');
		printf("Enter the final number: ");
		scanf("%d", &finalInt);
	} while (initialInt > finalInt);

	// 4. Using for loop to add number to Sum variable
	if (initialInt == finalInt)
	{
		sum = initialInt;
		printf("Answer: %d", initialInt);
	}
	else
	{
		for (int i = initialInt; i <= finalInt; i++)
			sum += i;
		printf("Answer: %d", sum);
	}
	return 0;
}