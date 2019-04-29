#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int Add(int x, int y)
{
	int z = x + y;
	return z;
}
int main()
{
	int num1 = 0;
	int num2 = 0;
	int sum = 0;
	printf("输入两个操作数:>");
	scanf("%d %d", &num1, &num2);
	sum = Add(x, y);
	printf("sum = %d\n", sum);
	system("pause");
	return 0;
}