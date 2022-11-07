#include<stdio.h>
int main()
{
	int n,i,s = 1;
	
	scanf("%d", &n);
	if(n>=0)
	{
		for (i = 1; i <= n; i++)
		{
			if (i % 5 == 0)
				s = s * i;
		}
		printf("%d\n", s);
	}
	return 0;
}