#include<stdio.h>

int main()
{
	int n = 0,k = 1;
	scanf("%d", &n);
	if (n < 0)
	{
		n = -n;
	}
	else if (n == 0)
	{
		printf("0");
	}
	else
	{
		int t = n;

		do
		{
			k *= 10;
			t /= 10;
		} while (t >= 9);

		while (k)
		{
			printf("%d ", n / k);
			n = n % k;
			k /= 10;
		}
	}
	
	return 0;
}