#define _CRT_SECURE_NO_WARNINGS 1
//ͷ�ļ�  ������Щ����  
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

#define  ROW 3//�����к���
#define  COL 3

void InitBoard(char board[ROW][COL], int row, int col);//��ʼ��
void PrintBoard(char board[ROW][COL], int row, int col);//��ӡ����
void CompMove(char board[ROW][COL], int row, int col);//������
void PlayMove(char board[ROW][COL], int row, int col);//�����
char CheckWin(char board[ROW][COL], int row, int col);//�ж���Ӯ