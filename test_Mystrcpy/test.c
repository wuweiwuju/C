#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
char* Mystrcpy(char* dest,const char* src)
{
	char* ret = dest;
	assert(dest);
	assert(src);
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	char dest[20] = { 0 };
	char* src = "Hello";
	char* ret = Mystrcpy(dest,src);
	printf("%s\n", ret);
	system("pause");
	return 0;
}