#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//1.ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
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
//	printf("��תǰ�ַ���Ϊ:>%s\n", str);
//	printf("Ҫ��������:>");
//	scanf_s("%d", &k);
//	printf("\n");
//	while (1)
//	{
//		if (k >= 0 && k <= strlen(str))
//		{
//			left_remove(str, k, strlen(str));
//			printf("��ת���ַ���Ϊ:>%s\n", str);
//			break;
//		}
//		else
//		{
//			printf("����ĳ�����Χ�����������룡\n");
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
//	printf("����ǰ�ַ���Ϊ:>");
//	printf("%s\n", p);
//	printf("������λ:>");
//	scanf_s("%d", &n);
//	while (n<1 || n>len - 1)
//	{
//		if (n == len || n == 0)
//		{
//			printf("�������ַ���Ϊ:>");
//			printf("%s", p);
//			return 0;
//		}
//		else
//		{
//			printf("��������\n");
//			scanf_s("%d", &n);
//		}
//	}
//	left_remove(p, n, len);
//	printf("��ת��%s\n", p);
//	system("pause");
//	return 0;
//}

