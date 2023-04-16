#include<stdio.h>
void f(float a,float b)
{  
    float c=a;
    for (float c = a; c >= b; c = c / b)
    {
        if (c / b == 1) {
            printf("yes");
            return;
        }
    }
    printf("no");
}
int main()
{   float c1,c2;
    scanf("%f%f", &c1, &c2);
    f(c1, c2);
}