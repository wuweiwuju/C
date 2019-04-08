#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i=0;
	int a = 0, b = 0, c = 0;
	for (i = 0; i < 1000; i++)
	{
		a = i % 10;
		b = i % 100 / 10;
		c = i / 100;
		if (i == a * a * a + b * b * b + c * c * c && i>=100)
		{
			printf("%d   \n", i);
		}		
	}
	system("pause");
	return 0;
}