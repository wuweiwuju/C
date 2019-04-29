#define _CRT_SECURE_NO_WARNINGS 1

//输出一个整数的每一位。

#include<stdio.h>
#include<stdlib.h>
void print(int n)
{
	if (n > 9)
	{
		print(n / 10);
	}
	printf("%d ", n % 10);
}
int main()
{
	int num = 0;
	scanf_s("%d", &num);
	print(num);
	printf("\n");
	system("pause");
	return 0;
}
//int main()
//{
//
//	int i, j, k, num, count;
//	int a[10];
//	printf("几位数\n");
//    scanf_s("%d", &k);
//    for (i = 1; i <= k; i++)
//
//	{
//
//			scanf_s("%d", &a[i]);
//
//	}
//
//
//
//	for (i = 1; i <= k; i++)
//
//	{
//
//		printf("%d ", a[i]);
//
//	}
//	system("pause");
//	return 0;
//
//}

//int main()
//{
//	int input=0;
//	scanf("%d", &input);
//	while(input)
//	{
//		printf("%d ", input % 10);
//			input /= 10;
//	}
//	system("pause");
//	return 0;
//}
