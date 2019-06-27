#define _CRT_SECURE_NO_WARNINGS 1
//实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
//方法一
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//void left_remove(char* p, int n, int len)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		int j = 0;
//		int tmp = p[0];
//		for (j = 0; j < len - 1; j++)
//		{
//			p[j] = p[j + 1];
//		}
//		p[len - 1] = tmp;
//	}
//}
//int main()
//{
//	char p[] = "ABCD";
//	int n = 0;
//	int len = strlen(p);
//	printf("左旋前字符串为:>");
//	printf("%s\n", p);
//	printf("左旋几位:>");
//	scanf_s("%d", &n);
//	while (n<1 || n>len - 1)
//	{
//		if (n == len || n == 0)
//		{
//			printf("左旋后字符串为:>");
//			printf("%s", p);
//			return 0;
//		}
//		else
//		{
//			printf("输入有误！\n");
//			scanf_s("%d", &n);
//		}
//	}
//	left_remove(p, n, len);
//	printf("旋转后：%s\n", p);
//	system("pause");
//	return 0;
//}
//方法二  三步旋转法
//void reserve(char* left,char* right)
//{
//	while (left < right)
//	{
//		char tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//void left_remove(char* p, int n, int len)
//{
//	reserve(p, p + n - 1);
//	reserve(p + n, p + len - 1);
//	reserve(p, p + len - 1);
//}
//int main()
//{
//	char p[] = "ABCD";
//	int n = 0;
//	int len = strlen(p);
//	printf("左旋前字符串为:>");
//	printf("%s\n", p);
//	printf("左旋几位:>");
//	scanf_s("%d", &n);
//	while (n<1 || n>len - 1)
//	{
//		if (n == len || n == 0)
//		{
//			printf("左旋后字符串为:>");
//			printf("%s", p);
//			return 0;
//		}
//		else
//		{
//			printf("输入有误！\n");
//			scanf_s("%d", &n);
//		}
//	}
//	left_remove(p, n, len);
//	printf("旋转后：%s\n", p);
//	system("pause");
//	return 0;
//}
//方法三 指针
void left_remove(char arr[], int n)     
{
	char arr1[5] = { 0 };
	char* mov1 = arr;
	char* mov2 = arr;
	char* res1 = arr1;
	char* res2 = arr1;
	while (n--)
	{
		*res1++ = *mov2++;
	}
	while (*mov2)
	{
		*mov1++ = *mov2++;
	}
	while (*mov1)
	{
		*mov1++ = *res2++;
	}
}
int main()
{
	char p[] = "ABCD";
	int n = 0;
	int len = strlen(p);
	printf("左旋前字符串为:>");
	printf("%s\n", p);
	printf("左旋几位:>");
	scanf_s("%d", &n);
	while (n<1 || n>len - 1)
	{
		if (n == len || n == 0)
		{
			printf("左旋后字符串为:>");
			printf("%s", p);
			return 0;
		}
		else
		{
			printf("输入有误！\n");
			scanf_s("%d", &n);
		}
	}
	left_remove(p, n);
	printf("旋转后：%s\n", p);
	system("pause");
	return 0;
}