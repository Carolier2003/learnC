#include<iostream>
using namespace std;
int main()
{
	int i, a;
	double sum;
	scanf_s("%d", &a);
	for (sum = 0, i = 1; i <= a; i++){
		sum = sum + 1.0 / i;
	}
	printf("sum=%lf", sum);
	return 0;
}