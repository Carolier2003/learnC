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
	printf("������ѧ����Ϣ:\n");
	scanf("%s", &s->num);
	scanf("%s", &s->name);
	scanf("%d", &s->age);
	printf("%x", s);
	return;
}
void output1(student* s)
{
	printf("\n");
	printf("�����ѧ����Ϣ:\n");
	printf("ѧ�ţ�");
	printf("%s\n", s->num);
	printf("������");
	printf("%s\n", s->name);
	printf("���䣺");
	printf("%d\n", s->age);
	return;
}
void main()
{
	struct student* s1;
	struct student s2 = { "002","abab",22 };
	printf("�����ѧ����Ϣ:\n");
	printf("ѧ�ţ�");
	printf("%6s\n", &s2.num);
	printf("������");
	printf("%8s\n", &s2.name);
	printf("���䣺");
	printf("%5d\n", &s2.age);
	s1 = (student*)malloc(sizeof(student));
	input1(&s2);
	output1(&s2);
	printf("%x", &s2);
	printf("�����ѧ����Ϣ:\n");
	printf("ѧ�ţ�");
	printf("%6s\n", &s2.num);
	printf("������");
	printf("%8s\n", &s2.name);
	printf("���䣺");
	printf("%5d\n", &s2.age);
	free(s1);
}





