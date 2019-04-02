#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 2, b = 4, c = 0;
	c = a;
	a = b;
	b = c;
	printf(" a=%d\n b=%d\n ", a, b);
	system("pause");
	return 0;
}