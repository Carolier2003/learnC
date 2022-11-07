#include<stdio.h>
int main()
{
	int a = 0, b = 0, c = 0, d = 0;
	char x;
	while ((x = getchar()) != '\n') 
	{
		if (x >= 'a' && x <= 'z' || x >= 'A' && x <= 'Z')
			a++;
		else if (x == ' ')
			b++;
		else if (x >= '0' && x <= '9')
			c++;
		else d++;
	}
	printf("%d %d %d %d", a,b,c,d);
	return 0;
}