#include <stdio.h>
#include <math.h>

int IsPrimeNumber(int number);
int main(void)
{
	int n, ret;  // ret用于存放调用函数的返回值
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

//函数功能：判断number是否是素数，是素数则函数返回1，不是素数返回值为0 
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
