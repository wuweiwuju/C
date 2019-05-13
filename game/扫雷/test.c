
#include"game.h"

void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	//初始化棋盘
	Initboard(mine, ROWS, COLS, '0');
	Initboard(show, ROWS, COLS, '*');
	//打印棋盘
	/*Displayboard(mine, ROW, COL);*/
	Displayboard(show, ROW, COL);
	//布置雷
	Setmine(mine, ROW, COL);
	/*Displayboard(mine, ROW, COL);*/
	
	First_SafeMine(mine, show, ROW, COL);
	//扫雷
	Findmine(mine, show, ROW, COL);

}
void menu()
{
	printf("**********************\n");
	printf("*****   1.play    ****\n");
	printf("*****   0.exit    ****\n");
	printf("**********************\n");
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
		{
			game();
			break;
		}
		case 0:
		{
			printf("退出游戏\n");
			break;
		}
		default:
		{
			printf("选择错误，请重新选择！\n");
			break;
		}
		}
	} while (input);
}
int main()
{
	test();
	system("pause");
	return 0;
}