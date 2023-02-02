#include<stdio.h>
#define MAX 50
int main()
{
    int students[MAX] = { 0 };
    int n = 0;
    int i = 0, k = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &k);
        students[i] = k;
    }
//    int* p = NULL;
    for (i = 0; i < n; i++)
    {
      //  p = &students[i];
        int max = 0, * dizhi = NULL;
        for (int j = i; j < n; j++)
        {
            if (students[j] > max)
            {
                max = students[j];
                dizhi = &students[j];
            }
        }
        *dizhi = students[i];
        students[i] = max;
        /*if (*p > max)
        {
            max = *p;
            dizhi = p;
        }
        max = students[i];
        students[i] = *dizhi;
        *dizhi = max;*/
    }
    for (i = 0; i < 5; i++)
    {
        printf("%d", students[i]);
        if (n != 4)
            printf(" ");
    }
    return 0;
}