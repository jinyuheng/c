#define _CRT_SECURE_NO_WARNINGS 1

#include "game2.h"
void menu()
{
	printf("********  �˵�  *********\n");
	printf("*****               *****\n");
	printf("***** 1.����Ϸ      *****\n");
	printf("***** 0.�˳���Ϸ    *****\n");
	printf("*****               *****\n");
	printf("*************************\n");
}

void game()
{
	char mine[ROWS][COLS] = { 0 }; //����
	char show[ROWS][COLS] = { 0 }; //��ӡ�� 
	InitBoard(mine, ROWS, COLS, '0');//��ʼ�� �����ʼ���ɡ�0��
	InitBoard(show, ROWS, COLS, '*');//show ��ʼ���� *
	SetMine(mine, ROW, COL);//������

	PrintBoard(show, ROW, COL);//��ӡ���� show
	PrintBoard(mine, ROW, COL);//��ӡ���� mine

	FindMine(mine, show, ROW, COL);
	//PrintBoard(mine, ROW, COL);//��ӡһ������

}

void  test()
{
	int input = 0;
	srand((unsigned)time(NULL));//�����������
	do
	{
		menu();
		printf("�������ʾ��������  \n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������������������\n");
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