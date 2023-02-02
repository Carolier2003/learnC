////统计一行字符串中的单词个数。
//#include <stdio.h>
//int main()
//{
//    char  str[100];  //str存放输入的句子
//    int  i, num = 0;    //num保存单词个数
//
//    //-------------------请在此区域内些下你的程序------------------------
//    gets(str);
//    char* pstr = str;
//    while (*pstr)
//    {
//        if (*pstr == ' '&&*(pstr-1)!=' '&&*(pstr-1)!=',' || *pstr == '.' || *pstr == '!' || *pstr == '?')
//            num++;
//        pstr++;
//    }
//    //-------------------------------------------------------------------
//
//    printf("%d", num);
//    return 0;
//}
#include<stdio.h>
int main()
{
    int a = 0;
    int b = 0;
    scanf("%d", &a);
    for (int i = 0; i < 4; i++)
    {
        b = 10 * b + a % 10;
        a = a % 10;
    }
    printf("%d", b);
    return 0;
}