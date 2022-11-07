#include<stdio.h>
int main()
{
    int i, n, score, count = 0;
    double sum = 0;
    scanf("%d", &n);
    if (n > 0) {
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &score);
            if (score >= 60)
                count++;
            sum = sum + score;
        }
        printf("average = %.1f\ncount = %d", sum / n, count);
    
    }
    else if (n == 0) {
        printf("average = 0.0\n");
        printf("count = 0");
    }

    return 0;
}