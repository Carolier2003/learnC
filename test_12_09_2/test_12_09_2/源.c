#include<stdio.h>
#define MAXN 1000000
int main(void)
{
    /*********Begin*********/
    int a[MAXN];
    int n, high, low, mid, i;
    scanf("%d", &n);
    for (i = 0; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d", &n);
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == n)
            break;
        else if (n < a[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (low <= high)
        printf("%d", mid + 1);
    else
        printf("None");
    /*********End**********/
    return 0;
}