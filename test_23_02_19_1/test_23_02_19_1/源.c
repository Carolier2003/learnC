#include<stdio.h>
#define MAXN 20
int main()
{
	int n = 0, m = 0, i = 0, j = 0, k = 0;
	int a[MAXN] = { 0 }, b[MAXN] = { 0 }, c[MAXN] = { 0 };
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d", &b[i]);
	}
	for (i = 0; i < n; i++)
	{
		int flag = 0;
		for (j = 0; j < m; j++)
		{
			if (a[i] == b[j])
				flag = 1;
		}
		if (flag == 0)
			c[k++] = a[i];
	}
	for (i = 0; i < m; i++)
	{
		int flag = 0;
		for (j = 0; j < n; j++)
		{
			if (b[i] == a[j])
				flag = 1;
		}
		if (flag == 0)
			c[k++] = b[i];
	}
	printf("%d", c[0]);
	for (i = 1; i < k; i++)
	{
		int flag = 0;
		for (j = 0 ; j < k; j++)
		{
			if (c[i] == c[j])
				flag = 1;
		}
		if (flag == 0)
			printf(" %d", c[i]);
	}
	return 0;
}