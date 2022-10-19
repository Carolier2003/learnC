#include <stdio.h>

int main(void)
{
    float  h, w, t;
    printf("Please enter h,w:");
    scanf("%f, %f", &h, &w);
    /*********begin**********/
    t = w / (h * h);
    if (t < 18)
        printf("t=%f\tLower weight!",t);
    else if (t < 25)
        printf("t=%f\tStandard weight!",t);
    else if (t < 27)
        printf("t=%f\tHigher weight!",t);
    else
        printf("t=%f\tToo fat!",t);


        /**********end***********/
        return 0;
}
