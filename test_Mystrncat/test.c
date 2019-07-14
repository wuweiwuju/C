#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
char* Mystrncat(char* dest, const char* src, int count)
{
	assert(dest && src);
	char* ret = dest;
	while (*dest)
	{
		dest++;
	}
	while (count--)
	{
		*dest++ = *src++;
	}
	return ret;
}
int main()
{
	char dest[10] = "Hello";
	char* src = "Word";
	int count = 3;
	char* ret = Mystrncat(dest,src,count);
	printf("%s\n", ret);
	system("pause");
	return 0;
}