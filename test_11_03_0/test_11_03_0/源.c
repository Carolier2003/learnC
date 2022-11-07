#include<stdio.h>
int main() {
	int n, i;
	int score, sum;
	sum = 0;
	i = 0;
	printf("the number of students:");
	scanf_s("%d", &n);
	printf("the scores;");
	
	if (n <= 0)
		printf("average=0");
	else
		while (i < n) {
			scanf_s("%d", &score);
			i++;
			sum = sum + score;
		}
	printf("%d", sum/n);
	return 0;
}
