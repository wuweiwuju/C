#define _CRT_SECURE_NO_WARNINGS 1
//写一个函数返回参数二进制中 1 的个数
//比如： 15 0000 1111 4 个 1
//程序原型：
#include<stdio.h>
#include<stdlib.h>

int count_one_bits(unsigned int value)
{
	// 返回 1的位数 
	int num = 0;
	while (value)
	{
		if (value % 2)
			num++;
		value /= 2;
	}
	return num;
}
int main()
{
	int i = 0;
	int num = 0;
	scanf_s("%d", &i);
	num=count_one_bits(i);
	printf("%d\n",num);
	system("pause");
	return 0;
}
//#include<stdio.h>
//#include<stdlib.h>
//int count_one_bits(unsigned int value)
//{
//	int num = 0;
//	while (value)//value为0时跳出循环
//	{
//		if (value % 2)//如果余数为1，则num自加1
//			num++;
//		value = value / 2;//将得到的商再付给value
//	}
//	return num;
//}
//int main()
//{
//	int i = 0;
//	int num = 0;
//	printf("请输入一个正数：");
//	scanf("%d", &i);
//	num = count_one_bits(i);//num为记录1 的个数
//	printf("num=%d\n", num);
//	system("pause");
//	return 0;
//}
