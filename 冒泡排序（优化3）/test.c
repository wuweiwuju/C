#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
void  swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void bub_sort(int* arr, int sz)
{
	int i = 0;
	int k = sz - 1;
	int pos = 0;
	int n = 0;
	int jdp = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int num = 0;
		for (int j = 0; j < k; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				num++;
				pos = j;//记录最后一次交换的位置
			}
		}
		if (num == 0)
			break;
		else
		{
			k = pos;
			num = 0;
			for (int p = k; p > n; p--)
			{
				if (arr[p] < arr[p - 1])
				{
					swap(&arr[p], &arr[p - 1]);
					num++;
					jdp = p;
				}
			}
			n = jdp;
			if (num == 0)
				return;
		}
	}
}
void bub_print(int* array, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}
int main()
{
	int array[] = { 1,2,3,4,5,6,8,7,0 };
	int size = sizeof(array) / sizeof(int);
	bub_sort(array, size);
	bub_print(array, size);
	system("pause");
	return 0;
}