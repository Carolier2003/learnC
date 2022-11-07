#include<stdio.h>
int main()
{
    int n, i, count = 0;
    double cj, sum = 0;
    scanf("%d", &n);
    if (n == 0) {
        printf("average = 0.0\n");
        printf("count = 0\n");
    }
    else if (n != 0)
    {
        for (i = 1; i <= n; i++)
        {
            scanf("%lf", &cj);
            if (cj >= 60) {
                count++;
            }
            sum += cj;
        }
    }
    printf("average = %.1lf\n", sum);
    printf("count= %d\n", count);
    return 0;
}