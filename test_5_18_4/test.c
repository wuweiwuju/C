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
void sort(int* a, int sz)
{
	int i = 0;
	int j = sz-1;
	for (i = 0; i != j; i++)
	{
		if (a[i] % 2 != 0)
			continue;
		else
		{
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
			if (a[j] % 2 == 0)
				j--;
			    i--;
		}
	}
}
int main()
{
	int a[] = { 1,9,4,2,6,3,5,7 };
	int sz = sizeof(a) / sizeof(a[0]);
	int i;
	sort(a, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}
