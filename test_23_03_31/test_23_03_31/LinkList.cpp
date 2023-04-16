/*************************************************************
    date: June 2017
    copyright: Zhu En
    DO NOT distribute this code without my permission.
**************************************************************/
// ������ʵ���ļ�

#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// 1��
LinkList* LL_Create()
// ����һ�����Ӵ洢�����Ա���ʼΪ�ձ�����llistָ�롣
{
    LinkList* llist=(LinkList*)malloc(sizeof(LinkList));
    llist->front=NULL;
    llist->rear=NULL;
    llist->pre=NULL;
    llist->curr=NULL;
    llist->position=0;
    llist->len=0;
    return llist;
}

// 2��	
void LL_Free(LinkList* llist)
// �ͷ�����Ľ�㣬Ȼ���ͷ�llist��ָ��Ľṹ��
{
    LinkNode* node=llist->front;
    LinkNode* nextnode;
    while(node){
        nextnode=node->next;
        free(node);
        node=nextnode;
    }
    free(llist);
}

// 3��	
void LL_MakeEmpty(LinkList* llist)
// ����ǰ���Ա��Ϊһ���ձ������Ҫ�ͷ����н�㡣
{
    LinkNode* node=llist->front;
    LinkNode* nextnode;
    while(node){
        nextnode=node->next;
        free(node);
        node=nextnode;
    }
    llist->front=NULL;
    llist->rear=NULL;
    llist->pre=NULL;
    llist->curr=NULL;
    llist->position=0;
    llist->len=0;
}

// 4��	
int LL_Length(LinkList* llist)
// �������Ա�ĵ�ǰ���ȡ�
{
    return llist->len;
}

// 5��	
bool LL_IsEmpty(LinkList* llist)
// ����ǰ���Ա��ǿձ��򷵻�true�����򷵻�TRUE��
{
    return llist->len==0;
}

// 6��  
bool LL_SetPosition(LinkList* llist, int i)
// �������Ա�ĵ�ǰλ��Ϊi��λ�á�
// ���óɹ����򷵻�true�����򷵻�false�����Ա�Ϊ�գ���i������Ч�ķ��أ�
// �������Ա�ǰ����Ϊlen����ôi����Ч��ΧΪ[0,len]
{	
    int k;
    /* ������Ϊ�գ��򷵻�*/
    if (llist->len==0) return false;

    /*��λ��Խ��*/
    if( i < 0 || i > llist->len)
    {	printf("LL_SetPosition(): position error");
        return false;
    }

    /* Ѱ�Ҷ�Ӧ���*/
    llist->curr = llist->front;
    llist->pre = NULL;
    llist->position = 0;
    for ( k = 0; k < i; k++)	{
        llist->position++;
        llist->pre = llist->curr;
        llist->curr = (llist->curr)->next;
    }
    
    /* ���ص�ǰ���λ��*/
    return true;
}

// 7)	
int LL_GetPosition(LinkList* llist)
// ��ȡ���Ա�ĵ�ǰλ�ý��ı��
{
    return llist->position;
}

// 8��	
bool LL_NextPosition(LinkList* llist)
// �������Ա�ĵ�ǰλ�õ���һ��λ��Ϊ��ǰλ�á�
// ���óɹ����򷵻�true�����򷵻�false�����Ա�Ϊ�գ���ǰλ��Ϊ��β��
{
    if (llist->position >= 0 && llist->position < llist->len)
    /* ����ǰ�����ڣ������̽������Ϊ��ǰ���*/
    {
        llist->position++;
        llist->pre = llist->curr;
        llist->curr = llist->curr->next;
        return true;
    }
    else 
        return false;
}

// 9��	
T LL_GetAt(LinkList* llist)
// �������Ա�ĵ�ǰλ�õ�����Ԫ�ص�ֵ��
{
    if(llist->curr==NULL)
    {
        printf("LL_GetAt(): Empty list, or End of the List.\n");
        LL_Free(llist);
        exit(1);
	}
    return llist->curr->data;
}

// 10��	
void LL_SetAt(LinkList* llist, T x)
// �����Ա�ĵ�ǰλ�õ�����Ԫ�ص�ֵ�޸�Ϊx��
{
    if(llist->curr==NULL)
    {
        printf("LL_SetAt(): Empty list, or End of the List.\n");
        LL_Free(llist);
        exit(1);
    }
    llist->curr->data=x;
}

// 11��	
bool LL_InsAt(LinkList* llist, T x)
// �����Ա�ĵ�ǰλ��֮ǰ��������Ԫ��x����ǰλ��ָ��ָ��������Ԫ�ؽ�㡣
// ������ʧ�ܣ�����false�����򷵻�true��
{	
    LinkNode *newNode=(LinkNode*)malloc(sizeof(LinkNode));
    if (newNode==NULL) return false;

    newNode->data=x;

    if (llist->len==0){
        /* �ڿձ��в���*/
        newNode->next=NULL;
        llist->front = llist->rear = newNode;
	}
    //��ǰλ��Ϊ��ͷ
    else if (llist->pre==NULL)
    {
        /* �ڱ�ͷ��㴦����*/
        newNode->next = llist->front;
        llist->front = newNode;
    }
    else {  
        /* ��������м�λ�û��β���λ�ò���*/
        newNode->next = llist->curr;
        llist->pre->next=newNode;
    }
    //�����ڱ�β��
    if (llist->pre==llist->rear)
        llist->rear=newNode;
    /* ��������Ĵ�С*/
    llist->len++;
    /* �²���Ľ��Ϊ��ǰ���*/
    llist->curr = newNode;
    return true;
}

// 12��	
bool LL_InsAfter(LinkList* llist, T x)
// �����Ա�ĵ�ǰλ��֮���������Ԫ��x���ձ�������롣��ǰλ��ָ�뽫ָ���½�㡣
// ������ʧ�ܣ�����false�����򷵻�true��
{
    // �������ﲹ����룬��ɱ�������
    /********** Begin *********/
    // ����һ���½�㣬������Ϊx
    LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode)); // Ϊ�½������ڴ�ռ�
    if (newNode == NULL) return false; // �������ʧ�ܣ�����false
    newNode->data = x; // ��x��ֵ���½���������
    if (llist->len == 0) /*�ڿձ��в���*/
    {
        newNode->next = NULL; // �½��ĺ��ָ��ָ��NULL
        llist->front = llist->rear = newNode; // ͷ����β��㶼ָ���½��
    }
    else if (llist->curr == llist->rear || llist->curr == NULL) /*��β��㴦����*/
    {
        newNode->next = llist->curr->next; // �½��ĺ��ָ��ָ��NULL
        llist->curr->next = newNode; // ԭ����β���ĺ��ָ��ָ���½��
        llist->pre = llist->curr; // ǰ��ָ��ָ��ԭ����β���
        llist->position++; // λ�ü�һ
    }
    else /*��������м�λ�ò���*/
    {
        newNode->next = llist->curr->next; // �½��ĺ��ָ��ָ��ԭ����ǰλ��֮��Ľ��
        llist->curr->next = newNode; // ԭ����ǰλ�õĺ��ָ��ָ���½��
        llist->pre = llist->curr; // ǰ��ָ��ָ��ԭ���ĵ�ǰλ��
        llist->position++; // λ�ü�һ
    }
    /*��������Ĵ�С*/
    llist->len++;
    /*�²���Ľ��Ϊ��ǰ���*/
    llist->curr = newNode;
    return true; // ����true��ʾ����ɹ�

    /********** End **********/
}

// 13��	
bool LL_DelAt(LinkList* llist)
// ɾ�����Ա�ĵ�ǰλ�õ�����Ԫ�ؽ�㡣
// ��ɾ��ʧ�ܣ�Ϊ�ձ���ǰλ��Ϊβ���֮�󣩣��򷵻�false�����򷵻�true��
{	
    LinkNode *oldNode;
    /* ����Ϊ�ջ��ѵ���β֮�������������ʾ������*/
    if (llist->curr==NULL)
    {	
        printf("LL_DelAt(): delete a node that does not exist.\n");
        return false;
    }
    oldNode=llist->curr;
    /* ɾ�����Ǳ�ͷ���*/
    if (llist->pre==NULL)
    {	
        llist->front = oldNode->next;
    }
    /* ɾ�����Ǳ��л��β���*/
    else if(llist->curr!=NULL){
        llist->pre->next = oldNode->next;
    }
    if (oldNode == llist->rear)	{
        /* ɾ�����Ǳ�β��㣬���޸ı�βָ��͵�ǰ���λ��ֵ*/
        llist->rear = llist->pre;
    }

    /* ��̽����Ϊ�µĵ�ǰ���*/
    llist->curr = oldNode->next;

    /* �ͷ�ԭ��ǰ���*/
    free(oldNode);

    /* �����С��*/
    llist->len --;
    return true;
}

// 14��	
bool LL_DelAfter(LinkList* llist)
// ɾ�����Ա�ĵ�ǰλ�õĺ����Ǹ�����Ԫ�ء�
// ��ɾ��ʧ�ܣ�Ϊ�ձ���ǰλ��ʱ��β�����򷵻�false�����򷵻�true��
{
    LinkNode *oldNode;
    /* ����Ϊ�ջ��ѵ���β�������������ʾ������*/
    if (llist->curr==NULL || llist->curr== llist->rear)
    {
        printf("LL_DelAfter():  delete a node that does not exist.\n");
        return false;
    }
    /* ���汻ɾ������ָ�벢��������ɾ���ý��*/
    oldNode = llist->curr->next;
    llist->curr->next=oldNode->next;
    
    if (oldNode == llist->rear)
        /* ɾ�����Ǳ�β���*/
        llist->rear = llist->curr;
    /* �ͷű�ɾ�����*/
    free(oldNode);
    /* �����С��*/
    llist->len --;
    return true;
}

// 15��	
int LL_FindValue(LinkList* llist, T x)
// �ҵ����Ա��е�һ��ֵΪx������Ԫ�صı�š�
// ����ֵ-1��ʾû���ҵ�������ֵ>=0��ʾ��š�
{
    LinkNode* p=llist->front;
    int idx=0;
    while(p!=NULL && p->data!=x) {
        idx++;
        p = p->next;
    }
    if (idx>=llist->len) return -1;
    else return idx;
}

// 16��	
int LL_DelValue(LinkList* llist, T x)
// ɾ����һ��ֵΪx������Ԫ�أ����ظ�����Ԫ�صı�š����������ֵΪx������Ԫ�أ��򷵻�-1.
{
    int idx=LL_FindValue(llist, x);
    if (idx<0) return -1;
    LL_SetPosition(llist, idx);
    LL_DelAt(llist);
    return idx;
}

// 17��	
void LL_Print(LinkList* llist)
// ��ӡ�������Ա�
{
    LinkNode* node=llist->front;
    while (node) {
        printf("%d ", node->data);
        node=node->next;
    }
    printf("\n");
}
