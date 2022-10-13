#include<stdio.h>
#include<math.h>
int main() 
{
	double sum = 0;
	int i, N;
	scanf_s("%d", &N);
	for (i = 1; i <= N; i++)
	{
		sum = sum + sqrt(i);
	}
	printf("sum = %.2lf", sum);
	return 0;
}