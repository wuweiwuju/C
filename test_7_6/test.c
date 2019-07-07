#define _CRT_SECURE_NO_WARNINGS 1
//大小端的两种方法
#include<stdio.h>
#include<stdlib.h>
//第一种联合体
//union Un
//{
//	int b;
//	char a;
//};
//union Un un = { 1 };
//void print(char* x)
//{
//	if (x == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//}
//int main()
//{
//	print(un.a);
//	system("pause");
//	return 0;
//}
union un
{
	char a;
	int b;
};
int test_little_endian(void)
{
	union un p;
	p.b = 1;
	return p.a;
}
int main()
{
	if (1 == test_little_endian())
	{
		printf("小端\n");
	}
	else
		printf("大端\n");
	system("pause");
	return 0;
}
//第二种字符指针判断
//int main()
//{
//	int a = 1;
//	if (1 == *(char*)& a)
//	{
//		printf("小端\n");
//	}
//	else
//		printf("大端\n");
//	system("pause");
//	return 0;
//}
