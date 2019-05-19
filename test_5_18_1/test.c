#define _CRT_SECURE_NO_WARNINGS 1

//不使用（a + b） / 2这种方式，求两个数的平均值
#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	printf("%d\n", (a & b) + ((a ^ b) >> 1));
	system("pause");
	return 0;
}
