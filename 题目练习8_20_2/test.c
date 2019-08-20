#define _CRT_SECURE_NO_WARNINGS 1
//编写一个函数，将字符串中的空格替换为%20，
//样例："abc defgx yz" 转换 "abc%20defgx%20yz"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void swap_str(char* str,int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		if (str[i] == ' ')
		{
			str[i] = '%';
			str[i + 1] = '2';
			str[i + 2] = '0';
		}
	}
}
int main()
{
	char str[] = { 0 };
	scanf("%s", str);
	swap_str(str,strlen(str));
	printf("%s\n", str);
	system("pause");
	return 0;
}