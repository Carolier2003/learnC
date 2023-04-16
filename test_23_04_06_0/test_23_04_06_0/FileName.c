#include<stdio.h>
// 定义结点结构体
struct node {
    int data; // 数据域
    struct node* next; // 指针域
};

// 逆置单链表的函数
void reverse(struct node** head) {
    struct node* prev = NULL; // 前驱结点
    struct node* curr = *head; // 当前结点
    struct node* next = NULL; // 后继结点
    while (curr != NULL) {
        next = curr->next; // 保存后继结点
        curr->next = prev; // 将当前结点的next指向前驱结点
        prev = curr; // 将前驱结点更新为当前结点
        curr = next; // 将当前结点更新为后继结点
    }
    *head = prev; // 将head指向逆置后的第一个结点
}