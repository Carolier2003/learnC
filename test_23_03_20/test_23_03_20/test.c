#include<stdio.h>
/*********Begin*********/
struct student {
	double number;
	char name[20];
	int score;
}s1, s2;

int main() {
	scanf("%lf %s %d", &s1.number, &s1.name, &s1.score);
	scanf("%lf %s %d", &s2.number, &s2.name, &s2.score);
	if (s1.score > s2.score)
		printf("%.0f %s %d", s1.number, s1.name, s1.score);
	else
		printf("%.0f %s %d", s2.number, s2.name, s2.score);
}
/*********End*********/