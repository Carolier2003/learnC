/*************************************************************
    date: June 2017
    copyright: Zhu En
    DO NOT distribute this code without my permission.
**************************************************************/
// ������ ͷ�ļ�
///////////////////////////////////////////////////
#if !defined(LINKED_LIST_H_LIELJE7398CNHD_INCLUDE_)
#define LINKED_LIST_H_LIELJE7398CNHD_INCLUDE_
////////////////////////////////////////////////////

typedef int T;
struct LinkNode {
    T data;
    LinkNode* next;
};
struct LinkList {
    LinkNode* front;  // ָ��ͷ���
    LinkNode* rear;   // ָ��β���
    LinkNode* pre;    // ָ��ǰλ�ý���ǰһ�����
    LinkNode* curr;   // ָ��ǰλ�ý��
    int position;     // ��ǰλ�ӽ��ı��
    int len;          // ���Ա�Ĵ�С������������
};

// 1��	
LinkList* LL_Create();
// ����һ�����Ӵ洢�����Ա���ʼΪ�ձ�����llistָ�롣

// 2��	
void LL_Free(LinkList* llist);
// �ͷ�����Ľ�㣬Ȼ���ͷ�llist��ָ��Ľṹ��

// 3��	
void LL_MakeEmpty(LinkList* llist);
// ����ǰ���Ա��Ϊһ���ձ������Ҫ�ͷ����н�㡣

// 4��	
int LL_Length(LinkList* llist);
// �������Ա�ĵ�ǰ���ȡ�

// 5��	
bool LL_IsEmpty(LinkList* llist);
// ����ǰ���Ա��ǿձ��򷵻�true�����򷵻�TRUE��

// 6��  
bool LL_SetPosition(LinkList* llist, int i);
// �������Ա�ĵ�ǰλ��Ϊi��λ�á�
// ���óɹ����򷵻�true�����򷵻�false�����Ա�Ϊ�գ���i������Ч�ķ��أ�
// �������Ա�ǰ����Ϊlen����ôi����Ч��ΧΪ[0,len]

// 7)		
int LL_GetPosition(LinkList* llist);
// ��ȡ���Ա�ĵ�ǰλ�ý��ı��

// 8��	
bool LL_NextPosition(LinkList* llist);
// �������Ա�ĵ�ǰλ�õ���һ��λ��Ϊ��ǰλ�á�
// ���óɹ����򷵻�true�����򷵻�false�����Ա�Ϊ�գ���ǰλ��Ϊ��β��

// 9��	
T LL_GetAt(LinkList* llist);
// �������Ա�ĵ�ǰλ�õ�����Ԫ�ص�ֵ��

// 10��	
void LL_SetAt(LinkList* llist, T x);
// �����Ա�ĵ�ǰλ�õ�����Ԫ�ص�ֵ�޸�Ϊx��

// 11��	
bool LL_InsAt(LinkList* llist, T x);
// �����Ա�ĵ�ǰλ��֮ǰ��������Ԫ��x���ձ�������롣��ǰλ��ָ�뽫ָ���½�㡣
// ������ʧ�ܣ�����false�����򷵻�true��

// 12��	
bool LL_InsAfter(LinkList* llist, T x);
// �����Ա�ĵ�ǰλ��֮���������Ԫ��x���ձ�������롣��ǰλ��ָ�뽫ָ���½�㡣
// ������ʧ�ܣ�����false�����򷵻�true��

// 13��	
bool LL_DelAt(LinkList* llist);
// ɾ�����Ա�ĵ�ǰλ�õ�����Ԫ�ؽ�㡣
// ��ɾ��ʧ�ܣ�Ϊ�ձ����򷵻�false�����򷵻�true��

// 14��	
bool LL_DelAfter(LinkList* llist);
// ɾ�����Ա�ĵ�ǰλ�õĺ����Ǹ�����Ԫ�ء�
// ��ɾ��ʧ�ܣ�Ϊ�ձ���ǰλ��ʱ��β�����򷵻�false�����򷵻�true��

// 15��	
int LL_FindValue(LinkList* llist, T x);
// �ҵ����Ա��е�һ��ֵΪx������Ԫ�صı�š�
// ����ֵ-1��ʾû���ҵ�������ֵ>=0��ʾ��š�

// 16��	
int LL_DelValue(LinkList* llist, T x);
// ɾ����һ��ֵΪx������Ԫ�أ����ظ�����Ԫ�صı�š����������ֵΪx������Ԫ�أ��򷵻�-1.

// 17��	
void LL_Print(LinkList* llist);
// ��ӡ�������Ա�

#endif // LINKED_LIST_H_LIELJE7398CNHD_INCLUDE_
