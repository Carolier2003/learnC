#include "game.h"

void Initialization(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//�������� ȫ����ֵΪ�ո�
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void printboard(char board[ROW][COL], int row, int col)
{										        
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ",board[i][j]);
			if (j < (col - 1))
				printf("|");//�ڷſո� �м��� | ����
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
				if (j < col - 1)
					printf("---|");
				else
					printf("---");
				
		}
		printf("\n");
	}
}

void playermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("�����\n");
	printf("���������꣨���磺1 1��:>");
	do
	{
		scanf("%d%d", &x, &y);
		if (board[x - 1][y - 1] == ' ')
		{
			board[x - 1][y - 1] = '#';
			break;
		}
		else if (board[x - 1][y - 1] == '#' || board[x - 1][y - 1] == '*')
		{
			printf("������ռ�ã�����������:>");
		}
		else
		{
			printf("�Ƿ���������������:>");
		}
	} while (1);
	
}

void computermove(char board[ROW][COL], int row, int col)
{
	printf("������\n");
	
	do
	{
		if (board[1][1] == ' ')
		{
			board[1][1] = ' *';
			break;
		}
		int x = 0;
		int y = 0;
		srand((unsigned)time(NULL));
		x = rand() % 3;
		y = rand() % 3;
		if (board[x][y] == ' ')
		{
			board[x][y] = '*';
			break;
		}
	} while (1);
	
}

char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)//�ж���
	{
		if (board[i][1] == board[i][2] && board[i][2] == board[i][0] && board[i][1] != ' ')
			return board[i][1];
	}
	for (i = 0; i < col; i++)//�ж���
	{
		if (board[1][i] == board[2][i] && board[2][i] == board[0][i] && board[1][i] != ' ')
			return board[1][i];
	}
	//�ж������Խ���
	if (board[1][1] == board[2][2] && board[2][2] == board[0][0] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	return '\0';
}
