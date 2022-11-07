#include<stdio.h>
int main()
{
	int i,n = 7;
	double score, sum=0,max=0,min=100;
	for (i = 1; i <= n; i++)
	{
		scanf("%lf", &score);
		sum = sum + score;
		if (score > max)
			max = score;
		if (score < min)
			min = score;
	}
	sum = sum - max - min;
	printf("score=%.2lf", sum / 5);
	return 0;
}