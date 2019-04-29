#define _CRT_SECURE_NO_WARNINGS 1
//实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定，
//输入9，输出9 * 9口诀表，输入12，输出12 * 12的乘法口诀表。
#include<stdio.h>
#include<stdlib.h>
int mul_(int n)
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%-2d ", j, i, i * j);
		}
		printf("\n");
	}
}
int main()
{
	int n = 0;
	int ret = 0;
	printf("请输入一个数:> ");
	scanf_s("%d", &n);
	ret = mul_(n);
	system("pause");
	return 0;
}