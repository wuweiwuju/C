#include"Contact.h"
void menu()
{
	printf("************************\n");
	printf("***1.���      2.ɾ��***\n");
	printf("***3.����      4.�޸�***\n");
	printf("***5.��ʾ      6.���***\n");
	printf("***7.����      0.exit***\n");
	printf("************************\n");
}
enum //����ö��������������#define
{
	Exit,
	Add,
	Del,
	Search,
	Modify,
	Show,
	Clear,
	Sort
};
int main()
{
	contact con;
	int input = 0;
	InitContact(&con);
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		printf("\n");
		switch (input)
		{
		case Exit:
			printf("�˳�����\n");
			return 0;
		case Add:
			AddContact(&con);
			break;
		case Del:
			DelContact(&con);
			break;
		case Search:
			SearchContact(&con);
			break;
		case Modify:
			ModifyContact(&con);
			break;
		case Show:
			ShowContact(&con);
			break;
		case Clear:
			ClearContact(&con);
			break;
		case Sort:
			SortContact(&con);
			break;
		default:
			printf("ѡ������������ѡ��\n");
			break;
		}
		
	} while (input);
	system("pause");
	return 0;
}