#include <stdio.h>
int main()
{
    char  str[100];  //str�������ľ���
    int  i, num = 0;    //num���浥�ʸ���    
    //-------------------���ڴ�������Щ����ĳ���------------------------
    int flag = 0;
    gets(str);
    for (i = 0; str[i] != 0; i++)
    {
        if (str[i] != ' ' && flag == 0)
        {
            num++;
            flag = 1;
        }
        else if (str[i] == ' ')
            flag = 0;
    }
    //-------------------------------------------------------------------

    printf("%d", num);
    return 0;
}
