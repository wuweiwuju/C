#include"Seqlist.h"
void menu()
{
	printf("****************************************************\n");
	printf("*****1. 尾插       *********2.   尾删        *******\n");
	printf("*****3. 头插       *********4.   头删        *******\n");
	printf("*****5. 查找       *********6.   插入        *******\n");
	printf("*****7. 删除       *********8.   移除        *******\n");
	printf("*****9. 替换       *********10.  释放        *******\n");
	printf("*****11.冒泡排序   *********12.  二分查找    *******\n");
	printf("*****13.移除相同   ********* 0.   exit       *******\n");
	printf("****************************************************\n");

}
void test()
{
	int input = 0;
	size_t ret = 0;
	size_t pos = 0;
	SLDataType x = 0;
	Seqlist psl;
	SeqlistInit(&psl);
	Seqlistprint(&psl);
	do
	{
		menu();
		printf("请选择:> ");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			{
				printf("请选择要插入的数:> ");
				scanf_s("%d", &x);
				SeqlistPushBack(&psl, x);
				Seqlistprint(&psl);
				break;
			}
		case 2:
			{
				SeqlistPopBack(&psl);
				Seqlistprint(&psl);
				break;
			}
		case 3:
			{
				printf("请选择要插入的数:> ");
				scanf_s("%d", &x);
				SeqlistPushFront(&psl, x);
				Seqlistprint(&psl);
				break;
			}
		case 4:
			{
				SeqlistPopFront(&psl);
				Seqlistprint(&psl);
				break;
			}
		case 5:
			{
				printf("请输入要查找的数:>");
				scanf_s("%d", &x);
				ret = SeqlistFind(&psl,x);
				printf("%d\n", ret);
				break;
			}
		case 6:
			{
				printf("请输入插入的位置和插入的数:>");
				scanf_s("%d %d", &pos, &x);
				SeqlistInsert(&psl, pos, x);
				Seqlistprint(&psl);
				break;
			}
		case 7:
			{
				printf("请输入删除的位置:>");
				scanf_s("%d", &pos);
				SeqlistErase(&psl, pos);
				Seqlistprint(&psl);
				break;
			}
		case 8:
			{
				printf("请输入要移除的数:>");
				scanf_s("%d", &x);
				SeqlistRemove(&psl, x);
				Seqlistprint(&psl);
				break;
			}
		case 9:
			{
				printf("请输入更改的位置和更改的数:>");
				scanf_s("%d %d", &pos, &x);
				SeqlistModify(&psl, pos, x);
				Seqlistprint(&psl);
				break;
			}
		case 10:
			{
				SeqlistDestory(&psl);
				Seqlistprint(&psl);
				break;
			}
		case 11:
		{
			Seqlistprint(&psl);
			SeqlistBubbleSort(&psl);
			Seqlistprint(&psl);
			break;
		}
		case 12:
		{
			printf("请输入要查找的数:>");
			scanf_s("%d", &x);
			ret = SeqlistBinaryFind(&psl,x);
			printf("%d\n", ret);
			break;
		}
		case 13:
		{
			printf("请输入要移除的数:>");
			scanf_s("%d", &x);
			SeqlistRemoveAll(&psl, x);
			Seqlistprint(&psl);
			break;
		}
		case 0:
		{
			return 0;
		}
		default:
			printf("选择有误！请重新选择！\n");
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