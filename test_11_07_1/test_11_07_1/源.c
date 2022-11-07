#include<stdio.h>
int main()
{
    int i, letter = 0, blank = 0, digit = 0, other = 0;
    char c;
    for (i = 1; i <= 10; i++)
    {
        c = getchar();
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
            letter++;
        else if (c == ' ' || c == '\n')
            blank++;
        else if (c >= '0' && c <= '9')
            digit++;
        else
            other++;
    }
    printf("letter = %d, blank = %d, digit = %d,other = %d", letter, blank, digit, other); 
            return 0;
}