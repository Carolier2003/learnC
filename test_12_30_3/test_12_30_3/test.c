////ͳ��һ���ַ����еĵ��ʸ�����
//#include <stdio.h>
//int main()
//{
//    char  str[100];  //str�������ľ���
//    int  i, num = 0;    //num���浥�ʸ���
//
//    //-------------------���ڴ�������Щ����ĳ���------------------------
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