#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
char* Mystrncpy(char* dest, const char* src, int count)
{
	assert(dest);
	assert(src);
	char* ret = dest;
	while (count && (*dest = *src))
	{
		dest++;
		src++;
		count--;
	}
	if (count > 0)
	{
		while (count--)
		{
			*dest = 0;
		}
	}
	return ret;
}
int main()
{
	char dest[10]= "0";
	int count = 6;
	char* src = "Hello";
	char* ret = Mystrncpy(dest,src,count);
	printf("%s\n", ret);
	system("pause");
	return 0;
}