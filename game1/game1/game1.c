#define _CRT_SECURE_NO_WARNINGS 1
#include "game1.h"

void InitBoard(char board[ROW][COL], int row, int col)//��ʼ��
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)//��������
	{
		for (j = 0; j <col; j++)
		{//�ԾŸ��ո���и�ֵ
			board[i][j] = ' ';//����
		}
	}
}

void PrintBoard(char board[ROW][COL], int row, int col)//��ӡ
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		//��ӡ�ո��|

		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");

		//��ӡ�ָ������
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
//������Ҫһ������  ��Ҫ֪���к���
void CompMove(char board[ROW][COL], int row, int col)//������
{
	int x = 0;
	int y = 0;
	printf("������ \n");

	while (1)
	{
		x = rand() % row;//rand ����������Ĺؼ���  ������Ҫ���ڲ����ļ��ж���
		y = rand() % col;//��Ϊ�����������±���0-2 ����Ҫģ3
		if (board[x][y] == ' ')//�ж��Ƿ�ռ����
		{
			board[x][y] = '#';
			break;
		}
	}
}

void PlayMove(char board[ROW][COL], int row, int col)  //�����
{

	int x = 0;
	int y = 0;

	printf("�����  \n");
	while (1)
	{

		scanf("%d %d", &x, &y);

		if (x >= 1 && x <= row&&y >= 1 && y <= col)//����λ�����±�֮��Ĺ�ϵ
		{
			if (board[x - 1][y - 1] != ' ')//����Ҫ������ƥ��
			{
				printf("��λ���Ѿ���ռ��\n");
			}
			else
			{
				board[x - 1][y - 1] = '*';
				break;
			}
		}
		else
		{
			printf("���������������������\n");
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

char CheckWin(char board[ROW][COL], int row, int col)//�ж���Ӯ
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

	if (Checkfull(board, row, col) == 1)//��ռ�� ����ƽ��

	{
		return 'Q';
	}
	//��Ϸ����
	return 'C';
}
