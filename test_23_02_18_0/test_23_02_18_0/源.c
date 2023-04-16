#include<stdio.h>
#define MAXN 10
int main()
{
    int n = 0;
    int a[MAXN] = { 0 };
    scanf("%d", &n);
    int i = 0;
    for (i = 0; i < n; i++)
    {
        int shuju = 0;
        scanf("%d", &shuju);
        a[i] = shuju;
    }
    i--;
    while (i != -1)
    {
        printf("%d", a[i]);
        i--;
        if (i != -1)
            printf(" ");
    }
    return 0;
}