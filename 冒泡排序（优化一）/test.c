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
	for (i = 0; i < sz - 1; i++)
	{
		int flag = 0;
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				swap(&arr[j], &arr[j+1]);
				flag++;
			}
		}
		if (flag == 0)
			break;
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
	int array[] = { 1,2,3,4,5,6,7 };
	int size = sizeof(array) / sizeof(int);
	bub_print(array, size);
	bub_sort(array,size);
	bub_print(array, size);
	system("pause");
	return 0;
}