#define _CRT_SECURE_NO_WARNINGS 1

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"


#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2


#define Easy_Count 10 //定义雷的数量

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);//初始化数组
void SetMine(char board[ROWS][COLS], int row, int col); //布雷
void PrintBoard(char board[ROWS][COLS], int row, int col);//打印数组
//static int CountMine(char mine[ROWS][COLS], int x, int y);//计算雷的数量
//static void Openboard(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);//排雷之后展开
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//扫雷