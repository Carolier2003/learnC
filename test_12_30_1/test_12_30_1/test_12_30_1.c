//�ж�һ���ַ����Ƿ�����ַ�����

#include<stdio.h>
#include<string.h>
int main()
{
	char str[80] = { 0 };
	char* p = 0, * q = 0  ;//ָ���ʼ��
	int flag = 1;
	gets(str);
	p = str;
	q = str;
	q += strlen(str) - 1;//qָ�����һ��Ԫ��
	while (p<q)
	{
		if (*q!=*p)//�ж��Ƿ����
		{
			flag = 0;
			break;
		}
		p++;
		q--;//ָ����ƶ�
	}

	if (flag == 1)//�жϽ���������
		printf("Yes");
	else
		printf("No");

	return 0;
}