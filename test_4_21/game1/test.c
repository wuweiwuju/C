#include"game.h"
void menu()
{
	printf("****************************\n");
	printf("***  1.play     0.exit   ***\n");
	printf("****************************\n");
}
//���Ӯ---'X'
//����Ӯ---'0'
//ƽ��---'Q'
//����---' '
void game()
{
	char board[ROW][COL] = { 0 };
	char ret = 0;
	InitBoard(board, ROW, COL);//��ʼ������
	DisplayBoard(board, ROW, COL);//��ӡ����-����
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
		printf("���Ӯ\n");
	}
	else if (ret == '0')
	{
		printf("����Ӯ\n");
	}
	else if (ret == 'Q')
	{
		printf("ƽ��\n");
	}
}

void test()
{
	int input = 0;
	srand((unsigned int)(time(NULL)));
	do
	{
		menu();
		printf("��ѡ��:> ");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ����Ч��������ѡ��\n");
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