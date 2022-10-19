#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#define  EPS  1e-6

int main()
{
    float a, b, c, disc, p, q, x1, x2;
    printf("Please enter a,b,c:");
    scanf("%f,%f,%f", &a, &b, &c);
    if (fabs(a) <= EPS)
    {
        printf("\nIt is not a quadratic equation!\n");
        exit(0);
    }
    disc = b * b - 4 * a * c;
    /*********************Begin*****************/
    if (disc > 0)
    {
        p = -b / (2 * a);
        q = sqrt(disc) / (2 * a);
        x1 = p + q;
        x2 = p - q;
        printf("\nTwo unequal real roots: x1=%.2f,x2=%.2f", x1, x2);
    }
    else if (disc == 0) {
        p = -b / (2 * a);
        x1 = x2 = p;
        printf("\nTwo unequal real roots: x1=x2=%.2f", x1);
    }
    else {
        p = -b / (2 * a);
        disc = fabs(disc);
        q = sqrt(disc) / (2 * a);
        printf("\nTwo complex roots: x1=%.2f+%.2fi,x2=%.2f-%.2fi", p, q, p, q);
    }




    /*********************End*******************/

    return 0;
}


