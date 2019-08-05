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
	for (i = 0; i < sz - 1; i++)
	{
		int num = 0;
		for (int j = 0; j < k; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				num++;
				pos = j ;//记录最后一次交换的位置
			}
		}
		if (num == 0)
			break;
		else
		{
			k = pos;
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
	int array[] = { 1,2,5,3,4,8,7,9,1 };
	int size = sizeof(array) / sizeof(int);
	bub_print(array, size);
	bub_sort(array, size);
	bub_print(array, size);
	system("pause");
	return 0;
}