#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}
//
////将unsigned int 重命名为uint_32, 所以uint_32也是一个类型名
//typedef unsigned int uint_32;
//int main()
//{
//	//观察num1和num2,这两个变量的类型是一样的
//	unsigned int num1 = 0;
//	uint_32 num2 = 0;
//	return 0;
//}
//代码1
#include <stdio.h>
void test()
{
	int i = 0;
	i++;
	printf("%d ", i);
}
int main()
{
	int i;
	for (i = 0; i < 10; i++)
	{
		test();
	}
	return 0;
}
////代码2
//#include <stdio.h>
//void test()
//{
//	static int i = 0;
//	i++;
//	printf("%d ", i);
//}
//int main()
//{
//	for (i = 0; i < 10; i++)
//	{
//		test();
//	}
//	return 0;