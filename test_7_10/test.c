#define _CRT_SECURE_NO_WARNINGS 1
//一个数组中只有两个数字是出现一次，
//其他所有数字都出现了两次。
//找出这两个只出现一次的数字，编程实现。
#include<stdio.h>
#include<stdlib.h>
int Find_num(int* arr,int size,int* num1,int* num2)
{
	//全部按位与找不同
	int tmp = 0;
	int i = 0;
	int pos = 0;
	for (i = 0; i < size; i++)
	{
		tmp ^= arr[i];
	}
	//分组
	for (i = 0; i < 32; i++)
	{
		if (tmp >> i == 1)
		{
			pos = i;
			break;
		}
	}
	for (i = 0; i < size; i++)
	{
		if (((arr[i] >> pos)&1 )== 0)
		{
			*num1 ^= arr[i];
		}
	}
	//求不同值
	*num2 = *num1 ^ tmp;
}
int main()
{
	int num1 = 0;
	int num2 = 0;
	int arr[] = { 1,2,3,4,5,6,4,3,2,1 };
	Find_num(arr,sizeof(arr)/sizeof(int),&num1,&num2);
	printf("num1 = %d num2 = %d\n", num1, num2);
	system("pause");
	return 0;
}

