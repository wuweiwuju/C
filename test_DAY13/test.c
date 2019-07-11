#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//1.调整数组使奇数全部都位于偶数前面。
//
//题目：
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。
//void print(int* arr,int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz ; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//void move(int* arr, int x)
//{
//	int left = 0;
//	int right = x - 1;
//	int tmp = 0;
//	while (left < right)
//	{
//		//左边找数组的偶数
//		while ((left <= right) && (arr[left] % 2 == 1))
//		{
//			left++;
//		}
//		//找数组的奇数
//		while ((left <= right) && (arr[right] % 2 == 0))
//		{
//			right--;
//		}
//		//将偶数位置和奇数位置调换
//		if(left < right)
//		{
//			tmp = arr[right];
//			arr[right] = arr[left];
//			arr[left] = tmp;
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,0 };
//	print(arr,sizeof(arr)/sizeof(int));
//	move(arr, sizeof(arr) / sizeof(int));
//	print(arr,sizeof(arr) / sizeof(int));
//	system("pause");
//	return 0;
//}
//杨氏矩阵 
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
//时间复杂度小于O(N);
//数组：
//1 2 3
//2 3 4
//3 4 5
int Find_num(int arr[3][3],int sz,int* px,int* py)
{
	int x = 0;
	int y = *py - 1;
	while ((x < *py) && y>=0)
	{
		if (arr[x][y] < sz)
		{
			x++;
		}
		else if (arr[x][y] > sz)
		{
			y--;
		}
		else
		{
			*px = x;
			*py = y;
			return 1;
		}
	}
	*px = -1;
	*py = -1;
	return 0;
}
int main()
{
	int x = 3;
	int y = 3;
	int arr[3][3] = { 1,2,3,4,5,6,7,8,9 };
	int ret = Find_num(arr,7,&x,&y);
	if(ret == 1)
	printf("找到了:>%d %d\n", x, y);
	else
	printf("没找到:>%d %d\n", x, y);
	system("pause");
	return 0;
}