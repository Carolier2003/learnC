#include<stdio.h>
int main()
{
	printf("[1] apple\n[2] pear\n[3] orange\n[4] grape\n[0] exit\n");
	int i = 0, choice = 0;
	double price = 0;
	for (i = 1; i <= 5; i++)
	{
		scanf("%d", &choice);
		if (choice == 0) break;
		switch (choice)
		{
		case 1:price = 3.00; break;
		case 2:price = 2.50; break;
		case 3:price = 4.10; break;
		case 4:price = 10.20; break;
		default:price = 0; break;
		}
		printf("price = %.2f\n", price);
	}
	return 0;
}