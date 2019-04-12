#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int is_prime(int n)
{
	int i;
	for (i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
		else
		{
			break;
		}
	}
	return 1;
}
int main()
{
	int n = 0;
	int ret = 0;
	scanf_s("%d", &n);
	ret = is_prime(n);
	if (is_prime(n))
	{
		printf("是素数\n");
	}
	else
	{
		printf("不是素数\n");
	}
	
	system("pause");
	return 0;
}