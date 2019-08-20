#define _CRT_SECURE_NO_WARNINGS 1
//写一个函数，求unsigned int型变量x在内存中二进制一的个数
#include<stdio.h>
#include<stdlib.h>
int num()
{
	int i = 0;
	int count = 0;
	unsigned int x = 0;
	printf("请输入一个无符号整型:>");
	scanf("%u", &x);
	for (i = 0; i < 32; i ++)
	{
		//判断每一位的值是否为1
		if ((x & 1) == 1)
		{
			count++;
		}
		//右移准备判断下一位的值
		x >>= 1;
	}
	return count;
}
int main()
{

	int ret = num();
	printf("%d\n", ret);
	system("pause");
	return 0;
}