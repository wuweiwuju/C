#define _CRT_SECURE_NO_WARNINGS 1
//����Ļ�ϴ�ӡ������ǡ�
//   1
//  1 1
// 1 2 1
//1 3 3 1

#include<stdlib.h>
#include<stdio.h>
void printYangHui()//��������ӡ�������
{
	int rows, coef = 1, space, i, j;
	printf("����: ");
	scanf_s("%d", &rows);
	//��������
	for (i = 0; i < rows; i++)
	{
		//��ӡ�ո�
		for (space = 1; space <= rows - i; space++)
			printf("  ");
		//
		for (j = 0; j <= i; j++)//��n�е�������n�����j<=i
		{
			//��һ��Ϊ1����һ��Ϊ1
			if (j == 0 || i == 0)
				coef = 1;
			else
				coef = coef * (i - j + 1) / j;//���һ��ÿһ��i=j,�����ڶ��У�coef=j������������
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


