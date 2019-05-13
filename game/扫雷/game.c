
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
	int count = Easy_Count;
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
int get_mine(char mine[ROWS][COLS], int x, int y)
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
void OpenMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)//չ��һƬ
{
	int ret = 0;
	ret = get_mine(mine, x, y);
	if (ret == 0)
	{
		show[x][y] = '0';
		if (x > 0 && y + 1 <= col && show[x][y + 1] == '*')
			OpenMine(mine, show, row, col, x, y + 1);
		if (x - 1 > 0 && y + 1 <= col && show[x - 1][y + 1] == '*')
			OpenMine(mine, show, row, col, x - 1, y + 1);
		if (x - 1 > 0 && y > 0 && show[x - 1][y] == '*')
			OpenMine(mine, show, row, col, x - 1, y);
		if (x - 1 > 0 && y - 1 > 0 && show[x - 1][y - 1] == '*')
			OpenMine(mine, show, row, col, x - 1, y - 1);
		if (x > 0 && y - 1 > 0 && show[x][y - 1] == '*')
			OpenMine(mine, show, row, col, x, y - 1);
		if (x + 1 <= row && y - 1 > 0 && show[x + 1][y - 1] == '*')
			OpenMine(mine, show, row, col, x + 1, y - 1);
		if (x + 1 <= row && y > 0 && show[x + 1][y] == '*')
			OpenMine(mine, show, row, col, x + 1, y);
		if (x + 1 <= row && y + 1 <= col && show[x + 1][y + 1] == '*')
			OpenMine(mine, show, row, col, x + 1, y + 1);
	}
	else
	{
		show[x][y] = get_mine(mine, x, y) + '0';
	}
}
void First_SafeMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)//ȷ����һ��������
{
	int x = 0;
	int y = 0;
	int ret = 1;
	int count = 0;
	printf("������Ҫ�Ų������:");
	scanf_s("%d%d", &x, &y);
	if (mine[x][y] == '1')//���Ϊ�ף����Ϊû����
	{
		mine[x][y] = '0';
		count = get_mine(mine, x, y);
		show[x][y] = count + '0';
		while (ret)//�������һ����
		{
			x = rand() % ROW + 1;
			y = rand() % COL + 1;
			if (mine[x][y] == '0')
			{
				mine[x][y] = '1';
			}
			ret--;
		}
	}
	OpenMine(mine, show, row, col, x, y);
	Displayboard(show, row, col);
}
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < row * col - Easy_Count)
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
				int count = get_mine(mine, x, y);
				show[x][y] = count + '0';
				OpenMine(mine, show, row, col, x, y);
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