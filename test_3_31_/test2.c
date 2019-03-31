#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a, b;
	for (a = 1; a <= 9; a++)
	{
		for (b = 1; b <= a; b++)
		{
			printf("%d*%d=%d ", a, b, a*b);
		}
		printf("\n");
	}
	system("pause");
	return 0;

}