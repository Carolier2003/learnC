#include<stdio.h>
#include<malloc.h>
#include<cstring>
#define MaxSize 50
typedef char ElemType;
typedef struct 
{
	ElemType data[MaxSize];//存放顺序表中的元素
	int length;//存放顺序表的长度
}SqList;//声明顺序表的类型
void CreateList(SqList*& L, ElemType a[], int n) 
{
	L = (SqList*)malloc(sizeof(SqList));
	for (int i = 0; i < n; i++) {
		L->data[i] = a[i];
	}
	L->length = n;
}//整体建立顺序表
void InitList(SqList*& L) 
{
	L = (SqList*)malloc(sizeof(SqList));//分配存放线性表的空间
	L->length = 0;
}//初始化线性表
void DestroyList(SqList*& L) 
{
	free(L);
}//销毁线性表
bool ListEmpty(SqList* L) //判断线性表是否为空表
{
	return(L->length == 0);
}
int ListLength(SqList* L) //求线性表的长度
{
	return(L->length);
}
void DispList(SqList* L)//输出线性表
{
	for (int i = 0; i < L->length; i++)
		printf("%c", L->data[i]);
	printf("\n");
}
bool GetElem(SqList* L, int i, ElemType& e)//求线性表中第i个元素的值
{
	if (i < 1 || i > L->length)
		return false;
	e = L->data[i - 1];
	return true;
}
int LocateElem(SqList* L, ElemType e) //查找第一个值域为e的元素的序号
{
	int i = 0;
	while (i < L->length && L->data[i] != e)
		i++;
	if (i >= L->length)
		return 0;
	else
		return i + i;
}
bool ListInsert(SqList*& L, int i, ElemType e)//插入第i个元素
{
	int j;
	if (i<1 || i>L->length + 1 || L->length == MaxSize)
		return false;
	i--;//将顺序表的位序转换为data的下标
	for (j = L->length; j > i; j--)//将data[i]及后面的元素后移一个位置
		L->data[j] = L->data[j - 1];
	L->data[i] = e;
	L->length++;//顺序表的长度增加
	return true;
}
bool ListDelete(SqList*& L, int i, ElemType& e)//删除第i个元素
{
	int j;
	if (i<1 || i>L->length)
		return false;
	i--;//将顺序表的为序转化为data的下标
	e = L->length;
	for (j = i; j < L->length - 1; j++)//将data[i]之后的元素向前移动一个位置
		L->data[j] = L->data[j + 1];
	L->length--;//顺序表的长度减
	return true;
}

int main()
{
    //（1）创建顺序表
    //假设有一个字符数组a，存放了10个元素
    ElemType a[10] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
    //声明一个指向顺序表的指针L
    SqList* L;
    //调用CreateList函数，传递a和10作为输入参数，L作为输出参数
    CreateList(L, a, 10);
    //打印顺序表中的元素
    DispList(L);

    //（2）顺序表中的元素查找
    //声明一个表示待查找元素值的变量e
    ElemType e;
    //给e赋值为'g'
    e = 'g';
    //声明一个表示查找结果的变量i
    int i;
    //调用LocateElem函数，传递L和e作为输入参数，i作为输出参数
    i = LocateElem(L, e);
    //判断查找结果是否为0
    if (i == 0)
        printf("没有找到元素%c\n", e);
    else
        printf("找到了元素%c，它在顺序表中的位置是%d\n", e, i);

    //（3）顺序表中元素的插入和删除
    //声明一个表示插入位置的整数i
    i = 5;
    //声明一个表示插入值的变量e
    e = 'k';
    //声明一个表示插入结果的变量b
    bool b;
    //调用ListInsert函数，传递L，i和e作为输入参数，b作为输出参数
    b = ListInsert(L, i, e);
    //判断插入结果是否为true
    if (b)
        printf("在顺序表中第%d个位置插入了元素%c\n", i, e);
    else
        printf("插入失败\n");

    //打印顺序表中的元素
    DispList(L);

    //给i赋值为8
    i = 8;
    //调用ListDelete函数，传递L和i作为输入参数，e和b作为输出参数
    b = ListDelete(L, i, e);
    //判断删除结果是否为true
    if (b)
        printf("删除了顺序表中第%d个位置的元素%c\n", i, e);
    else
        printf("删除失败\n");

    //打印顺序表中的元素
    DispList(L);
}
