#include <stdio.h>
#include <math.h>

int IsPrimeNumber(int number);
int main(void)
{
	int n, ret;  // ret���ڴ�ŵ��ú����ķ���ֵ
	printf("Input a positive integer,a:\n");
	scanf("%d", &n);
	/************Begin************/
	ret = IsPrimeNumber(n);
	if (ret)
		printf("%d is a prime number", n);
	else
		printf("%d is not a prime number", n);
	/************End************/
	return 0;
}

//�������ܣ��ж�number�Ƿ�����������������������1��������������ֵΪ0 
int IsPrimeNumber(int number)
{
	/************Begin************/
	int i;
	if (number == 1 || number == 0)
		return 0;
	else if (number == 2)
		return 1;
	else if (number < 0)
		return 0;
	else 
	{
		for (i = 2; i < number; i++) 
		{
			if (number % i == 0)
				return 0;
		}
		return 1;
	}
	/************End************/

}
