#include"game.h"

int main()
{
	char set = ' ';
	char board[ROW][COL];
	do
	{
		printf("*******************************\n");
		printf("****   <1>    play         ****\n");
		printf("****   <0>    exit         ****\n");
		printf("*******************************\n");
		printf("��ѡ�� : >");
		int choice = 0;
		scanf("%d", &choice);
		if (choice == 0)
			break;
		else if (choice == 1)
		{
			
			Initialization(board, ROW, COL);// ��ʼ������

			printboard(board, ROW, COL);//��ӡ����

			int steps = 0;
			do
			{
				playermove(board, ROW, COL);//�������
				printboard(board, ROW, COL);//��ӡ����
				set = IsWin(board,ROW,COL);//�ж�ʤ��
				if (set == '#')
					break;
				steps++;
				if (steps == 9)
					break;
				computermove(board,ROW,COL);//��������
				printboard(board, ROW, COL);//��ӡ����
				set = IsWin(board, ROW, COL);//�ж�ʤ��
				if (set == '*')
					break;
				steps++;
			} while (!set);
			
		}
			
		else
			printf("Invalid value\n");//�Ƿ����� ��ʾ��������
		if (set == '#')
			printf("���Ӯ\n");

		else if (set == '*')
			printf("����Ӯ\n");
		else
			printf("ƽ��\n");
		printboard(board, ROW, COL);//��ӡ����
	} while (1);
	
	return 0;
}