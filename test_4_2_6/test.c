#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 0, b = 0, t = 0;
	printf("请输入两个整数：\n");
	scanf("%d %d", &a, &b);
	if (a < b)
	{
		t = b;
		b = a;
		a = t;
	}
	while (a%b!=0)
	{
		t = a % b;
		a = b;
		b = t;
	}
	printf("这两个整数的最大公约数是：%d\n", b);
	system("pause");
	return 0;
}