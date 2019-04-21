#include"game.h"
void menu()
{
	printf("****************************\n");
	printf("***  1.play     0.exit   ***\n");
	printf("****************************\n");
}
//玩家赢---'X'
//电脑赢---'0'
//平局---'Q'
//继续---' '
void game()
{
	char board[ROW][COL] = { 0 };
	char ret = 0;
	InitBoard(board, ROW, COL);//初始化数组
	DisplayBoard(board, ROW, COL);//打印数组-界面
	while (1)
	{
		PlayerMove(board, ROW, COL);
		ret=IsWin(board, ROW, COL);
		if (ret != ' ')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
		ComputerMove(board, ROW, COL);
		ret=IsWin(board, ROW, COL);
		if (ret != ' ')
		{
			break;
		}
		DisplayBoard(board, ROW, COL);
	}
	DisplayBoard(board, ROW, COL);
	if (ret == 'X')
	{
		printf("玩家赢\n");
	}
	else if (ret == '0')
	{
		printf("电脑赢\n");
	}
	else if (ret == 'Q')
	{
		printf("平局\n");
	}
}

void test()
{
	int input = 0;
	srand((unsigned int)(time(NULL)));
	do
	{
		menu();
		printf("请选择:> ");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择无效，请重新选择\n");
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