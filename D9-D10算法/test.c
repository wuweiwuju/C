#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//在字符串中找出第一个只出现一次的字符
//时间复杂度O（n）例如：“abaccdeff”  则输出 'b'
char firstNotRepeate(char* str) 
{
	const int size = 256;//表示 
	int hashTable[256]; 
	int i;
	if(str == NULL)
	{ 
		return '\0';
	}
	for(i = 0;i < size;i++) 
	{
		hashTable[i] = 0;
	}
	char* pHashKey = str; 
	while (*(pHashKey) != '\0') 
	{
		hashTable[*(pHashKey++)]++;
	}
	pHashKey = str;
	while (*(pHashKey) != '\0')
	{ 
		if (hashTable[*(pHashKey)] == 1)
		{ 
			return *(pHashKey); 
		}
		pHashKey++; 
	}
	return '\0';
}

int main()
{
	char* str = "abaccdeff";
	char ret = firstNotRepeate(str);
	printf("%c\n", ret);
	system("pause");
	return 0;
}




//输入一个整形数组，数组中有正数也有负数，数组中一个或者多个整数组成一个子数组。求
//所有和子数组的最大值时间复杂度O（n）
//例如：{1,-2,3,10,-4,7,2,-5}   输出为  18
//int MAX_Arry(int* arr, int sz)
//{
//	int max = arr[0];
//	int sum = arr[0];
//	int i = 1;
//	if (arr == NULL || sz < 1)
//		return 0;
//	for (i = 1; i < sz; i++)
//	{
//		if (sum < 0)//
//			sum = arr[i];//3
//		else
//		{
//			sum += arr[i]; // -1  3+10=13 sum = 9 sum = 16
//		}
//		if (max < sum)
//			max = sum;//3  13 16
//	}
//	return max;
//}
//int main()
//{
//	int array[] = { 1,-2,3,10,-4,7,2,-5 };
//	//int array[] = {1};
//	int ret = MAX_Arry(array, sizeof(array)/sizeof(array[0]));
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}
