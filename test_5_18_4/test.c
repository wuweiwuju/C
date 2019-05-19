#define _CRT_SECURE_NO_WARNINGS 1
//调整数组使奇数全部都位于偶数前面。
//
//题目：
//
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。

#include<stdio.h>
#include<stdlib.h>
//int main()
//{
//	int arr[100] = { 0 };
//	int i = 0;
//	int n = 0;
//	scanf_s("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		scanf_s("%d", &arr[i]);
//	}
//	for (i = 1; i <= n; i+=2)
//	{
//		printf("%d", arr[i]);
//	}
//	for (i = 2; i <= n; i += 2)
//	{
//		printf("%d", arr[i]);
//	}
//	system("pause");
//	return 0;
//}
//void Sort(int* arr, int len)
//{
//	int* start = arr;      //左边起始位置
//	int* end = arr + len - 1;     //右边起始位置
//	int i = 0;
//	int j = len - 1;
//	while (i < j)
//	{
//
//		if (arr[i] % 2 == 0) {
//			arr[i] = arr[i];
//		}
//		else {
//			++i;
//		}
//		if (arr[j] % 2 == 1) {
//			arr[j] = arr[j];
//		}
//		else {
//			--j;
//		}
//		swap(arr[i], arr[j]);
//	}
//}
//int main()
//{
//	int arr[] = { 3, 4, 7, 8, 12, 1 };
//	adjust(arr, sizeof(num) / sizeof(int));
//	for (int i = 0; i < sizeof(num) / sizeof(int); ++i)
//		printf("%d  ", tmp[i]);
//	system("pause");
//	return 0;
//}
