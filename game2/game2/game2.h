#define _CRT_SECURE_NO_WARNINGS 1

#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"


#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2


#define Easy_Count 10 //�����׵�����

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);//��ʼ������
void SetMine(char board[ROWS][COLS], int row, int col); //����
void PrintBoard(char board[ROWS][COLS], int row, int col);//��ӡ����
//static int CountMine(char mine[ROWS][COLS], int x, int y);//�����׵�����
//static void Openboard(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y);//����֮��չ��
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);//ɨ��