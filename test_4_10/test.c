#define _CRT_SECURE_NO_WARNINGS 1

//2.д����������������������в�����Ҫ�����֣�
//�ҵ��˷����±꣬�Ҳ������� - 1.���۰���ң�
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10};
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int k = 6;
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
			printf("�ҵ��ˣ��±��ǣ� %d\n", mid);
			break;
		}
	}
	if (left > right)
	{
		printf("û�ҵ�\n");
	}
	system("pause");
	return 0;
}
