#include<stdio.h>
// ������ṹ��
struct node {
    int data; // ������
    struct node* next; // ָ����
};

// ���õ�����ĺ���
void reverse(struct node** head) {
    struct node* prev = NULL; // ǰ�����
    struct node* curr = *head; // ��ǰ���
    struct node* next = NULL; // ��̽��
    while (curr != NULL) {
        next = curr->next; // �����̽��
        curr->next = prev; // ����ǰ����nextָ��ǰ�����
        prev = curr; // ��ǰ��������Ϊ��ǰ���
        curr = next; // ����ǰ������Ϊ��̽��
    }
    *head = prev; // ��headָ�����ú�ĵ�һ�����
}