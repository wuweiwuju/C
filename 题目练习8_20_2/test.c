#define _CRT_SECURE_NO_WARNINGS 1
//编写一个函数，将字符串中的空格替换为%20，
//样例："abc defgx yz" 转换 "abc%20defgx%20yz"
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//void swap_str(char* str,int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		if (str[i] == ' ')
//		{
//			str[i] = '%';
//			str[i + 1] = '2';
//			str[i + 2] = '0';
//		}
//	}
//}
//int main()
//{
//	char str[] = { 0 };
//	scanf("%s", str);
//	swap_str(str,strlen(str));
//	printf("%s\n", str);
//	system("pause");
//	return 0;
//}
#include <stdio.h>
#include <assert.h>
void replace(char* src)
{
	assert(src);
	int OldLen = 0;                  //原字符串长度
	int NewLen = 0;                  //新字符串长度
	int BlackNum = 0;                //空格数量
	int NewBack = 0;                 //新字符串尾部
	int OldBack = 0;                 //原字符串尾部
	while (src[OldLen] != '\0')
	{
		if (src[OldLen] == ' ')
		{
			BlackNum++;
		}
		OldLen++;
	}
	NewLen = OldLen + BlackNum * 2;
	OldBack = OldLen - 1;
	NewBack = NewLen - 1;
	while (OldBack != 0)
	{
		if (src[OldBack] == ' ')
		{
			src[NewBack--] = '0';
			src[NewBack--] = '2';
			src[NewBack] = '%';
		}
		else
		{
			src[NewBack] = src[OldBack];
		}
		OldBack--;
		NewBack--;
	}
}
int main()
{
	char p[20] = "abc defgx yz";
	replace(p);
	printf("%s\n", p);
	return 0;
	return 0;
}