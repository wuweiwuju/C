#define _CRT_SECURE_NO_WARNINGS 1
//
//编写函数：
//unsigned int reverse_bit(unsigned int value);
//这个函数的返回值value的二进制位模式从左到右翻转后的值。
//
//如：
//在32位机器上25这个值包含下列各位：
//00000000000000000000000000011001
//翻转后：（2550136832）
//10011000000000000000000000000000
//程序结果返回：
//2550136832

#include<stdio.h>
#include<stdlib.h>
unsigned int reverse_bit(unsigned int value)
{    
	unsigned int sum = 0;
	int i = 0;
	for (i = 0; i < 32; i++)
	{        
		sum += ((value >> i) & 1) << (31 - i);//取出最低位，左移到相应位置
	}
	return sum;
}
int main()
{    
	unsigned int num = 25;
	printf("反转后：%u\n", reverse_bit(num));
	system("pause");
	return 0;
}

