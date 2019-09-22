#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int judge_Fib(int n)
{
	int x = 0;
	int y = 1;
	int z = 0;
	while (1)
	{
		if (n == z)
			return 0;
		if (n > x && n < y)
		{
			if ((n - x) > (y - n))
			{
				return (y - n);
			}
			return (n - x);
		}
		z = x + y;
		x = y;
		y = z;
	}
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = judge_Fib(n);
	printf("%d\n", ret);
	return 0;
}