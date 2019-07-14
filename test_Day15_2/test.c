#define _CRT_SECURE_NO_WARNINGS 1
////模拟实现strcpy
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//char* My_strcpy(char* dest, const char* src)
//{
//	assert(dest);
//	assert(src);
//	char* ret = dest;
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return ret;
//}
//int main()
//{
//	char* src = "abcd";
//	char dest[20];
//	printf("%s\n", My_strcpy(dest, src));
//	system("pause");
//	return 0;
//}
//模拟实现strcat
char* My_strcat(char* dest, const char* src)
{
	assert(dest);
	assert(src);
	char* ret = dest;
	while (*dest)
	{
		dest++;
	}
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	char* src = "abcd";
	char dest[15] = "fgc";
	printf("%s\n", My_strcat(dest, src));
	system("pause");
	return 0;
}


