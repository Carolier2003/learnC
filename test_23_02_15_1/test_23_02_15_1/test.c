#include<stdio.h>
int main()
{
	char s[80];
	gets(s);
	int i = 0;
	for (; s[i] == '#'; i++);
	char* p = NULL, * q = NULL;
	p = q = &s[i];

	while (*q!=0)
	{
		if (*q != '#')
		{
			*p = *q;
			p++;
		}
		q++;
	}
	*p = 0;
	puts(s);
	return 0;
 }