#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
char* Mystrchr(const char* str1, char str2)
{
	assert(str1);
	while (*str1)
	{
		if( *str1 == str2)
		{
			return (char*)str1;
		}
		str1++;
	}
	return NULL;
}
int main()
{
	char* str1 = "abcder";
	char str2 = 'b';
	char* ret = Mystrchr(str1, str2);
	printf("%s\n", ret);
	system("pause");
	return 0;
}

