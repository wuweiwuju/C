#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int Sn = 0;
	int a = 0;
	int i = 0;
	int b = 0;
	scanf("%d", &a);
	for (i = 0; i < 5; i++)
	{
		b = a + b * 10;
		Sn = Sn + b;
	}
	printf("%d\n", Sn);
	system("pause");
	return 0;
}