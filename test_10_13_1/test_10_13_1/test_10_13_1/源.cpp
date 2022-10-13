#include<stdio.h>
int main()
{
	int i, N,  demo = 1, numer = 1,fahr = 1;
	double x,sum = 0;
	scanf_s("%d", &N);
	for (i = 1; i <= N; i++) 
	{
		x = 1.0*fahr * numer / demo;
		sum = sum + x;
		numer++;
		demo = demo + 2;
		fahr = -fahr;
	}
	printf("%.3lf", sum);
	return 0;
}