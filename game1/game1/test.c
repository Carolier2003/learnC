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
				set = IsWin(board,ROW,COL);//判断胜负
				if (set == '#')
					break;
				steps++;
				if (steps == 9)
					break;
				computermove(board,ROW,COL);//电脑下棋
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