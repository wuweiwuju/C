#define _CRT_SECURE_NO_WARNINGS 1
//在屏幕上打印杨辉三角。
//   1
//  1 1
// 1 2 1
//1 3 3 1

#include<stdlib.h>
#include<stdio.h>
void printYangHui()//按行数打印杨辉三角
{
	int rows, coef = 1, space, i, j;
	printf("行数: ");
	scanf_s("%d", &rows);
	//控制行数
	for (i = 0; i < rows; i++)
	{
		//打印空格
		for (space = 1; space <= rows - i; space++)
			printf("  ");
		//
		for (j = 0; j <= i; j++)//第n行的数字有n项，所以j<=i
		{
			//第一行为1，第一列为1
			if (j == 0 || i == 0)
				coef = 1;
			else
				coef = coef * (i - j + 1) / j;//最后一个每一行i=j,倒数第二行（coef=j）等于列数，
			printf("%4d", coef);
		}
		printf("\n");
	}
}
int main()
{
	printYangHui();
	system("pause");
	return 0;//
}


