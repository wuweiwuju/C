#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int get_max(int a, int b)
//{
//	/*if (a > b)
//	{
//		return a;
//	}
//	return b;*/
//	return a > b ? a : b;
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int ret = 0;
//	scanf("%d %d", &a, &b);
//	ret = get_max(a, b);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}
//void swap(int a, int b)
//{
//	int tmp = 0;
//	tmp = a;
//	a = b;
//	b = tmp;
//	printf("%d %d\n", a, b);
//}
//void swap1(int* a, int* b)
//{
//	int tmp;
//	tmp = *a;
//	*a = *b;
//	*b = tmp;
//	printf("%d %d\n", *a, *b);
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	swap(a, b);
//	swap1(&a, &b);
//	system("pause");
//	return 0;
//}
//void new_line()
//{
//	printf("peng\n");
//}
//void three_line()
//{
//	int i = 0;
//	for (i = 0; i < 3; i++)
//	{
//		new_line();
//	}
//}
//int main()
//{
//
//	three_line();
//	return 0;
//}
//
//
//#include <string.h>
//int main()
//{
//	char arr[20] = "hello";
//	int ret = strlen(strcat(arr, "bit"));//这里介绍一下strlen函数
//	printf("%d\n", ret);
//	return 0;
//}
//void print(int x)
//{
//	if (x > 9)
//	{
//		print(x / 10);
//	}
//	printf("%d ", x % 10);
//}
//int main()
//{
//	int num = 0;
//	scanf("%d", &num);
//	print(num);
//	return 0;
//}

//
//int Strlen(const char* str)
//{
//	if (*str == '\0')
//		return 0;
//	else return 1 + Strlen(str + 1);
//}
//int main()
//{
//	char* p = "abcdef";
//	int len = Strlen(p);
//	printf("%d\n", len);
//	return 0;
//}
//int factorial(int n)
//{
//	if (n <= 1)
//		return 1;
//	else
//		return n * factorial(n - 1);
//}
//int fib(int n)
//{
//	if (n <= 2)
//		return 1;
//	else
//		return fib(n - 1) + fib(n - 2);
//}

//求n的阶乘
int factorial(int n)
{
	int result = 1;
	while (n > 1)
	{
		  result *= n;
		  n -= 1;
	}
	return result;
}
//求第n个斐波那契数
int fib(int n)
{
	int result;
	int pre_result;
	int next_older_result;
	result = pre_result = 1;
	while (n > 2)
	{
		n -= 1;
		next_older_result = pre_result;
		pre_result = result;
		result = pre_result + next_older_result;
	}
	return result;
}