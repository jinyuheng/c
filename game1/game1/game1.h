#define _CRT_SECURE_NO_WARNINGS 1
//头文件  声明这些函数  
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define  ROW 3//定义行和列
#define  COL 3

void InitBoard(char board[ROW][COL], int row, int col);//初始化
void PrintBoard(char board[ROW][COL], int row, int col);//打印棋盘
void CompMove(char board[ROW][COL], int row, int col);//电脑走
void PlayMove(char board[ROW][COL], int row, int col);//玩家走
char CheckWin(char board[ROW][COL], int row, int col);//判断输赢