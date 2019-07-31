#define _CRT_SECURE_NO_WARNINGS 1
#include "game1.h"

void InitBoard(char board[ROW][COL], int row, int col)//初始化
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)//两个参数
	{
		for (j = 0; j <col; j++)
		{//对九个空格进行赋值
			board[i][j] = ' ';//传参
		}
	}
}

void PrintBoard(char board[ROW][COL], int row, int col)//打印
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		//打印空格和|

		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");

		//打印分割的虚线
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}
//传参需要一个数组  还要知道行和列
void CompMove(char board[ROW][COL], int row, int col)//电脑走
{
	int x = 0;
	int y = 0;
	printf("电脑走 \n");

	while (1)
	{
		x = rand() % row;//rand 生成随机数的关键字  但是需要现在测试文件中定义
		y = rand() % col;//因为数组里面是下标是0-2 所以要模3
		if (board[x][y] == ' ')//判断是否被占用了
		{
			board[x][y] = '#';
			break;
		}
	}
}

void PlayMove(char board[ROW][COL], int row, int col)  //玩家走
{

	int x = 0;
	int y = 0;

	printf("玩家走  \n");
	while (1)
	{

		scanf("%d %d", &x, &y);

		if (x >= 1 && x <= row&&y >= 1 && y <= col)//调整位置与下标之间的关系
		{
			if (board[x - 1][y - 1] != ' ')//输入要与棋盘匹配
			{
				printf("此位置已经被占用\n");
			}
			else
			{
				board[x - 1][y - 1] = '*';
				break;
			}
		}
		else
		{
			printf("输入错误，请重新输入坐标\n");
		}
	}
}
static char Checkfull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char CheckWin(char board[ROW][COL], int row, int col)//判断输赢
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
	{
		return board[1][1];
	}

	if (Checkfull(board, row, col) == 1)//均占满 属于平局

	{
		return 'Q';
	}
	//游戏继续
	return 'C';
}
