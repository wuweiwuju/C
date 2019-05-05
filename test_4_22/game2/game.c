#include"game.h"

void Initboard(char board[ROWS][COLS], int rows, int cols, char set)
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
void Displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("------------------------\n");
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("------------------------\n");
}

void Setmine(char mine[ROWS][COLS], int row, int col)
{
	int count = 10;
	while (count)
	{
		int i=rand() % row+1;
		int j=rand() % col+1;
		if (mine[i][j] == '0')
		{
			mine[i][j] = '1';
			count--;
		}
	}
}
int GetmineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y + 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1]-8*'0';
}
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col- Easy_Count)
	{
		printf("����������\n");
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("�㱻ը���ˣ���Ϸ����\n");
				Displayboard(mine, ROW, COL);
				break;
			}
			else
			{
				     //ͳ��x,y��Χ�ж��ٸ���
				     char count = GetmineCount(show, x, y);
					 show[x][y]=count + '0';
					 Displayboard(show, ROW, COL);
					 win++;
			}
		}
		else
		{
			printf("���������Ƿ������������룡\n");
		}
	}
	if (win == row * col - Easy_Count)
	{
		printf("��ϲ�㣬ɨ�׳ɹ�\n");
		Displayboard(mine, ROW, COL);
	}

}
