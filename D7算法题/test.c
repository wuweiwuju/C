#define _CRT_SECURE_NO_WARNINGS 1
//有一个数组a 编写函数，求数组中前k个最小的数字
#include<stdio.h>
#include<stdlib.h>
int min_count(int a[],int k)
{
	int i = 0;
	int min = 0;
	for (i = 0; i < k-1; i++)
	{
		if (a[i] < a[i + 1])
		{
			a[i + 1] = a[i];
			min = a[i + 1];
		}
		else
		{
			min = a[i + 1];
		}
	}
	return min;
}
int main()
{
	int a[] = { 6,2,3,5,1,96,6,2,5,8,7 };
	int ret = 0;
	int k = 0;
	scanf("%d", &k);
	ret = min_count(a,k);
	printf("%d\n", ret);
	system("pause");
	return 0;
}