#define _CRT_SECURE_NO_WARNINGS 1
//1.编写函数：
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
//未优化
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//#include<math.h>
//unsigned int reverse_bit(unsigned int value)
//{
//	int i = 0;
//	int sum = 0;
//	for (i = 0; i < 32; i++)
//	{
//		sum+=((value >> i) & 1) * pow(2, 31 - i);
//	}
//	return sum;
//}
//int main()
//{
//	unsigned int a = 25;
//	unsigned int ret = reverse_bit(a);
//	printf("%u\n", ret);
//	system("pause");
//	return 0;
//}
//优化后
//unsigned int reverse_bit(unsigned int value)
//{
//	int i = 0;
//	unsigned int sum = 0;
//	for (i = 0; i < 32; i++)
//	{
//		sum <<= 1;
//		sum |= ((value >> i) & 1);
//	}
//	return sum;
//}
//int main()
//{
//	unsigned int a = 25;
//	unsigned int ret = reverse_bit(a);
//	printf("%u\n", ret);
//	system("pause");
//	return 0;
//}
//2.不使用（a + b） / 2这种方式，求两个数的平均值。
//int average_value(int a, int b)
//{
//	/*return (a + b) >>1;*/
//	return (a & b) + ((a ^ b) >> 1);
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int ret = 0;
//	scanf_s("%d %d", &a, &b);
//	ret = average_value(a, b);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}
//3.编程实现：
//一组数据中只有一个数字出现了一次。其他所有数字都是成对出现的。
//请找出这个数字。（使用位运算）
//未扩展
//int find(int* arr, int sz)
//{
//	assert(arr != NULL);
//	int i = 0;
//	int num = 0;
//	for (i = 0; i < sz; i++)
//	{
//		num ^= arr[i];
//	}
//	return num;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,5,4,2,3,1 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	printf("%d\n", find(arr, n));
//	system("pause");
//	return 0;
//}
//4.
//有一个字符数组的内容为:"student a am i",
//	请你将数组的内容改为"i am a student".
//	要求：
//	不能使用库函数。
//	只能开辟有限个空间（空间个数和字符串的长度无关）。
void reverse_str(char* left, char* right)
{
	assert(left != NULL);
	assert(right != NULL);
	while (left < right)
	{
		int temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}
void reverse(char* str,int sz)
{
	assert(str != NULL);
	//逆序整个字符串
	reverse_str(str, str + sz - 1);
	//逆序单个单词
	while (*str)
	{
		char* start = str;
		while ((*str != ' ')&&(*str!='\0'))
		{
			str++;
		}
		reverse_str(start, str - 1);
		if (*str != '\0')
		{
			str++;
		}
	}
}
int Strlen(char* str)
{
	int len = 0;
	assert(str != NULL);
	while (*str)
	{
		len++;
		str++;
	}
	return len;
}
int main()
{
	char arr[] = "student a am i";
	int n = Strlen(arr);
	printf("原数组内容为:>%s\n", arr);
	reverse(arr, n);
	printf("现数组内容为:>%s\n", arr);
	system("pause");
	return 0;
}