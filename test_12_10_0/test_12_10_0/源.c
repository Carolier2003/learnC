#include<stdio.h>
int main(void)
{
	/*********Begin*********/
	int i, j, a[10][10], p, q, m, n, y, z, x = 0, t = 100; //i是行，j是列； 
	scanf("%d%d", &m, &n);
	//遍历二维数组 
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	}
	for (i = 0; i < m; i++)
	{
		//先找出每行最大的 
		for (j = 0; j < n; j++)
		{
			if (x < a[i][j])
			{
				x = a[i][j];
				p = i;
				z = j;
				//把每行最大值的下标存起来 
			}
		}
		x = 0;
		//判断是不是这列最小的 
		for (q = 0; q < m; q++)
		{
			if (t > a[q][z])
			{
				t = a[q][z];
				y = q;
			}
		}
		t = 100;
		if (p == y)
		{
			printf("Array[%d][%d]=%d", p, z, a[p][z]);
			return 0;
		}

	}
	/*********End**********/

}