#include<stdio.h>
int main()
{
	int n, i, r, sum = 0, fact = 1; 
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		for (fact=1,r = 1; r <= i; r++)
			fact = fact * r;
		sum = sum + fact;
	}
	printf("%d", sum);
	return 0;
}