//判断一个字符串是否回文字符串。

#include<stdio.h>
#include<string.h>
int main()
{
	char str[80] = { 0 };
	char* p = 0, * q = 0  ;//指针初始化
	int flag = 1;
	gets(str);
	p = str;
	q = str;
	q += strlen(str) - 1;//q指向最后一个元素
	while (p<q)
	{
		if (*q!=*p)//判断是否相等
		{
			flag = 0;
			break;
		}
		p++;
		q--;//指针的移动
	}

	if (flag == 1)//判断结束的类型
		printf("Yes");
	else
		printf("No");

	return 0;
}