#include<stdio.h>
int main(void)
{
	int m, n, x, y, p, q = 0, max, i;
	scanf("%d%d", &m, &n);
	if (m > n)
		max = m;
	else
		max = n;
	for (i = 1; i <= max; i++)
	{
		if (m % i == 0)
			x = i;
		if (n % i == 0)
			y = i;
		if (x == y)
			p = x;
	}
	q = m * n/p;
	printf("���Լ����:%d",p);
	printf("\n��С��������:%d",q);
	return 0;
}