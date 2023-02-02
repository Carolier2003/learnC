//将字符串中除了字符串前导*号之外的其它*号全部删除

#include<stdio.h>
int main()
{
	char str[80];
	//-------------------------请在以下区域补充你的代码---------------------
	gets(str);
	int flag = 0;
	char* pstr = str;
	while (*pstr)
	{
		if (*pstr >= 'a' && *pstr <= 'z' || *pstr>='A' && *pstr <= 'Z')
			flag = 1;
		if (flag == 1)
		{
			if (*pstr == '*')
			{
				int i = 1;
				for (;; i++)
				{
					if (*(pstr + i) != '*')
					{
						*pstr = *(pstr + i);
						*(pstr + i) = '*';
						break;
					}
				}
			}
		}
		pstr++;
		if (*(pstr - 1) == '\0')
			break;
	}
	//----------------------------------------------------------------------
	puts(str);

	return 0;
}