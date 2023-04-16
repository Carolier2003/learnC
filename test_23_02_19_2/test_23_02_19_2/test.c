#include<stdio.h>
#define MAXN 10
#define MAXM 10
int main()
{
	int a[MAXN][MAXM] = { 0 };
	int i = 0, j = 0;
	int n = 0, sum = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
			sum += a[i][j];
		}
	}
	if (n == 2)
	{
		sum = sum - a[0][1]  - a[1][0]  - a[1][1];
	}
	else
	{
		for (i = 0; i < n; i++)
		{
			j = n - 1;
			sum = sum - a[i][j];
			j--;
		}
		for (i = 0; i < n; i++)
		{
			sum = sum - a[i][n - 1];
		}
		for (j = 0; j < n; j++)
		{
			sum = sum - a[n - 1][j];
		}
		sum = sum + a[0][n - 1] + a[n - 1][0] + a[n - 1][n - 1];
	}

	printf("%d", sum);
	return 0;
}