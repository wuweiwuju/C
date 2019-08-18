#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//青蛙跳台阶 一次可以跳一级 ， 还可以跳两级，
//问跳n阶的台阶有几种跳法
//n = 1 时  1种
//n = 2 时  2种
//n = 3 时  3种
//n = 4 时  5种
//n = 5 时  8种
//很容易看出来满足斐波那契数列 
//f(n) = f(n-1) + f(n-2) n>=2
//也可以这么理解
//第一次跳一阶 还剩 n - 1 阶 则有f(n-1)种跳法
//第一次跳两阶 还剩 n - 2 阶 则有f(n-2)种跳法
//所以总的跳法f(n) = f(n-1) + f(n-2)
//int fib(int n)
//{
//	if (n == 1 || n == 2)
//		return n;
//	return fib(n - 1) + fib(n - 2);
//}
//int main()
//{
//	int n = 0;
//	int ret = 0;
//	scanf("%d", &n);
//	ret = fib(n);
//	printf("%d \n", ret);
//	system("pause");
//	return 0;
//}
//变态跳台阶问题
//青蛙跳台阶 一次可以跳一级 , 二级,........ 还可以跳n级,问跳n阶的台阶有几种跳法
//第一次跳一阶 还剩 n - 1 阶 则有f(n-1)种跳法
//第一次跳两阶 还剩 n - 2 阶 则有f(n-2)种跳法
//第一次跳三阶 还剩 n - 3 阶 则有f(n-3)种跳法
//...........................................
//第一次跳n阶 还剩 n-n 阶 则有f(n-n)种跳法
//所以总的跳法f(n) = f(n-1) + f(n-2) + f(n-3)......+f(n-n)
//f(n-1) = f(n-2) + f(n-3)......+f(n-n)
//所以f(n) = f(n-1)*2  n>=2
//当只有一阶的话 就是只有一种跳法 
int jumpFloor(int n)
{
	if (n == 1)
		return n;
	return 2*jumpFloor(n - 1);
}
int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = jumpFloor(n);
	printf("%d \n", ret);
	system("pause");
	return 0;
}