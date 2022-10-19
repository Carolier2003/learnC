#include<stdio.h>
double fact(int n);
int main()
{
	int i, n,sum = 0;
	scanf("%d", &n);
	if (n <= 12)
	{
		for (i = 1; i <= n; i++)
			sum = sum + fact(i);
	}
	
	printf("%d", sum);
	return 0;
}
	double fact(int n)
	{
		int i;
		double product;
		product = 1;
		for (i = 1; i <= n; i++)
			product = product * i;
		return product;
	}
