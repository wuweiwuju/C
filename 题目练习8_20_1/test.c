#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//编写函数，求第n个斐波那契数的值（非递归）
int Fib_n(int n)
{
	int i = 0;
	int f1 = 1, f2 = 1, f3 = 0;
	if (n == 1 || n == 2)
		return 1;
	for (i = 0; i < n - 2; i++)
	{
		f3 = f1 + f2;
		f1 = f2;
		f2 = f3;
	}
	return f3;
}
int main()
{
	int ret = 0;
	int n = 0;
	scanf("%d", &n);
	ret = Fib_n(n);
	printf("%d\n", ret);
	system("pause");
	return 0;
}