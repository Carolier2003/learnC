#include<stdio.h>
int main()
{
    int m, n, i;
    double s = 0,x = 0;
    scanf_s("%d%d",&m,&n);
    if (m <= n)
    {
        for (i = m; i <= n; i++)
        {
            x = i * i + 1.0 / i;
            s = s + x;
        }
    }
    printf ("sum = %.6lf",s);
    return 0;
}