//���ַ����г����ַ���ǰ��*��֮�������*��ȫ��ɾ��

#include<stdio.h>
int main()
{
	char str[80];
	//-------------------------�����������򲹳���Ĵ���---------------------
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