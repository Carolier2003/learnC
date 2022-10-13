#include<stdio.h>
int main()
{
	int cm = 0, inch = 0, foot = 0;
	scanf_s("%d", &cm);
	foot = cm / 30.48;
	inch = ((cm / 30.48) - foot) * 12;
	printf("%d %d", foot, inch);
	return 0;
}