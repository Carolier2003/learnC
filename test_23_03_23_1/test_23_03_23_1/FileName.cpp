#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define MaxSize 50

//定义一个结构体，用于存放职工信息
typedef struct
{
	int id;//工号
	char sex;//性别
	char name[20];//姓名
}Employee;

//定义一个顺序表类型，用于存放Employee类型的数据
typedef struct
{
	Employee data[MaxSize];//存放顺序表中的职工信息
	int length;//存放顺序表的长度
}EmpList;//声明顺序表的类型

//定义一个函数，用于创建顺序表，并根据给定数组初始化职工信息
void CreateList(EmpList*& L, Employee a[], int n)
{
	L = (EmpList*)malloc(sizeof(EmpList));
	for (int i = 0; i < n; i++) {
		L->data[i] = a[i];
	}
	L->length = n;
}

//定义一个函数，用于输出顺序表中所有职工信息
void DispList(EmpList* L)
{
	printf("工号\t性别\t姓名\n");
	for (int i = 0; i < L->length; i++)
		printf("%d\t%c\t%s\n", L->data[i].id, L->data[i].sex, L->data[i].name);
	printf("\n");
}

//定义一个函数，用于在顺序表中新增员工
bool AddEmp(EmpList*& L, Employee e)
{
	//判断顺序表是否已满
	if (L->length == MaxSize)
		return false;
	//将新员工信息添加到顺序表末尾
	L->data[L->length] = e;
	//顺序表长度加一
	L->length++;
	return true;
}

//定义一个函数，用于在顺序表中删除离职员工
bool DeleteEmp(EmpList*& L, int id)
{
	//声明一个变量i，用于遍历顺序表中的每个员工信息
	int i;
	//从第一个员工开始遍历，找到与给定id相同的员工
	for (i = 0; i < L->length; i++)
	{
		if (L->data[i].id == id)
			break;
	}
	//判断是否找到了该员工
	if (i == L->length)
		return false;
	//将该员工之后的所有员工信息向前移动一个位置
	for (int j = i; j < L->length - 1; j++)
	{
		L->data[j] = L->data[j + 1];
	}
	//顺序表长度减一
	L->length--;
	return true;
}

//定义一个函数，用于按工号查找员工信息，并返回其在顺序表中的位置（从1开始计数）
int FindEmpById(EmpList* L, int id)
{
	//声明一个变量i，用于遍历顺序表中的每个员工信息
	int i;
	//从第一个员工开始遍历，找到与给定id相同的员工
	for (i = 0; i < L->length; i++)
	{
		if (L->data[i].id == id)
			break;
	}
	//判断是否找到了该员工
	if (i == L->length)
		return 0;
	else
		return i + 1;
}

//定义一个函数，用于按姓名查找员工信息，并返回其在顺序表中的位置（从1开始计数）
int FindEmpByName(EmpList* L, char name[])
{
	//声明一个变量i，用于遍历顺序表中的每个员工信息
	int i;
	//从第一个员工开始遍历，找到与给定姓名相同的员工
	for (i = 0; i < L->length; i++)
	{
		//比较字符串是否相等，如果相等就跳出循环
		if (strcmp(L->data[i].name, name) == 0)
			break;
	}
	//判断是否找到了该员工
	if (i == L->length)
		return 0;
	else
		return i + 1;
}

//定义一个主函数，用于测试顺序表的各种操作
int main()
{
	//声明一个顺序表指针L
	EmpList* L;
	//声明一个数组a，用于初始化顺序表中的职工信息
	Employee a[] = { {1001,'M',"张三"},{1002,'F',"李四"},{1003,'M',"王五"},{1004,'F',"赵六"} };
	//声明一个变量n，用于存放数组a中的元素个数
	int n = sizeof(a) / sizeof(a[0]);
	//调用CreateList函数，创建顺序表，并根据数组a初始化职工信息
	CreateList(L, a, n);
	//调用DispList函数，输出顺序表中所有职工信息
	DispList(L);
	//声明一个变量choice，用于存放用户选择的操作编号
	int choice;
	//声明一个变量flag，用于存放操作是否成功的标志
	bool flag;
	//声明一个变量id，用于存放用户输入的工号
	int id;
	//声明一个变量name，用于存放用户输入的姓名
	char name[20];
	//声明一个变量pos，用于存放查找到的员工在顺序表中的位置（从1开始计数）
	int pos;
	//声明一个结构体变量e，用于存放用户输入的新员工信息
	Employee e;

	//使用do-while循环，让用户重复选择操作直到退出
	do {
		//输出菜单提示信息
		printf("请选择你要进行的操作：\n");
		printf("1.新增员工\n");
		printf("2.删除离职员工\n");
		printf("3.按工号查找员工\n");
		printf("4.按姓名查找员工\n");
		printf("5.输出职工信息\n");
		printf("0.退出程序\n");
		//输入用户选择的操作编号，并赋值给choice变量
		scanf("%d", &choice);

		//使用switch语句，根据choice变量的值执行相应的操作
		switch (choice) {
		case 1: //新增员工
			//提示用户输入新员工的信息，并赋值给e变量
			printf("请输入新员工的信息：\n");
			printf("请输入新员工的工号：\n");
			scanf("%d", &e.id);
			printf("请输入新员工的性别（M或F）：\n");
			scanf("%c", &e.sex);
			getchar(); //吸收回车符
			printf("请输入新员工的姓名：\n");
			gets(e.name);
			//调用AddEmp函数，在顺序表中新增员工，并将返回值赋给flag变量
			flag = AddEmp(L, e);
			//判断flag变量是否为真，如果为真则表示新增成功，否则表示新增失败（顺序表已满）
			if (flag)
				printf("新增成功！\n");
			else
				printf("新增失败！\n");
			break;
		case 2: //删除离职员工 
			//提示用户输入离职员工的工号，并赋值给id变量 
			printf("请输入离职员工的工号：\n");
			scanf("%d", &id);
			//调用DeleteEmp函数，在顺序表中删除离职员工，并将返回值赋给flag变量 
			flag = DeleteEmp(L, id);
			//判断flag变量是否为真，如果为真则表示删除成功，否则表示删除失败（没有找到该员工）
			if (flag)
				printf("删除成功！\n");
			else
				printf("删除失败！\n");
			break;
		case 3: //按工号查找员工 
			//提示用户输入要查找的员工的工号，并赋值给id变量 
			printf("请输入要查找的员工的工号：\n");
			scanf("%d", &id);
			//调用FindEmpById函数，按工号查找员工，并将返回值赋给pos变量
			pos = FindEmpById(L, id);
			//判断pos变量是否为0，如果为0则表示没有找到该员工，否则表示找到了该员工，并输出其信息
			if (pos == 0)
				printf("没有找到该员工！\n");
			else {
				printf("找到了该员工！\n");
				printf("他（她）在顺序表中的位置是：%d\n", pos);
				printf("他（她）的信息是：\n");
				printf("%d\t%c\t%s\n", L->data[pos - 1].id, L->data[pos - 1].sex, L->data[pos - 1].name);
			}
			break;
		case 4: //按姓名查找员工  
			//提示用户输入要查找的员工的姓名，并赋值给name变量  
			printf("请输入要查找的员工的姓名：\n");
			getchar(); //吸收回车符  
			gets(name);
			//调用FindEmpByName函数，按姓名查找员工，并将返回值赋给pos变量  
			pos = FindEmpByName(L, name);
			//判断pos变量是否为0，如果为0则表示没有找到该员工，否则表示找到了该员工，并输出其信息  
			if (pos == 0)
				printf("没有找到该员工！\n");
			else {
				printf("找到了该员工！\n");
				printf("他（她）在顺序表中的位置是：%d\n", pos);
				printf("他（她）的信息是：\n");
				printf("%d\t%c\t%s\n", L->data[pos - 1].id, L->data[pos - 1].sex, L->data[pos - 1].name);
			}
			break;
		case 5: //输出职工信息   
			//调用DispList函数，输出顺序表中所有职工信息   
			DispList(L);
			break;
		case 0: //退出程序   
			//输出退出提示信息   
			printf("感谢使用本程序！再见！\n");
		}
	} while (choice != 0); //当choice变量不等于0时，重复执行do-while循环   

	return 0; //主函数返回0
}