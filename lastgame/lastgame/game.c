#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#define ROW 3//定义行数
#define COL 3//定义列数

void Initialization(char board[ROW][COL], int row, int col);//游戏实现函数

void printboard(char board[ROW][COL], int row, int col);//打印棋盘函数

void playermove(char board[ROW][COL], int row, int col);//玩家下棋

void computermove(char board[ROW][COL], int row, int col);//电脑下棋

char IsWin(char board[ROW][COL], int row, int col);//判断胜负

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
		printf("请选择 : >");
		int choice = 0;
		scanf("%d", &choice);
		if (choice == 0)
			break;
		else if (choice == 1)
		{

			Initialization(board, ROW, COL);// 初始化数组

			printboard(board, ROW, COL);//打印棋盘

			int steps = 0;
			do
			{
				playermove(board, ROW, COL);//玩家下棋
				printboard(board, ROW, COL);//打印棋盘
				set = IsWin(board, ROW, COL);//判断胜负
				if (set == '#')
					break;
				steps++;
				if (steps == 9)
					break;
				computermove(board, ROW, COL);//电脑下棋
				printboard(board, ROW, COL);//打印棋盘
				set = IsWin(board, ROW, COL);//判断胜负
				if (set == '*')
					break;
				steps++;
			} while (!set);

		}

		else
			printf("Invalid value\n");//非法数据 提示从新输入
		if (set == '#')
			printf("玩家赢\n");

		else if (set == '*')
			printf("电脑赢\n");
		else
			printf("平局\n");
		printboard(board, ROW, COL);//打印棋盘
	} while (1);

	return 0;
}



void Initialization(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//遍历数组 全部赋值为空格
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
			printf(" %c ", board[i][j]);
			if (j < (col - 1))
				printf("|");//摆放空格 中间以 | 隔开
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
	printf("玩家走\n");
	printf("请输入坐标（例如：1 1）:>");
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
			printf("坐标已占用，请重新输入:>");
		}
		else
		{
			printf("非法坐标请重新输入:>");
		}
	} while (1);

}

void computermove(char board[ROW][COL], int row, int col)
{
	printf("电脑走\n");

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
	for (i = 0; i < row; i++)//判断行
	{
		if (board[i][1] == board[i][2] && board[i][2] == board[i][0] && board[i][1] != ' ')
			return board[i][1];
	}
	for (i = 0; i < col; i++)//判断列
	{
		if (board[1][i] == board[2][i] && board[2][i] == board[0][i] && board[1][i] != ' ')
			return board[1][i];
	}
	//判断两个对角线
	if (board[1][1] == board[2][2] && board[2][2] == board[0][0] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	return '\0';
}
