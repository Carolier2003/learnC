#include<stdio.h>
int main(void)
{
	/*********Begin*********/
	int i, j, a[10][10], p, q, m, n, y, z, x = 0, t = 100; //i���У�j���У� 
	scanf("%d%d", &m, &n);
	//������ά���� 
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	}
	for (i = 0; i < m; i++)
	{
		//���ҳ�ÿ������ 
		for (j = 0; j < n; j++)
		{
			if (x < a[i][j])
			{
				x = a[i][j];
				p = i;
				z = j;
				//��ÿ�����ֵ���±������ 
			}
		}
		x = 0;
		//�ж��ǲ���������С�� 
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