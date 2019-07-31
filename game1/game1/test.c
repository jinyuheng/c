#define _CRT_SECURE_NO_WARNINGS 1
//test  里面放测试的代码
#include "game1.h"
//游戏代码都放game里面

void menu()
{
	printf("*************************\n");
	printf("***  1.play           ***\n");
	printf("***  0.exit           ***\n");
	printf("*************************\n");
}
//思路  初始化  打印棋盘  玩家先走 判断输赢  电脑走  判断输赢
void game()
{
	char board[ROW][COL] = { 0 };//定义

	char tmp = 0;//变量
	InitBoard(board, ROW, COL);//初始化
	PrintBoard(board, ROW, COL);//打印

	//判断返回值，判断输赢，循环
	while (1)
	{
		PlayMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);//打印
		tmp = CheckWin(board, ROW, COL);
		if (tmp != 'C')
		{
			break;
		}
		CompMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);//打印
		tmp = CheckWin(board, ROW, COL);
		if (tmp != 'C')
		{
			break;
		}
	}
	if (tmp == '*')
	{
		printf("你赢了  \n");
	}
	else if (tmp == '#')
	{
		printf("电脑赢了  \n");
	}
	else if (tmp == 'Q')
	{
		printf("平局\n");
	}
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择  \n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误  \n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	system("pause");
	return 0;
}