// Workshop 01 - Thanh Hoang Phan
#include <stdio.h>

int main()
{
	int n, m; 
	printf("Enter the value of n: "); 
	scanf("%d", &n);
	printf("Enter the value of m: ");
	scanf("%d", &m);

	printf("\n%d + %d = %d\n", n, m, n + m);
	printf("%d - %d = %d\n", n, m, n - m);
	printf("%d * %d = %d\n", n, m, n * m);
	printf("%d / %d = %d\n", n, m, n / m);

	printf("\nn is greater than m: %d\n", n > m);

	return 0;
}
