#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//#include<stdio.h>
//#include<stdlib.h>
//int Bi_Search(int a[], int n, int b)//
//{//���ص���b�ĵ�һ��
//	if (n == 0)
//		return -1;
//	int low = 0;
//	int high = n - 1;
//	int last = -1;//��last��¼��һ�������������±�
//	while (low <= high)
//	{
//		int mid = low + (high - low) / 2;
//		if (a[mid] == b)
//		{
//			last = mid;
//			high = mid - 1;
//		}
//		else if (a[mid] > b)
//			high = mid - 1;
//		else
//			low = mid + 1;
//	}
//	return last;
//}
//int Bi_Search1(int a[], int n, int b)//����b�ĵ�һ����
//{
//	if (n <= 0)
//		return -1;
//	int last = -1;
//	int low = 0;
//	int high = n - 1;
//	while (low <= high)
//	{
//		int mid = low + (high - low) / 2;
//		if (a[mid] > b)
//		{
//			last = mid;
//			high = mid - 1;
//		}
//		else if (a[mid] <= b)
//		{
//			low = mid + 1;
//		}
//	}
//	system("pause");
//	return last;
//}
//���ֲ����㷨���Ҳ����ͷ���-1���ҵ��˾ͷ���ֵ
int binary_search(int* list, int left,int right,int target)
{
	int mid = 0;
	while (left <= right) 
	{
		if (left > right)//���Ҳ���
			return -1;
		int mid = left + (right-left) / 2;
		if (target == list[mid])//���ҵ�
			return mid;
		else if (target < list[mid])
			return binary_search(list, left, mid, target);
		else
			return binary_search(list, mid + 1, right, target);
	}
	printf("δ�ҵ���ֵ!");
	return -1;
}
//int binary_search(int* list, int len, int target) 
//{
//	int low = 0;
//	int hight = len - 1;
//	int middle;
//	while (low <= hight)
//	{
//		middle = (low + hight) / 2;
//		if (list[middle] = target)
//		{
//			printf("���ҵ���ֵ�������±�Ϊ:%d\n", middle);
//			return list[middle];
//		}
//		else if (list[middle] > target)
//		{
//			hight = middle - 1;
//		}
//		else if (list[middle] < target)
//		{
//			low = middle + 1;
//		}
//	}
//	printf("δ�ҵ���ֵ");
//	return -1;
//}

int main()
{
    int a[] = { 1,4,5,6,9,10,18,23 };
	int n = sizeof(a)/sizeof(int);
	int ret = binary_search(a,0,n-1,9);
	printf("ret=%d\n", ret);
	system("pause");
	return 0;
}