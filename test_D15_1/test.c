#define _CRT_SECURE_NO_WARNINGS 1
//喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，
//给20元，可以喝多少汽水。
//编程实现。
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int total = 0;
	int empty = 0;
	int money = 0;
	scanf_s("%d", &money);
	//total = money * 2 - 1;
	total = money;
	empty = money;
	while (empty > 1)
	{
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	printf("%d\n", total);
	system("pause");
	return 0;
}