#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//��һ����������������Ԫ��ֵ���Ϊk�����֣�����������Ԫ�ص��±ꡣʱ�临�Ӷ�O(n)
//�ռ临�Ӷ�O��1��
#include <stdlib.h>
#include<math.h>
//void sumk(int* arr, int len, int* num1, int* num2, int key)
//{
//	int i = 0;
//	int j = len - 1;
//	while (i < j)
//	{
//		if (arr[i] + arr[j] > key)
//		{
//			j--;
//		}
//		else if (arr[i] + arr[j] < key)
//		{
//			i++;
//		}
//		else
//		{
//			*num1 = i;
//			*num2 = j;
//			break;
//		}
//	}
//}
//int main()
//{
//	int arr[] = { 1,3,5,8,9,10,13,17 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	int i = 0;
//	int j = 0;
//	sumk(arr, len, &i, &j, 17);
//	printf("%d,%d\n", i, j);
//	system("pause");
//	return 0;
//}
//����ж�һ����n�Ƿ���2��k�η���ע�⣺������k�Ƕ��٣�ֻ��Ҫ�жϣ����д����ʵ��
int judge_num(int n,int k)
{
	if (n == pow(2 , k))
		return 1;
	return 0;
}
int main()
{
	int n = 0;
	int k = 0;
	int ret = 0;
	scanf("%d %d", &n, &k);
	ret = judge_num(n, k);
	if (ret == 0)
	{
		printf("No\n");
		system("pause");
		return 0;
	}
	printf("Yes\n");
	system("pause");
	return 0;
}