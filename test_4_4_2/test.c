#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 1,i;
	float c = 0.0;
	for (i = 1; i <= 100; i++)
	{
		c = c + a*(1.0/i);
		a = -a;
	}
	printf("%f\n", c);
	system("pause");
	return 0;
}