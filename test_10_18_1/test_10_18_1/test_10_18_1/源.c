# include<stdio.h>
int main()
{
    int a,denominator,N,i,flag;
    double item, sum;
    scanf("%d",& N);
    a = 1;
    denominator = 1;
    flag = 1;
    sum = 0;
    item = 1;
    for (i = 1; i <= N; i++) {
        sum = sum + item;
        flag = -flag;
        denominator = denominator + 2;
            a = a + 1;
        item = 1.0*(flag * a) / denominator;
    }
    printf("%.31f",sum );
        return 0;
}
