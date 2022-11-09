// Workshop 03 - Hoang Phan
#include <stdio.h>

int main()
{
	// 1. Initializing 2 float and 1 char variables.
	float num1, num2; 
	char op; 

	// 2. Ask user to enter the values.
	printf("Enter the first variable: ");
	scanf("%f", &num1);
	while ((getchar()) != '\n');
	printf("Enter the operation: ");
	scanf("%c", &op);
	printf("Enter the second variable: ");
	scanf("%f", &num2);

	// 3. Arithmetic by if else
	/*
	if (op == '+')
		printf("%.2f + %.2f =  %.2f\n", num1, num2, (float)num1 + num2);
	else if (op == '-')
		printf("%.2f - %.2f =  %.2f\n", num1, num2, (float)num1 - num2);
	else if (op == '*')
		printf("%.2f * %.2f =  %.2f\n", num1, num2, (float)num1 * num2);
	else if (op == '/')
		printf("%.2f / %.2f =  %.2f\n", num1, num2, (float)num1 / num2);
	else
		printf("Invalid operation!"); 
	*/

	// 4. Arithmetic by switch
	switch (op)
	{
		case '+':
			printf("%.2f + %.2f =  %.2f\n", num1, num2, (float)num1 + num2);
			break;
		case '-':
			printf("%.2f - %.2f =  %.2f\n", num1, num2, (float)num1 - num2);
			break;
		case '*':
			printf("%.2f * %.2f =  %.2f\n", num1, num2, (float)num1 * num2);
			break;
		case '/':
			printf("%.2f / %.2f =  %.2f\n", num1, num2, (float)num1 / num2);
			break;
		default:
			printf("Invalid operation!\n");
	}
	return 0;
}