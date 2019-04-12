#define _CRT_SECURE_NO_WARNINGS 1
//使用函数实现两个数的交换。

#include<stdio.h>
#include<stdlib.h>
int swap(int* a, int* b)
{
	int temp = *b;
	*b = *a;
	*a = temp;
}

int main()
{
	int a = 5;
	int b = 6;
	int ret = 0;
	printf("a=%d b=%d\n", a, b);
	ret= swap(&a, &b);
	printf("a=%d b=%d\n", a, b);
	system("pause");
	return 0;
}