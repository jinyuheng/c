#define _CRT_SECURE_NO_WARNINGS 1
//test  ����Ų��ԵĴ���
#include "game1.h"
//��Ϸ���붼��game����

void menu()
{
	printf("*************************\n");
	printf("***  1.play           ***\n");
	printf("***  0.exit           ***\n");
	printf("*************************\n");
}
//˼·  ��ʼ��  ��ӡ����  ������� �ж���Ӯ  ������  �ж���Ӯ
void game()
{
	char board[ROW][COL] = { 0 };//����

	char tmp = 0;//����
	InitBoard(board, ROW, COL);//��ʼ��
	PrintBoard(board, ROW, COL);//��ӡ

	//�жϷ���ֵ���ж���Ӯ��ѭ��
	while (1)
	{
		PlayMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);//��ӡ
		tmp = CheckWin(board, ROW, COL);
		if (tmp != 'C')
		{
			break;
		}
		CompMove(board, ROW, COL);
		PrintBoard(board, ROW, COL);//��ӡ
		tmp = CheckWin(board, ROW, COL);
		if (tmp != 'C')
		{
			break;
		}
	}
	if (tmp == '*')
	{
		printf("��Ӯ��  \n");
	}
	else if (tmp == '#')
	{
		printf("����Ӯ��  \n");
	}
	else if (tmp == 'Q')
	{
		printf("ƽ��\n");
	}
}

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��  \n");
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
			printf("ѡ�����  \n");
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