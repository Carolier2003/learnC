#include<stdio.h>
int main()
{
	char a, b, c;
	a = getchar();
	b = getchar();
	c = getchar();
	if (a >= 'e' && a <= 'z' || a >= 'E' && a <= 'Z')
		a = a - 4;
	else if (a >= 'a' && a <= 'd' || a >= 'A' && a <= 'D')
		a = a + 22;

	if (b >= 'e' && b <= 'z' || b >= 'E' && b <= 'Z')
		b = b - 4;
	else if (b >= 'a' && b <= 'd' || b >= 'A' && b <= 'D')
		b = b + 22;

	if (c >= 'e' && c <= 'z' || c >= 'E' && c <= 'Z')
		c = c - 4;
	else if (c >= 'a' && c <= 'd' || c >= 'A' && c <= 'D')
		c = c + 22;
	printf("% c% c%c", a, b, c);
	return 0;
}