#define _CRT_SECURE_NO_WARNINGS 1
//递归和非递归分别实现求n的阶乘
//非递归
//#include<stdio.h>
//#include<stdlib.h>
//int fac(int n)
//{
//	int sum = 1;
//	int i = 1;
//	for (i = 1; i <= n; i++)
//	{
//		sum *= i;
//	}
//	return sum;
//
//}
//int main()
//{
//	int n = 0;
//	scanf_s("%d", &n);
//	fac(n);
//	printf("%d\n", fac(n));
//	system("pause");
//	return 0;
//}
//递归
#include<stdio.h>
#include<stdlib.h>
int fac(int n)
{
	if (n == 1 || n == 0)
	{
		return 1;
	}
	else
	{
		return fac(n-1)*n;
	}
}
int main()
{
	int n = 0;
	scanf_s("%d", &n);
	fac(n);
	printf("%d\n", fac(n));
	system("pause");
	return 0;
}