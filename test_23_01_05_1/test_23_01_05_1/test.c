//#include<stdio.h>
//int main()
//{
//	int a=0, b=0, c=0;
//	scanf("%d %d %d", &a, &b, &c);
//	int s = 0;
//	if (a > b);
//	else
//	{
//		s = a; a = b; b = s;
//	}
//	if (a > c)
//	{
//		if (b > c);
//		else
//		{
//			s = b; b = c; c = s;
//		}
//	}
//	else
//	{
//		s = a; a = c; c = b; b = s;
//	}
//	printf("%d->%d->%d", c, b, a);
//	return 0;
//}
#include<stdio.h>
int main()
{
    int a = 0;
    int b = 0;
    scanf("%d", &a);
    for (int i = 0; i < 4; i++)
    {
        b = 10 * b + a % 10;
        a = a % 10;
    }
    printf("%d", b);
    return 0;
}