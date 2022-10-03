#include<stdio.h>
int main() 
{
	int N, fenmu, i;
	double sum, x = 1;
	scanf_s("%d", &N);
	sum = 0, fenmu = 1;
	for (i = 1; i <= N; i++)
	{
		sum = sum + x;
		fenmu = fenmu + 2;
		x = 1.0 / fenmu;
	}
	printf("sum = %.6lf", sum);
	return 0;
}