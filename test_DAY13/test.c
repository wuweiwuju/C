#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//1.��������ʹ����ȫ����λ��ż��ǰ�档
//
//��Ŀ��
//����һ���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿�֡�
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
//		//����������ż��
//		while ((left <= right) && (arr[left] % 2 == 1))
//		{
//			left++;
//		}
//		//�����������
//		while ((left <= right) && (arr[right] % 2 == 0))
//		{
//			right--;
//		}
//		//��ż��λ�ú�����λ�õ���
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
//���Ͼ��� 
//��һ����ά����.
//�����ÿ�д������ǵ����ģ�ÿ�д��ϵ����ǵ�����.
//�������������в���һ�������Ƿ���ڡ�
//ʱ�临�Ӷ�С��O(N);
//���飺
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
	printf("�ҵ���:>%d %d\n", x, y);
	else
	printf("û�ҵ�:>%d %d\n", x, y);
	system("pause");
	return 0;
}