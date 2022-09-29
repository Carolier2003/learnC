#include<stdio.h>
int main()
{
	int lower, upper, fahr;
	double celsius;
	scanf_s("%d%d", &lower, &upper);
	if (lower <= upper)
	{
		printf("fahr celsius\n");
		for (fahr = lower; fahr <= upper; fahr = fahr + 2)
		{
			celsius = 5.0 * (fahr - 32) / 9.0;
			printf("%d%6.1lf\n", fahr, celsius);
		}
	}
	else
		printf("Invalid.");
	return 0;
}
 
