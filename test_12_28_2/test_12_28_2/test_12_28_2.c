#include<stdio.h>
#define M 3
main()
{
	int a[M], i;
	int* max, * min;
	for (i = 0; i < M; i++)
	{
		scanf("%d", &a[i]);
	}
	/***** ��ָ�����max,min��ʼ�� *****/
   /********** Begin **********/
	max = &a[0];
	min = &a[0];

   /********** End **********/
   /***** ��ÿ������Ԫ��������max,minָ�������Ԫ�رȽϣ�ʹmax,min�ֱ�ָ��������С������Ԫ�� *****/
   /********** Begin **********/
	for (i = 0; i < M; i++)
	{
		if (a[i] > *max)
			max = &a[i];
		if (a[i] < *min)
			min = &a[i];
	}

   /********** End **********/
   /***** ͨ��ָ�����max,min������ֵ����Сֵ *****/
   /********** Begin **********/
	printf("min=%d\n", *min);
	printf("max=%d", *max);

   /********** End **********/
	return 0;
}
