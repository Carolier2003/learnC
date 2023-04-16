#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n = 0, m = 0;
	scanf("%d%d", &n, &m);
	int t = n;
	int* arr1 = (int*)malloc(n * sizeof(int));
	int* arr2 = (int*)malloc(n * sizeof(int));
	for (int i = 1; i <= n; i++) {
		arr1[i-1] = i;
		arr2[i-1] = 1;
	}
	while (n != 1) {
		int x;
		if (n > m) {
			x = m;
		}
		else if (n < m)
		{
			x = m % n;
		}
		else
			x = n;
		for (int i = 0,count = 0; i <= t; i++) {
			if (count == x) {
				arr2[i-1] = 0;
				break;
			}
			if(arr2[i]!= 0) 
				count++;
		}
		n -= 1;
	}
	for (int i = 0; i < n; i++) {
		if (arr2[i] == 1)
			printf("%d", arr1[i]);
	}
}