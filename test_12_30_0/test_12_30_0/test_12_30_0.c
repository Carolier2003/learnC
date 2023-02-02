// 改错题 输入五个单词，将这五个单词按照字典升序输出。
#include<stdio.h>
#include<string.h>
int main()
{
	char s[5][80], t[80];
	int j, i;
	for (i = 0; i < 5; i++)
		scanf("%s", s[i]);
	/*---------------错误开始区域------------------*/
	/*for (i = 1; i < 5; i+1)
	{
		for (j = 0; j < 5; j++)
			if (s[j] > s[j + 1])
				t = s[j]; s[j] = s[j + 1]; s[j + 1] = t);
	}*/
	//更正后的程序
	for (i = 1; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (strcmp(s[j], s[j + 1]) > 0)
			{
				strcpy(t, s[j]);
				strcpy(s[j], s[j + 1]);
				strcpy(s[j + 1], t);
			}
		}
			
				
	}
	/*---------------错误结束区域------------------*/

	for (i = 0; i < 5; i++)
		printf("%s\n", s[i]);

	return 0;
}