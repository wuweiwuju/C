#define _CRT_SECURE_NO_WARNINGS 1
//4.编程实现：
//两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
//输入例子 :
//1999 2299
//输出例子 : 7
//
#include<stdio.h>
#include<stdlib.h>
int compare(int num1,int num2)
{
	int i = 0;
	int count = 0;
	int a[50] = { 0 };
	int b[50] = { 0 };
	for (i = 0; i < 32; i++)
	{
		a[i] = num1 % 2;
		num1 /= 2;
	}
	for (i = 0; i < 32; i++)
	{
		b[i] = num2 % 2;
		num2 /= 2;
	}
	for (i = 0; i < 32; i++)
	{
		if (a[i] != b[i])
		{
			count++;
		}
	}
	printf("%d\n", count);

}
int main()
{
	int num1 = 0;
	int num2 = 0;
	printf("输入两个整数\n");
	scanf_s("%d %d", &num1, &num2);
	compare(num1, num2);
	system("pause");
	return 0;
}
//#include<stdio.h>
//#include<stdlib.h>
//#include<math.h>
//int compare(int a, int b)
//{
//	int i = 0; 
//	int count = 0; 
//	for (i = 0; i < 32; i++) 
//	{ 
//		if (((a & 1) ^ (b & 1)) == 1) 
//		{ 
//			count++; 
//		}
//		a >>= 1; 
//		b >>= 1; 
//	}
//	printf("count=%d\n", count); 
//	return 1;
//}
//int main()
//{
//	int m = 0; 
//	int n = 0; 
//	scanf("%d%d", &m, &n); 
//	compare(m, n); 
//	system("pause"); 
//	return 0;
//}
