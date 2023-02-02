#include<stdio.h>
#define MAXN 10
int main()
{
	int a[MAXN];
	int i,k,index,exchange;

	for (i = 0; i < MAXN; i++)
		scanf("%d", &a[i]);
		for (k = 0; k < MAXN; k++)
		{
			index = k;
			for (i = k + 1; i < MAXN; i++)
			{
				if (a[i] < a[index])
					index = i;
			}
			exchange = a[k];
			a[k] = a[index];
			a[index] = exchange;
		}
	for (i = 0; i < MAXN; i++)
		printf("%d ", a[i]);
	return 0;
}