#include<stdio.h>
int main()
{	
	int a,n,i,j,x,y=0,p=1,sum = 0;
	scanf("%d%d", &a, &n);
	if (a > 0 && n > 0)
	{
		for (i = 1; i <= n; i++)
		{
			for (j = 1, p = 1; j <= i; j++)
			{
				x = a * p;
				p = p * 10;
				y = y + x;
			}

			sum = sum + y;
			y = 0;
		}
	}
	printf("%d", sum);
	return 0;
}