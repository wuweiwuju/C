#define _CRT_SECURE_NO_WARNINGS 1
//����һ�����飬
//ʵ�ֺ���init������ʼ�����顢
//ʵ��empty����������顢
//ʵ��reverse���������������Ԫ�ص����á�
//Ҫ���Լ���ƺ����Ĳ���������ֵ��
#include<stdio.h>
#include<stdlib.h>
void init(int arr[],int size)       //��ʼ������
{
	int a = 0;
	for (a = 1; a <= size; a++)
	{
		arr[a] = a;
		printf("%d ", arr[a]);
	}
	printf("\n");
}
void empty(int arr[], int size)     //�������
{
	int a = 0;
	for (a = 1; a <= size; a++)
	{
		arr[a] = 0;
		printf("%d ", arr[a]);
	}
	printf("\n");
}
void reverse(int arr[], int size)       //��������
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
	printf("****1. ��ʼ������***\n");
	printf("****2. �������  ***\n");
	printf("****3. ���������***\n");
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
		printf("��ѡ��\n");
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
			printf("ѡ����Ч��������ѡ��\n");
			break;
		}
		}
	} while (input);
	system("pause");
	return 0;
}