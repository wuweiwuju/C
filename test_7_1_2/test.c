#define _CRT_SECURE_NO_WARNINGS 1
//�ǵݹ��㷨
#include<stdio.h>
#include<stdlib.h>
//�ݹ��㷨
long long fib1(size_t N) 
{
	if (N < 2)
		return N;
	return fib1(N - 1) + fib1(N - 2);
}
int main()
{
	printf("%lld\n", fib1(6));
	system("pause");
	return 0;
}  