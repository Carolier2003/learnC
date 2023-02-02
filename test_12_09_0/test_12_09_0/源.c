#include<stdio.h>
#define MAXX 10
#define MAXY 10
int main(void)
{
    /*********Begin*********/
    int a[MAXX][MAXY];
    int i, j, m, n, row, col;
    printf("Input m, n:");
    scanf("%d,%d", &m, &n);
    printf("Input %d*%d array:", m, n);
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    row = col = 0;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (a[i][j] > a[row][col])
            {
                row = i;
                col = j;
            }
        }
    }
    printf("max=%d, row=%d, col=%d", a[row][col], row + 1, col + 1);
    /*********End**********/
    return 0;
}