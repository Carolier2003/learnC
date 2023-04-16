#include<stdio.h>
#define MAX 80
int main()
{
    char ch[80];
    gets(ch);
    char* p = ch;
    while (*p != 0)
    {
        if (*p >= 'a' && *p < 'z')
            *p = *p + 1;
        else if (*p == 'z')
            *p = *p - 25;
        else if (*p >= 'A' && *p < 'Z')
            *p = *p + 1;
        else if (*p == 'Z')
            *p = *p - 25;
        p++;
    }
    puts(ch);
    return 0;
}