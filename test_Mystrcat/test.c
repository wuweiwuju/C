#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
char* Mystrcat(char* dest, const char* src)
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
	char* src = "Word";
	char dest[15] = "Hello";
	char* ret = Mystrcat(dest, src);
	printf("%s\n", ret);
	system("pause");
	return 0;
}