#pragma once
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

#define ROW 3//��������
#define COL 3//��������

void Initialization(char board[ROW][COL], int row, int col);//��Ϸʵ�ֺ���

void printboard(char board[ROW][COL], int row, int col);//��ӡ���̺���

void playermove(char board[ROW][COL], int row, int col);//�������

void computermove(char board[ROW][COL], int row, int col);//��������

char IsWin(char board[ROW][COL], int row, int col);//�ж�ʤ��