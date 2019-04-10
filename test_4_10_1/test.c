#define _CRT_SECURE_NO_WARNINGS 1
//写代码可以在整型有序数组中查找想要的数字，
//找到了返回下标，找不到返回 - 1.（折半查找）
#include<stdio.h>
#include<stdlib.h>
int binary_search(int arr[], int k, int left, int right)
{
	int mid = 0;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
	}
	if (left > right)
	{
		return -1;
	}
}
int main()
{
	int mid=0;
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int k = 6;
	int ret = binary_search(arr, k, left, right);
		if (ret == -1)
		{
			printf("没找到\n");
		}
		else
		{
			printf("找到了，下标是：%d\n", ret);
		}
	system("pause");
	return 0;
}