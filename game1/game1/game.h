#pragma once
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