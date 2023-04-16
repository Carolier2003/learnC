#include<stdio.h>
#include <malloc.h>
struct student
{
	char num[6];
	char name[8];
	int age;
};
void input1(student* s)
{
	printf("请输入学生信息:\n");
	scanf("%s", &s->num);
	scanf("%s", &s->name);
	scanf("%d", &s->age);
	printf("%x", s);
	return;
}
void output1(student* s)
{
	printf("\n");
	printf("请输出学生信息:\n");
	printf("学号：");
	printf("%s\n", s->num);
	printf("姓名：");
	printf("%s\n", s->name);
	printf("年龄：");
	printf("%d\n", s->age);
	return;
}
void main()
{
	struct student* s1;
	struct student s2 = { "002","abab",22 };
	printf("请输出学生信息:\n");
	printf("学号：");
	printf("%6s\n", &s2.num);
	printf("姓名：");
	printf("%8s\n", &s2.name);
	printf("年龄：");
	printf("%5d\n", &s2.age);
	s1 = (student*)malloc(sizeof(student));
	input1(&s2);
	output1(&s2);
	printf("%x", &s2);
	printf("请输出学生信息:\n");
	printf("学号：");
	printf("%6s\n", &s2.num);
	printf("姓名：");
	printf("%8s\n", &s2.name);
	printf("年龄：");
	printf("%5d\n", &s2.age);
	free(s1);
}





