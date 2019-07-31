#define _CRT_SECURE_NO_WARNINGS 1

#include "game2.h"
void menu()
{
	printf("********  菜单  *********\n");
	printf("*****               *****\n");
	printf("***** 1.玩游戏      *****\n");
	printf("***** 0.退出游戏    *****\n");
	printf("*****               *****\n");
	printf("*************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 }; //放雷
	char show[ROWS][COLS] = { 0 }; //打印雷 
	InitBoard(mine, ROWS, COLS, '0');//初始化 雷阵初始化成‘0’
	InitBoard(show, ROWS, COLS, '*');//show 初始化成 *
	SetMine(mine, ROW, COL);//放置雷

	PrintBoard(show, ROW, COL);//打印数组 show
	PrintBoard(mine, ROW, COL);//打印数组 mine

	FindMine(mine, show, ROW, COL);
	//PrintBoard(mine, ROW, COL);//打印一下雷阵

}

void  test()
{
	int input = 0;
	srand((unsigned)time(NULL));//生成随机数字
	do
	{
		menu();
		printf("请根据提示输入数字  \n");
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
			printf("输入错误，请您重新输入\n");
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