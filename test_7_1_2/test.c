#define _CRT_SECURE_NO_WARNINGS 1
//∑«µ›πÈÀ„∑®
#include<stdio.h>
#include<stdlib.h>
//µ›πÈÀ„∑®
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