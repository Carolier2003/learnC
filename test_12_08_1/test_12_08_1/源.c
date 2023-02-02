#include<stdio.h>
#define MAXN 1000
int main(void)
{
    /*********Begin*********/
    int a[MAXN];
    int n, i, m, index = -1;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);


    for (i = 0; i < n; i++)
    {
        if (a[i] == m)
        {
            index = i + 1; break;
        }
           
    }
    printf("%d", index);
    /*********End**********/
    return 0;
}