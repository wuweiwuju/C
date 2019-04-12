#define _CRT_SECURE_NO_WARNINGS 1
//创建一个数组，
//实现函数init（）初始化数组、
//实现empty（）清空数组、
//实现reverse（）函数完成数组元素的逆置。
//要求：自己设计函数的参数，返回值。
#include<stdio.h>
#include<stdlib.h>
void init(int arr[],int size)       //初始化数组
{
	int a = 0;
	for (a = 1; a <= size; a++)
	{
		arr[a] = a;
		printf("%d ", arr[a]);
	}
	printf("\n");
}
void empty(int arr[], int size)     //清空数组
{
	int a = 0;
	for (a = 1; a <= size; a++)
	{
		arr[a] = 0;
		printf("%d ", arr[a]);
	}
	printf("\n");
}
void reverse(int arr[], int size)       //逆置数组
{
	int a = 0;
	int left = 0;
	int right = size - 1;
	for (a = 0; a < size; a++)
	{
		while (left < right)
		{
			int tmp = arr[left];
			arr[left] = arr[right];
			arr[right] = tmp;
			left++;
			right--;
		}
		printf("%d ", arr[a]);
	}
	printf("\n");

}
void menu()
{
	printf("********************\n");
	printf("****1. 初始化数组***\n");
	printf("****2. 清空数组  ***\n");
	printf("****3. 数组的逆置***\n");
	printf("********************\n");

}
int main()
{
	int arr[] = { 1,2,3,4,5,6 };
	int input = 0;
	int size = sizeof(arr) / sizeof(arr[0]);
	do
	{
		menu();
		printf("请选择：\n");
		scanf_s("%d", &input);
		
		switch (input)
		{
		case 1:
		{
			init(arr, size);
			break;
		}
		case 2:
		{
			empty(arr, size);
			break;
		}
		case 3:
		{
			reverse(arr, size);
			break;
		}
		default:
		{
			printf("选择无效，请重新选择\n");
			break;
		}
		}
	} while (input);
	system("pause");
	return 0;
}