#include<stdio.h>
int main(void)
{
    /*********Begin*********/
    int arr[10];
    int m, i;
    m = 10;
    for (i = 0; i < m; i++)
    {
        scanf("%d", &arr[i]);
    }
    int row = 0;
    for (i = 0; i < m; i++)
    {
        if (arr[i] > arr[row])
        {
            row = i;
        }
    }
    for (; row < m; row++)
    {
        arr[row] = arr[row + 1];
    }
    for (i = 0; i < 9; i++)
    {
        printf("%d ", arr[i]);
    }
    /*********End**********/
    return 0;
}