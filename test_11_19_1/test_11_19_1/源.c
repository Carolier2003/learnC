#include<stdio.h>
int main()
{
	int m, n,number=0;
	scanf("%d%d", &m, &n);
	for (; m <= n; m++) 
	{
		if (m == 1);
		else if (m == 2)
			number++;
		else 
		{
			int i,flag = 1 ;
			for (i = 2; i < m; i++)
			{
				if (m % i == 0)
					flag = 0;
			}
			if (flag)
				number++;
		}
		
	}
	printf("%d", number);
	return 0;
}