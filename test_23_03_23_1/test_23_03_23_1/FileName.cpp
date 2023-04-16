#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define MaxSize 50

//����һ���ṹ�壬���ڴ��ְ����Ϣ
typedef struct
{
	int id;//����
	char sex;//�Ա�
	char name[20];//����
}Employee;

//����һ��˳������ͣ����ڴ��Employee���͵�����
typedef struct
{
	Employee data[MaxSize];//���˳����е�ְ����Ϣ
	int length;//���˳���ĳ���
}EmpList;//����˳��������

//����һ�����������ڴ���˳��������ݸ��������ʼ��ְ����Ϣ
void CreateList(EmpList*& L, Employee a[], int n)
{
	L = (EmpList*)malloc(sizeof(EmpList));
	for (int i = 0; i < n; i++) {
		L->data[i] = a[i];
	}
	L->length = n;
}

//����һ���������������˳���������ְ����Ϣ
void DispList(EmpList* L)
{
	printf("����\t�Ա�\t����\n");
	for (int i = 0; i < L->length; i++)
		printf("%d\t%c\t%s\n", L->data[i].id, L->data[i].sex, L->data[i].name);
	printf("\n");
}

//����һ��������������˳���������Ա��
bool AddEmp(EmpList*& L, Employee e)
{
	//�ж�˳����Ƿ�����
	if (L->length == MaxSize)
		return false;
	//����Ա����Ϣ��ӵ�˳���ĩβ
	L->data[L->length] = e;
	//˳����ȼ�һ
	L->length++;
	return true;
}

//����һ��������������˳�����ɾ����ְԱ��
bool DeleteEmp(EmpList*& L, int id)
{
	//����һ������i�����ڱ���˳����е�ÿ��Ա����Ϣ
	int i;
	//�ӵ�һ��Ա����ʼ�������ҵ������id��ͬ��Ա��
	for (i = 0; i < L->length; i++)
	{
		if (L->data[i].id == id)
			break;
	}
	//�ж��Ƿ��ҵ��˸�Ա��
	if (i == L->length)
		return false;
	//����Ա��֮�������Ա����Ϣ��ǰ�ƶ�һ��λ��
	for (int j = i; j < L->length - 1; j++)
	{
		L->data[j] = L->data[j + 1];
	}
	//˳����ȼ�һ
	L->length--;
	return true;
}

//����һ�����������ڰ����Ų���Ա����Ϣ������������˳����е�λ�ã���1��ʼ������
int FindEmpById(EmpList* L, int id)
{
	//����һ������i�����ڱ���˳����е�ÿ��Ա����Ϣ
	int i;
	//�ӵ�һ��Ա����ʼ�������ҵ������id��ͬ��Ա��
	for (i = 0; i < L->length; i++)
	{
		if (L->data[i].id == id)
			break;
	}
	//�ж��Ƿ��ҵ��˸�Ա��
	if (i == L->length)
		return 0;
	else
		return i + 1;
}

//����һ�����������ڰ���������Ա����Ϣ������������˳����е�λ�ã���1��ʼ������
int FindEmpByName(EmpList* L, char name[])
{
	//����һ������i�����ڱ���˳����е�ÿ��Ա����Ϣ
	int i;
	//�ӵ�һ��Ա����ʼ�������ҵ������������ͬ��Ա��
	for (i = 0; i < L->length; i++)
	{
		//�Ƚ��ַ����Ƿ���ȣ������Ⱦ�����ѭ��
		if (strcmp(L->data[i].name, name) == 0)
			break;
	}
	//�ж��Ƿ��ҵ��˸�Ա��
	if (i == L->length)
		return 0;
	else
		return i + 1;
}

//����һ�������������ڲ���˳���ĸ��ֲ���
int main()
{
	//����һ��˳���ָ��L
	EmpList* L;
	//����һ������a�����ڳ�ʼ��˳����е�ְ����Ϣ
	Employee a[] = { {1001,'M',"����"},{1002,'F',"����"},{1003,'M',"����"},{1004,'F',"����"} };
	//����һ������n�����ڴ������a�е�Ԫ�ظ���
	int n = sizeof(a) / sizeof(a[0]);
	//����CreateList����������˳�������������a��ʼ��ְ����Ϣ
	CreateList(L, a, n);
	//����DispList���������˳���������ְ����Ϣ
	DispList(L);
	//����һ������choice�����ڴ���û�ѡ��Ĳ������
	int choice;
	//����һ������flag�����ڴ�Ų����Ƿ�ɹ��ı�־
	bool flag;
	//����һ������id�����ڴ���û�����Ĺ���
	int id;
	//����һ������name�����ڴ���û����������
	char name[20];
	//����һ������pos�����ڴ�Ų��ҵ���Ա����˳����е�λ�ã���1��ʼ������
	int pos;
	//����һ���ṹ�����e�����ڴ���û��������Ա����Ϣ
	Employee e;

	//ʹ��do-whileѭ�������û��ظ�ѡ�����ֱ���˳�
	do {
		//����˵���ʾ��Ϣ
		printf("��ѡ����Ҫ���еĲ�����\n");
		printf("1.����Ա��\n");
		printf("2.ɾ����ְԱ��\n");
		printf("3.�����Ų���Ա��\n");
		printf("4.����������Ա��\n");
		printf("5.���ְ����Ϣ\n");
		printf("0.�˳�����\n");
		//�����û�ѡ��Ĳ�����ţ�����ֵ��choice����
		scanf("%d", &choice);

		//ʹ��switch��䣬����choice������ִֵ����Ӧ�Ĳ���
		switch (choice) {
		case 1: //����Ա��
			//��ʾ�û�������Ա������Ϣ������ֵ��e����
			printf("��������Ա������Ϣ��\n");
			printf("��������Ա���Ĺ��ţ�\n");
			scanf("%d", &e.id);
			printf("��������Ա�����Ա�M��F����\n");
			scanf("%c", &e.sex);
			getchar(); //���ջس���
			printf("��������Ա����������\n");
			gets(e.name);
			//����AddEmp��������˳���������Ա������������ֵ����flag����
			flag = AddEmp(L, e);
			//�ж�flag�����Ƿ�Ϊ�棬���Ϊ�����ʾ�����ɹ��������ʾ����ʧ�ܣ�˳���������
			if (flag)
				printf("�����ɹ���\n");
			else
				printf("����ʧ�ܣ�\n");
			break;
		case 2: //ɾ����ְԱ�� 
			//��ʾ�û�������ְԱ���Ĺ��ţ�����ֵ��id���� 
			printf("��������ְԱ���Ĺ��ţ�\n");
			scanf("%d", &id);
			//����DeleteEmp��������˳�����ɾ����ְԱ������������ֵ����flag���� 
			flag = DeleteEmp(L, id);
			//�ж�flag�����Ƿ�Ϊ�棬���Ϊ�����ʾɾ���ɹ��������ʾɾ��ʧ�ܣ�û���ҵ���Ա����
			if (flag)
				printf("ɾ���ɹ���\n");
			else
				printf("ɾ��ʧ�ܣ�\n");
			break;
		case 3: //�����Ų���Ա�� 
			//��ʾ�û�����Ҫ���ҵ�Ա���Ĺ��ţ�����ֵ��id���� 
			printf("������Ҫ���ҵ�Ա���Ĺ��ţ�\n");
			scanf("%d", &id);
			//����FindEmpById�����������Ų���Ա������������ֵ����pos����
			pos = FindEmpById(L, id);
			//�ж�pos�����Ƿ�Ϊ0�����Ϊ0���ʾû���ҵ���Ա���������ʾ�ҵ��˸�Ա�������������Ϣ
			if (pos == 0)
				printf("û���ҵ���Ա����\n");
			else {
				printf("�ҵ��˸�Ա����\n");
				printf("����������˳����е�λ���ǣ�%d\n", pos);
				printf("������������Ϣ�ǣ�\n");
				printf("%d\t%c\t%s\n", L->data[pos - 1].id, L->data[pos - 1].sex, L->data[pos - 1].name);
			}
			break;
		case 4: //����������Ա��  
			//��ʾ�û�����Ҫ���ҵ�Ա��������������ֵ��name����  
			printf("������Ҫ���ҵ�Ա����������\n");
			getchar(); //���ջس���  
			gets(name);
			//����FindEmpByName����������������Ա������������ֵ����pos����  
			pos = FindEmpByName(L, name);
			//�ж�pos�����Ƿ�Ϊ0�����Ϊ0���ʾû���ҵ���Ա���������ʾ�ҵ��˸�Ա�������������Ϣ  
			if (pos == 0)
				printf("û���ҵ���Ա����\n");
			else {
				printf("�ҵ��˸�Ա����\n");
				printf("����������˳����е�λ���ǣ�%d\n", pos);
				printf("������������Ϣ�ǣ�\n");
				printf("%d\t%c\t%s\n", L->data[pos - 1].id, L->data[pos - 1].sex, L->data[pos - 1].name);
			}
			break;
		case 5: //���ְ����Ϣ   
			//����DispList���������˳���������ְ����Ϣ   
			DispList(L);
			break;
		case 0: //�˳�����   
			//����˳���ʾ��Ϣ   
			printf("��лʹ�ñ������ټ���\n");
		}
	} while (choice != 0); //��choice����������0ʱ���ظ�ִ��do-whileѭ��   

	return 0; //����������0
}