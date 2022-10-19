#include <stdio.h>
#include <math.h>
int main()
{
    int money = 0;
    double year = 0;
    double rate = 0;
    double interest = 0;
    scanf("%d%lf%lf", &money, &year, &rate);
    interest = money * (pow((1 + rate), year)) - money;
    printf("interest = %.2f", interest);
    return 0;
}

