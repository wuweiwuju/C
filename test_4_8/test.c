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
	int maxline;
	int i = 0;
	int j = 0;
	int k = 0;
	scanf_s("%d", &maxline);
	for (i = 1; i <= maxline; i++)
	{
		for (j = 1; j <= maxline-i; j++)
		{
			printf(" ");
		}
		for (k = 1; k <= 2 * i - 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}
	for (i = 1; i <= maxline-1; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf(" ");
		}
		for (k = 1; k <= 2*(maxline-1)-(2*i-1); k++)
		{
			printf("*");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}
