#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//一个数的二进制有多少个一
//int count_one_bit(/*unsigned */int n)
//{
//	/*int count = 0;
//	while (n)
//	{
//		if (n % 2 == 1)
//			count++;
//		n = n / 2;
//	}
//	return count;*/
//	/*int count = 0;
//	int i = 0;
//	for (i = 0; i < 32; i++)
//	{
//		if (((n >> i) & 1) == 1)
//			count++;
//	}
//	return count;*/
//}
//int count_one_bit(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		n = n & (n - 1);
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	int n=0;
//	int ret = 0;
//	scanf_s("%d", &n);
//	ret=count_one_bit(n);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}
//  两个数的二进制有多少位不同
//int count_one_bit(int n)
//{
//	int count = 0;
//	while (n)
//	{
//		n = n & (n - 1);
//		count++;
//	}
//	return count;
//}
//int diff_bit(int x, int y)
//{
//	return count_one_bit(x ^ y);
//}
//int main()
//{
//	int n = 0;
//	int m = 0;
//	int ret = 0;
//	scanf_s("%d%d", &m, &n);
//	ret = diff_bit(m, n);
//	printf("%d\n", ret);
//}
//杨辉三角
int main()
{
	int arr[50][50] = {0};
	int i = 0;
	int j = 0;
	int n = 0;
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (j == 0)
			{
				arr[i][j] = 1;
			}
			if (i == j)
			{
				arr[i][j] = 1;
			}
			if (i > 1 && j > 0)
			{
				arr[i][j] = arr[i-1][j] + arr[i-1][j-1];
			}
		}
	}
	for (i = 0; i < n; i++)
	{ 
		for (j = 1; j < n - i; j++)
			printf("  ");
		for (j = 0; j <= i; j++)
			printf("%4d", arr[i][j]);
		printf("\n");
	}

	system("pause");
	return 0;
}