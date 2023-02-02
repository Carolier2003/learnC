#include<stdio.h>
int main()
{
	int m, n, i, count=0;
	scanf("%d%d", &m, &n);
	for (i = 1; i <= m; i++) 
	{
		int p = i;
		do {
			int x = p % 10;
			if (x == n)
				count++;

			p /= 10;
		} while (p);
	}
	printf("%d", count);
	return 0;
}