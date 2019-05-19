#define _CRT_SECURE_NO_WARNINGS 1
//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。请找出这个数字

#include<stdio.h>
int main()
{
	int arr[] = { 1,3,3,1,4,6,4,5,5 };
	int i = 0;
	int len = sizeof(arr) / sizeof(arr[0]);
	for (i = 1; i < len; i++)
	{
		arr[0] = arr[0] ^ arr[i];
	}
	printf("the single number is:%d", arr[0]);
	return 0;
}
