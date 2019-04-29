#define _CRT_SECURE_NO_WARNINGS 1
//编写一个函数 reverse_string(char* string)（递归实现）
//实现：将参数字符串中的字符反向排列。
//要求：不能使用C函数库中的字符串操作函数。
#include<stdio.h>
#include<stdlib.h>
int reverse_string(char* string)
{
	if (*string != '\0')
	{
		string++;
		reverse_string(string);
		printf("%c", *(string-1));
	}
	else
		return 0;
}
int main()
{
	char string[100];
	gets(string);
	reverse_string(string);
	printf("\n");
	system("pause");
	return 0;
}