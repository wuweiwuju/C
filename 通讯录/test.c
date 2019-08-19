#include"Contact.h"
void menu()
{
	printf("************************\n");
	printf("***1.添加      2.删除***\n");
	printf("***3.查找      4.修改***\n");
	printf("***5.显示      6.清空***\n");
	printf("***7.排序      0.exit***\n");
	printf("************************\n");
}
enum //不加枚举名作用类似于#define
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
		printf("请选择:>");
		scanf("%d", &input);
		printf("\n");
		switch (input)
		{
		case Exit:
			printf("退出程序\n");
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
			printf("选择有误，请重新选择\n");
			break;
		}
		
	} while (input);
	system("pause");
	return 0;
}