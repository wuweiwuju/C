#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//���ַ������ҳ���һ��ֻ����һ�ε��ַ�
//ʱ�临�Ӷ�O��n�����磺��abaccdeff��  ����� 'b'
char firstNotRepeate(char* str) 
{
	const int size = 256;//��ʾ 
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




//����һ���������飬������������Ҳ�и�����������һ�����߶���������һ�������顣��
//���к�����������ֵʱ�临�Ӷ�O��n��
//���磺{1,-2,3,10,-4,7,2,-5}   ���Ϊ  18
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
