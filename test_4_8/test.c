#define _CRT_SECURE_NO_WARNINGS 1
//1.在屏幕上输出以下图案：
//        *
//       ***
//      *****
//     *******
//    *********
//   ***********
//  *************
//   ***********
//    *********
//     *******
//      *****
//       ***
//        *
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 1; i <= 6; i++)
	{
		for (j = 1; j <= 6-i; j++)
		{
			printf(" ");
		}
		for (k = 1; k <= 2 * i - 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = 1; i <= 5; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf(" ");
		}
		for (k = 1; k <= 11-2*i; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
