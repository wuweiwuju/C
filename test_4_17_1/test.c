#define _CRT_SECURE_NO_WARNINGS 1
//�ݹ�ͷǵݹ�ֱ�ʵ����n�Ľ׳�
//�ǵݹ�
//#include<stdio.h>
//#include<stdlib.h>
//int fac(int n)
//{
//	int sum = 1;
//	int i = 1;
//	for (i = 1; i <= n; i++)
//	{
//		sum *= i;
//	}
//	return sum;
//
//}
//int main()
//{
//	int n = 0;
//	scanf_s("%d", &n);
//	fac(n);
//	printf("%d\n", fac(n));
//	system("pause");
//	return 0;
//}
//�ݹ�
#include<stdio.h>
#include<stdlib.h>
int fac(int n)
{
	if (n == 1 || n == 0)
	{
		return 1;
	}
	else
	{
		return fac(n-1)*n;
	}
}
int main()
{
	int n = 0;
	scanf_s("%d", &n);
	fac(n);
	printf("%d\n", fac(n));
	system("pause");
	return 0;
}