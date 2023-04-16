#include <stdio.h>
#include <malloc.h>
typedef char ElemType;
typedef struct LNode	//���嵥����������
{
	ElemType data;
	struct LNode* next;
} LinkList;
void InitList(LinkList*& L)		//��ʼ�����Ա�
{
	L = (LinkList*)malloc(sizeof(LinkList));  	//����ͷ���
	L->next = NULL;
}
void DestroyList(LinkList*& L)	//�������Ա�
{
	LinkList* p = L, * q = p->next;
	while (q != NULL)
	{
		free(p);
		p = q;
		q = p->next;
	}
	free(p);
}
bool ListEmpty(LinkList* L)	//�����Ա��Ƿ�Ϊ�ձ�
{
	return(L->next == NULL);
}
int ListLength(LinkList* L)	//�����Ա�ĳ���
{
	LinkList* p = L; int i = 0;
	while (p->next != NULL)
	{
		i++;
		p = p->next;
	}
	return(i);
}
void DispList(LinkList* L)	//������Ա�
{
	LinkList* p = L->next;
	while (p != NULL)
	{
		printf("%c ", p->data);
		p = p->next;
	}
	printf("\n");
}
bool GetElem(LinkList* L, int i, ElemType& e)	//�����Ա���ĳ������Ԫ��ֵ
{
	int j = 0;
	LinkList* p = L;			//pָ��ͷ�ڵ�,j��Ϊ0(��ͷ�ڵ�����Ϊ0)
	while (j < i && p != NULL)	//�ҵ�i���ڵ�
	{
		j++;
		p = p->next;
	}
	if (p == NULL)			//�����ڵ�i�����ݽڵ�,����0
		return false;
	else					//���ڵ�i�����ݽڵ�,����1
	{
		e = p->data;
		return true;
	}
}
int LocateElem(LinkList* L, ElemType e)	//��Ԫ��ֵ����
{
	int i = 1;
	LinkList* p = L->next;		//pָ��ʼ�ڵ�,i��Ϊ1(����ʼ�ڵ�����Ϊ1)
	while (p != NULL && p->data != e)	//����dataֵΪe�Ľڵ�,�����Ϊi
	{
		p = p->next;
		i++;
	}
	if (p == NULL)				//������Ԫ��ֵΪe�Ľڵ�,����0
		return(0);
	else						//����Ԫ��ֵΪe�Ľڵ�,�������߼����i
		return(i);
}
bool ListInsert(LinkList*& L, int i, ElemType e)	//��������Ԫ��
{
	int j = 0;
	LinkList* p = L, * s;			//pָ��ͷ�ڵ�,j��Ϊ0(��ͷ�ڵ�����Ϊ0)
	while (j < i - 1 && p != NULL)	//���ҵ�i-1���ڵ�
	{
		j++;
		p = p->next;
	}
	if (p == NULL)			//δ�ҵ���i-1���ڵ�,����false
		return false;
	else					//�ҵ���i-1���ڵ�*p,�����½ڵ㲢����1
	{
		s = (LinkList*)malloc(sizeof(LinkList));
		s->data = e;			//�����½ڵ�*s,��data����Ϊe
		s->next = p->next;	//��*s���뵽*p֮��
		p->next = s;
		return true;
	}
}
bool ListDelete(LinkList*& L, int i, ElemType& e)	//ɾ������Ԫ��
{
	int j = 0;
	LinkList* p = L, * q;			//pָ��ͷ�ڵ�,j��Ϊ0(��ͷ�ڵ�����Ϊ0)
	while (j < i - 1 && p != NULL)	//���ҵ�i-1���ڵ�
	{
		j++;
		p = p->next;
	}
	if (p == NULL)				//δ�ҵ���i-1���ڵ�,����false
		return false;
	else						//�ҵ���i-1���ڵ�*p
	{
		q = p->next;				//qָ���i���ڵ�
		if (q == NULL)			//�������ڵ�i���ڵ�,����false
			return false;
		e = q->data;
		p->next = q->next;		//�ӵ�������ɾ��*q�ڵ�
		free(q);				//�ͷ�*q�ڵ�
		return true;			//����true��ʾ�ɹ�ɾ����i���ڵ�
	}
}
int main()
{
	LinkList* h;
	ElemType e;
	printf("������Ļ�����������:\n");
	printf("  (1)��ʼ��������h\n");
	InitList(h);
	printf("  (2)���β���β�巨����a,b,c,d,eԪ��\n");
	ListInsert(h, 1, 'a');
	ListInsert(h, 2, 'b');
	ListInsert(h, 3, 'c');
	ListInsert(h, 4, 'd');
	ListInsert(h, 5, 'e');
	printf("  (3)���������h:");
	DispList(h);
	printf("  (4)������h����=%d\n", ListLength(h));
	printf("  (5)������hΪ%s\n", (ListEmpty(h) ? "��" : "�ǿ�"));
	GetElem(h, 3, e);
	printf("  (6)������h�ĵ�3��Ԫ��=%c\n", e);
	printf("  (7)Ԫ��a��λ��=%d\n", LocateElem(h, 'a'));
	printf("  (8)�ڵ�4��Ԫ��λ���ϲ���fԪ��\n");
	ListInsert(h, 4, 'f');
	printf("  (9)���������h:");
	DispList(h);
	printf("  (10)ɾ��h�ĵ�3��Ԫ��\n");
	ListDelete(h, 3, e);
	printf("  (11)���������h:");
	DispList(h);
	printf("  (12)�ͷŵ�����h\n");
	DestroyList(h);
	return 0;
}
