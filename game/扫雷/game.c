
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
void OpenMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col, int x, int y)//展开一片
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
void First_SafeMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)//确保第一个不踩雷
{
	int x = 0;
	int y = 0;
	int ret = 1;
	int count = 0;
	printf("请输入要排查的坐标:");
	scanf_s("%d%d", &x, &y);
	if (mine[x][y] == '1')//如果为雷，则改为没有雷
	{
		mine[x][y] = '0';
		count = get_mine(mine, x, y);
		show[x][y] = count + '0';
		while (ret)//随机生成一个雷
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
		printf("请输入坐标\n");
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("你被炸死了，游戏结束\n");
				Displayboard(mine, ROW, COL);
				break;
			}
			else
			{
				//统计x,y周围有多少个雷
				int count = get_mine(mine, x, y);
				show[x][y] = count + '0';
				OpenMine(mine, show, row, col, x, y);
				Displayboard(show, ROW, COL);
				win++;
			}
		}
		else
		{
			printf("输入的坐标非法，请重新输入！\n");
		}
	}
	if (win == row * col - Easy_Count)
	{
		printf("恭喜你，扫雷成功\n");
		Displayboard(mine, ROW, COL);
	}
}