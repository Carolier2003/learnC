#include<stdio.h>
#include<stdlib.h>
#define MAXL 10000
int main() {
	int L, M, begin, end;
	scanf("%d%d", &L, &M);
	int *arr = (int*)malloc((L + 1) * sizeof(int));
	for (int i = 0; i <= L; i++)
		arr[i] = 0;
	for (int i = 1; i <= M; i++) {
		scanf("%d%d", &begin, &end);
		for (int j = begin; j <= end; j++) {
			arr[j] = 1;
		}
	}
	int count = 0;
	for (int i = 0; i <= L; i++) {
		if (arr[i] == 0)
			count++;
	}
	printf("%d", count);
	return  0;
}