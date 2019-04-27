#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//int main()
//{
//	int num1 = 1;
//	int num2 = 2;
//	int a, b, c;
//	a=num1& num2;
//	printf("%d\n",a);
//	c=num1 | num2;
//	printf("%d\n", c);
//	b=num1^ num2;
//	printf("%d\n", b);
//	return 0;
//}

//不能创建临时变量（第三个变量），实现两个数的交换。
//#include <stdio.h>
//int main()
//{
//	int a = 10;
//	int b = 20;
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("a = %d b = %d\n", a, b);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int num = 10;
//	int count = 0;//计数
//	while (num)
//	{
//		if (num % 2 == 1)
//			count++;
//		num = num / 2;
//	}
//	printf("二进制中1的个数 = %d\n", count);
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int num = 10;
//	int i = 0;
//	int count = 0;//计数
//	for (i = 0; i < 32; i++)
//	{
//		if (((num >> i) & 1) == 1)
//			count++;
//	}
//	printf("二进制中1的个数 = %d\n", count);
//	return 0;
//}
//思考还能不能更加优化，这里必须循环32次的。
//方法3：
#include <stdio.h>
int main()
{
	int num = -1;
	int i = 0;
	int count = 0;//计数
	while (num)
	{
		count++;
		num = num & (num - 1);
	}
	printf("二进制中1的个数 = %d\n", count);
	return 0;
}