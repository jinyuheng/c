#define _CRT_SECURE_NO_WARNINGS 1
#include "game2.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)//初始化函数
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void SetMine(char board[ROWS][COLS], int row, int col)  //布雷
{
	int count = Easy_Count;

	while (count)
	{
		int x = rand() % row + 1;  //模row得出的数字是 0到row 之间的数字  所以要加1
		int y = rand() % col + 1;//同理
		if (board[x][y] == '0')//放止重复防雷
		{
			board[x][y] = '1';
			count--;
		}
	}
}


void PrintBoard(char board[ROWS][COLS], int row, int col) //打印行标  列标 循环打印元素
{
	int i = 0;
	int j = 0;

	for (i = 0; i <= col; i++)//打印列标
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)//打印行标
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);//循环打印元素
		}
		printf("\n");
	}
}

static int CountMine(char mine[ROWS][COLS], int x, int y)//计算雷的数量
{
	int count = 0;
	count = (mine[x][y - 1] + mine[x][y + 1] + mine[x - 1][y] + mine[x - 1][y - 1] + mine[x - 1][y + 1] + mine[x + 1][y - 1]
		+ mine[x + 1][y] + mine[x + 1][y + 1]) - 8 * '0';
	return count;
}



static void Openboard(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int *count)//排雷之后展开
{
	int i = 0;
	int j = 0;
	if ((x >= 1 && x <= ROW) && (y >= 1 && y <= COL))//判断输入是否合法
	{
		if (CountMine(mine, x, y) == 0)//判断周围是否有雷，如果没有雷
		{
			show[x][y] = '0';
			(*count)--;
			for (i = x - 1; i <= x + 1; i++)
			{
				for (j = y - 1; j <= y + 1; j++)
				{
					if (show[i][j] == '*')//如果还没有展开
					{
						//(*count)--;
						Openboard(mine, show, i, j, count);//利用递归展开
					}
				}

			}
		}
		else
		{
			show[x][y] = CountMine(mine, x, y) + '0';
			(*count)--;

		}
	}
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)//扫雷
{
	int x = 0;
	int y = 0;
	int count = 0;
	int num = ROW*COL - Easy_Count;
	while (1)
	{
		printf("请输入坐标  ");
		scanf("%d %d", &x, &y);
		count++;
		if ((x >= 1 && x <= row) && (y >= 1 && y <= col))
		{
			while (count == 1 && mine[x][y] == '1')//第一次是雷
			{
				InitBoard(mine, ROWS, COLS, '0');//重新初始化
				SetMine(mine, ROW, COL);//重新布雷
			}
			if (mine[x][y] == '1')
			{
				printf("游戏结束  \n");
				break;
			}
			else
			{
				Openboard(mine, show, x, y, &num);//展开
				PrintBoard(show, ROW, COL);
				if (num == 0)
				{
					printf("你赢了\n\n");
					break;
				}
			}

		}

	}

}
