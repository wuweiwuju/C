#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//1.实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
//A DCB
// BCDA
//void reserve(char* left,char* right)
//{
//	assert(left);
//	assert(right);
//	while (left<right)
//	{
//		int tmp = *left;
//		*left = *right;
//		*right = tmp;
//		left++;
//		right--;
//	}
//}
//void left_remove(char* str,int x,int sz)
//{
//	reserve(str,str+x-1);
//	reserve(str+x, str + sz-1);
//	reserve(str, str + sz-1);
//}
//int main()
//{
//	char str[] = "ABCD";
//	int k = 0;
//	printf("旋转前字符串为:>%s\n", str);
//	printf("要左旋几个:>");
//	scanf_s("%d", &k);
//	printf("\n");
//	while (1)
//	{
//		if (k >= 0 && k <= strlen(str))
//		{
//			left_remove(str, k, strlen(str));
//			printf("旋转后字符串为:>%s\n", str);
//			break;
//		}
//		else
//		{
//			printf("输入的超出范围，请重新输入！\n");
//			scanf_s("%d", &k);
//		}
//	}
//	system("pause");
//	return 0;
//}
//void left_remove(char* p, int n, int len)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		int j = 0;
//		int tmp = p[0];
//		/*for (j = 0; j < len - 1; j++)
//		{
//			p[j] = p[j + 1];
//		}*/
//		memmove(p, p + 1, len - 1);
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

