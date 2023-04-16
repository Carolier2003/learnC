#include<stdio.h>
#include<malloc.h>
#include<cstring>
#define MaxSize 50
typedef char ElemType;
typedef struct 
{
	ElemType data[MaxSize];//���˳����е�Ԫ��
	int length;//���˳���ĳ���
}SqList;//����˳��������
void CreateList(SqList*& L, ElemType a[], int n) 
{
	L = (SqList*)malloc(sizeof(SqList));
	for (int i = 0; i < n; i++) {
		L->data[i] = a[i];
	}
	L->length = n;
}//���彨��˳���
void InitList(SqList*& L) 
{
	L = (SqList*)malloc(sizeof(SqList));//���������Ա�Ŀռ�
	L->length = 0;
}//��ʼ�����Ա�
void DestroyList(SqList*& L) 
{
	free(L);
}//�������Ա�
bool ListEmpty(SqList* L) //�ж����Ա��Ƿ�Ϊ�ձ�
{
	return(L->length == 0);
}
int ListLength(SqList* L) //�����Ա�ĳ���
{
	return(L->length);
}
void DispList(SqList* L)//������Ա�
{
	for (int i = 0; i < L->length; i++)
		printf("%c", L->data[i]);
	printf("\n");
}
bool GetElem(SqList* L, int i, ElemType& e)//�����Ա��е�i��Ԫ�ص�ֵ
{
	if (i < 1 || i > L->length)
		return false;
	e = L->data[i - 1];
	return true;
}
int LocateElem(SqList* L, ElemType e) //���ҵ�һ��ֵ��Ϊe��Ԫ�ص����
{
	int i = 0;
	while (i < L->length && L->data[i] != e)
		i++;
	if (i >= L->length)
		return 0;
	else
		return i + i;
}
bool ListInsert(SqList*& L, int i, ElemType e)//�����i��Ԫ��
{
	int j;
	if (i<1 || i>L->length + 1 || L->length == MaxSize)
		return false;
	i--;//��˳����λ��ת��Ϊdata���±�
	for (j = L->length; j > i; j--)//��data[i]�������Ԫ�غ���һ��λ��
		L->data[j] = L->data[j - 1];
	L->data[i] = e;
	L->length++;//˳���ĳ�������
	return true;
}
bool ListDelete(SqList*& L, int i, ElemType& e)//ɾ����i��Ԫ��
{
	int j;
	if (i<1 || i>L->length)
		return false;
	i--;//��˳����Ϊ��ת��Ϊdata���±�
	e = L->length;
	for (j = i; j < L->length - 1; j++)//��data[i]֮���Ԫ����ǰ�ƶ�һ��λ��
		L->data[j] = L->data[j + 1];
	L->length--;//˳���ĳ��ȼ�
	return true;
}

int main()
{
    //��1������˳���
    //������һ���ַ�����a�������10��Ԫ��
    ElemType a[10] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
    //����һ��ָ��˳����ָ��L
    SqList* L;
    //����CreateList����������a��10��Ϊ���������L��Ϊ�������
    CreateList(L, a, 10);
    //��ӡ˳����е�Ԫ��
    DispList(L);

    //��2��˳����е�Ԫ�ز���
    //����һ����ʾ������Ԫ��ֵ�ı���e
    ElemType e;
    //��e��ֵΪ'g'
    e = 'g';
    //����һ����ʾ���ҽ���ı���i
    int i;
    //����LocateElem����������L��e��Ϊ���������i��Ϊ�������
    i = LocateElem(L, e);
    //�жϲ��ҽ���Ƿ�Ϊ0
    if (i == 0)
        printf("û���ҵ�Ԫ��%c\n", e);
    else
        printf("�ҵ���Ԫ��%c������˳����е�λ����%d\n", e, i);

    //��3��˳�����Ԫ�صĲ����ɾ��
    //����һ����ʾ����λ�õ�����i
    i = 5;
    //����һ����ʾ����ֵ�ı���e
    e = 'k';
    //����һ����ʾ�������ı���b
    bool b;
    //����ListInsert����������L��i��e��Ϊ���������b��Ϊ�������
    b = ListInsert(L, i, e);
    //�жϲ������Ƿ�Ϊtrue
    if (b)
        printf("��˳����е�%d��λ�ò�����Ԫ��%c\n", i, e);
    else
        printf("����ʧ��\n");

    //��ӡ˳����е�Ԫ��
    DispList(L);

    //��i��ֵΪ8
    i = 8;
    //����ListDelete����������L��i��Ϊ���������e��b��Ϊ�������
    b = ListDelete(L, i, e);
    //�ж�ɾ������Ƿ�Ϊtrue
    if (b)
        printf("ɾ����˳����е�%d��λ�õ�Ԫ��%c\n", i, e);
    else
        printf("ɾ��ʧ��\n");

    //��ӡ˳����е�Ԫ��
    DispList(L);
}
