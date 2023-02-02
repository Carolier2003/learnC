#include <stdio.h>
int main()
{
    char  str[100];  //str存放输入的句子
    int  i, num = 0;    //num保存单词个数    
    //-------------------请在此区域内些下你的程序------------------------
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
