#define _CRT_SECURE_NO_WARNINGS 1
#include "game2.h"
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)//��ʼ������
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

void SetMine(char board[ROWS][COLS], int row, int col)  //����
{
	int count = Easy_Count;

	while (count)
	{
		int x = rand() % row + 1;  //ģrow�ó��������� 0��row ֮�������  ����Ҫ��1
		int y = rand() % col + 1;//ͬ��
		if (board[x][y] == '0')//��ֹ�ظ�����
		{
			board[x][y] = '1';
			count--;
		}
	}
}


void PrintBoard(char board[ROWS][COLS], int row, int col) //��ӡ�б�  �б� ѭ����ӡԪ��
{
	int i = 0;
	int j = 0;

	for (i = 0; i <= col; i++)//��ӡ�б�
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)//��ӡ�б�
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);//ѭ����ӡԪ��
		}
		printf("\n");
	}
}

static int CountMine(char mine[ROWS][COLS], int x, int y)//�����׵�����
{
	int count = 0;
	count = (mine[x][y - 1] + mine[x][y + 1] + mine[x - 1][y] + mine[x - 1][y - 1] + mine[x - 1][y + 1] + mine[x + 1][y - 1]
		+ mine[x + 1][y] + mine[x + 1][y + 1]) - 8 * '0';
	return count;
}



static void Openboard(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int *count)//����֮��չ��
{
	int i = 0;
	int j = 0;
	if ((x >= 1 && x <= ROW) && (y >= 1 && y <= COL))//�ж������Ƿ�Ϸ�
	{
		if (CountMine(mine, x, y) == 0)//�ж���Χ�Ƿ����ף����û����
		{
			show[x][y] = '0';
			(*count)--;
			for (i = x - 1; i <= x + 1; i++)
			{
				for (j = y - 1; j <= y + 1; j++)
				{
					if (show[i][j] == '*')//�����û��չ��
					{
						//(*count)--;
						Openboard(mine, show, i, j, count);//���õݹ�չ��
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

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)//ɨ��
{
	int x = 0;
	int y = 0;
	int count = 0;
	int num = ROW*COL - Easy_Count;
	while (1)
	{
		printf("����������  ");
		scanf("%d %d", &x, &y);
		count++;
		if ((x >= 1 && x <= row) && (y >= 1 && y <= col))
		{
			while (count == 1 && mine[x][y] == '1')//��һ������
			{
				InitBoard(mine, ROWS, COLS, '0');//���³�ʼ��
				SetMine(mine, ROW, COL);//���²���
			}
			if (mine[x][y] == '1')
			{
				printf("��Ϸ����  \n");
				break;
			}
			else
			{
				Openboard(mine, show, x, y, &num);//չ��
				PrintBoard(show, ROW, COL);
				if (num == 0)
				{
					printf("��Ӯ��\n\n");
					break;
				}
			}

		}

	}

}
