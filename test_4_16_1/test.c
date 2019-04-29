#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int fib_seq(int n)
{
	if (n == 1 || n == 2)
	{
		return 1;
	}
	else
	{
		return fib_seq(n - 1) + fib_seq(n - 2);
	}
}
int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret=fib_seq( n );
	printf("%d\n", ret);
	system("pause");
	return 0;
}