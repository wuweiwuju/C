#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a = 1;
	int b = 1;
	int c = 1;
	int i = 0;
	int n = 0;
	scanf("%d", &n);
	if (n == 1 || n == 2)
	{
		printf("%d\n", c);
		system("pause");
		return 0;
	}
	else
		for (i=2;i<n;i++)
		{
			c = a + b;
			a = b;
			b = c;
		}
	printf("%d\n", c);
	system("pause");
	return 0;
}