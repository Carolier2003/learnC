//连接两个字符串。
//要求不能使用编译系统中的string.h
#include<stdio.h>
int main()
{
	char s1[80], s2[80]; //将字符串s2连接到字符串s1的后面

	//---------------------------在以下区域中补充代码-------------------------
	gets(s1);
	gets(s2);
	char *str1 = s1, *str2 = s2;
	while (*str1!='\0')
		str1++;
	while (*str2!='\0')
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 = '\0';//这一步很重要
	//-----------------------------------------------------------------------
	puts(s1);

	return 0;
}