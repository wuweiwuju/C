#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int i, a = 1;
	float c = 0.0;
	for (i = 1; i <= 100; i++)
	{
		c += a * (1.0 / i);
		a = -a;
	}
	printf("sum is %f\n", c);
	system("pause");
	return 0;
}