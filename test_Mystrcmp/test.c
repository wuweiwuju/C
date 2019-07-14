#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
int Mystrcmp(const char* str1, const char* str2)
{
	assert(str1);
	assert(str2);
	while (*str1 == *str2)
	{
		if (*str1 == NULL)
			return 0;
		str1++;
		str2++;
	}
	return *str1 - *str2;
}
int main()
{
	char str1[] = "abc";
	char str2[] = "abc";
	int ret = Mystrcmp(str1,str2);
	printf("%d\n", ret);
	system("pause");
	return 0;
}