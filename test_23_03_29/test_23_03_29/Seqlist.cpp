/*************************************************************
	date: April 2017
	copyright: Zhu En
	DO NOT distribute this code without my permission.
**************************************************************/
// ˳������ʵ���ļ�
//////////////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include "Seqlist.h"

SeqList* SL_Create(int maxlen)
// ����һ��˳���
// ��SqLst_Free()���
{
	SeqList* slist = (SeqList*)malloc(sizeof(SeqList));
	slist->data = (T*)malloc(sizeof(T) * maxlen);
	slist->max = maxlen;
	slist->len = 0;
	return slist;
}

void SL_Free(SeqList* slist)
// �ͷ�/ɾ�� ˳���
// ��SqLst_Create()���
{
	free(slist->data);
	free(slist);
}

void SL_MakeEmpty(SeqList* slist)
// ��Ϊ�ձ�
{
	slist->len = 0;
}

int SL_Length(SeqList* slist)
// ��ȡ����
{
	return slist->len;
}

bool SL_IsEmpty(SeqList* slist)
// �ж�˳����Ƿ��
{
	return 0 == slist->len;
}

bool SL_IsFull(SeqList* slist)
// �ж�˳����Ƿ���
{
	return slist->len == slist->max;
}

T SL_GetAt(SeqList* slist, int i)
// ��ȡ˳���slist�ĵ�i�Ž������
// ���ص�i�Ž���ֵ
{
	if (i < 0 || i >= slist->len) {
		printf("SL_GetAt(): location error when reading elements of the slist!\n");
		SL_Free(slist);
		exit(0);
	}
	else
		return slist->data[i];
}

void SL_SetAt(SeqList* slist, int i, T x)
// ���õ�i�Ž���ֵ���Ե�i�Ž������ݽ���д��
{
	if (i < 0 || i >= slist->len) {
		printf("SL_SetAt(): location error when setting elements of the slist!\n");
		SL_Free(slist);
		exit(0);
	}
	else
		slist->data[i] = x;
}

bool SL_InsAt(SeqList* slist, int i, T x)
// ��˳����λ��i������x, ����d[i]֮ǰ
// i����Ч��Χ[0,plist->len]
{
	// �������ﲹ����룬��ɱ�������
	/********** Begin *********/
	if (i < 0 || i > slist->len) {
		return false;
	}
	if (slist->len == slist->max) {
		return false;
	}
	for (int j = slist->len; j > i; j--) {
		slist->data[j] = slist->data[j - 1];
	}
	slist->data[i] = x;
	slist->len++;
	return true;
	/********** End **********/
}

T SL_DelAt(SeqList* slist, int i)
// ɾ��˳���splist�ĵ�i�Ž��
// i����Ч��ΧӦ��[0,plist->len)�ڣ����������쳣�����
// ���ر�ɾ��������Ԫ�ص�ֵ��
{
	// �������ﲹ����룬��ɱ�������
	/********** Begin *********/
	int j = 0;
	if (i<0|| i > slist->len)
		return 0;
	for (j = i; j < slist->len-1 ; j++)
		slist->data[j] = slist->data[j + 1];
	slist->len--;
	return 1;
	/********** End **********/
}

int SL_FindValue(SeqList* slist, T x)
// ��˳�����в��ҵ�һ��ֵΪx�Ľ�㣬���ؽ��ı��
// ����ֵ���ڵ���0ʱ��ʾ�ҵ�ֵΪx�Ľ��ı�ţ�-1��ʾû���ҵ�
{
	int i = 0;
	while (i < slist->len && slist->data[i] != x) i++;
	if (i < slist->len) return i;
	else return -1;
}

int SL_DelValue(SeqList* slist, T x)
// �����Ա���ɾ����һ��ֵΪx�Ľ��,
// ����ֵΪx�Ľ���򷵻ؽ����, δ�ҵ����أ�1
{
	// �������ﲹ����룬��ɱ�������
	/********** Begin *********/
	int j = 0;
	for (j = 0; j < slist->len; j++) {
		if (x == slist->data[j]) {
			for (int k = j; k < slist->len - 1; k++)
				slist->data[k] = slist->data[k + 1];
			slist->len--;
			return 0;
		}
	}
	return -1;
	/********** End **********/
}

void SL_Print(SeqList* slist)
// ��ӡ����˳���
{
	if (slist->len == 0) {
		printf("The slist is empty.\n");
		return;
	}

	//printf("The slist contains: ");
	for (int i = 0; i < slist->len; i++) {
		printf("%d  ", slist->data[i]);
	}

	printf("\n");

}