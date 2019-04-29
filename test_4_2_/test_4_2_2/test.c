#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 2;
	int b = 4;
	a = a ^ b;
	b = b ^ a;
	a = b ^ a;
	printf("a=%d,b=%d\n", a, b);
	system("pause");
	return 0;
}