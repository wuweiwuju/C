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
				     char count = GetmineCount(show, x, y);
					 show[x][y]=count + '0';
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
