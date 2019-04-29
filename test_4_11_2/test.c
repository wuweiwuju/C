#define _CRT_SECURE_NO_WARNINGS 1
//实现一个函数判断year是不是润年。

#include<stdio.h>
#include<stdlib.h>
int leap_year(int year)
{
	if ((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0))
	{
		printf("是闰年\n");
	}
	else
	{
		printf("不是闰年\n");
	}
}
int main()
{
	int year = 0;
	int ret = 0;
	scanf_s("%d", &year);
	ret=leap_year(year);
	system("pause");
	return 0;
}