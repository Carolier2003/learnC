#include<stdio.h>
int main()
{
	int denominator, flag, i, n;
	double item, sum;
	scanf_s("%d", &n);
	flag = 1;
	denominator = 1;
	item = 1;
	sum = 0;
	for (i = 1; i <= n; i++) 
	{
		sum = sum + item;
		flag = -flag;
		denominator = denominator + 2;
		item = flag * 1.0 / denominator;
	}
	printf("sum = %lf\n", sum);
	return 0;
}