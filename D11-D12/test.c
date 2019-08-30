#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//一个数组中  有两个数字出现一次，其余出现两次 ，找出这两个数
//例如{1,3,5,7,1,3,5,9}    找出7  和  9
//void Find_num(int* arr,int sz)
//{
//	int num1 = 0;
//	int num2 = 0;
//	int pos = 0;
//	int tmp = 0;
//
//	for (int i = 0; i < sz; i++)
//	{
//		tmp ^= arr[i];
//	}
//
//	//tmp = 5^6
//
//	for (int i = 0; i < 32; i++)
//	{
//		if ((tmp >> i) == 1)
//		{
//			pos = i;
//			break;
//		}
//	}
//	//第pos位不同
//
//	for (int i = 0; i < sz; i++)
//	{
//		if ((arr[i] >> pos) == 1)
//		{
//			num1 ^= arr[i];
//		}
//	}
//	num2 = tmp ^ num1;
//	printf("%d %d\n", num1, num2);
//}
//int main()
//{
//	int array[] = { 1,3,5,7,1,3,5,9 };
//	Find_num(array,sizeof(array)/sizeof(int));
//	system("pause");
//	return 0;
//}
//对于一个字符串，请设计一个高效算法，找到第一次重复的字符
//例如：“qywyer23tdd”返回：y
//char str_replace(char* str,int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		if(str[i] == str[i+1])
//		{
//
//		}
//	}
//}
//int main()
//{
//	char* str = "qywyer23tdd";
//	char c = str_replace(str,strlen(str));
//	printf("%c\n", c);
//	system("pause");
//	return 0;
//}

//char firstNotRepeate(char* str,int SIZE)
//{
//	char* pHashKey = str; 
//	int hashTable[12] = {0};
//	int i; 
//	for (i = 0; i < SIZE; i++) 
//	{ 
//		hashTable[i] = 0;
//	}
//	while (*(pHashKey) != '\0')
//	{
//		hashTable[*(pHashKey++)]++;
//	}
//	pHashKey = str;
//	while (*(pHashKey) != '\0') 
//	{
//			if (hashTable[*(pHashKey)] == 2) 
//			{ 
//				return *(pHashKey);
//			}
//			pHashKey++;
//	}
//	return '\0';
//}
//int main() 
//{ 
//	char* str = "qywyer23tdd";
//	char ch = firstNotRepeate(str, strlen(str));
//	printf("%c\n", ch);
//	return 0;
//}
