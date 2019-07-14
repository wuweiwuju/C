#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
int Mystrncmp(const char* str1, const char* str2, size_t num)
{
	assert(str1 && str2);
	while (num--)
	{
		if (*str1 == *str2)
		{
			str1++;
			str2++;
		}
		else
		{
			return *str1 - *str2;
		}
	}
	return 0;
}
int main()
{
	char* str1 = "abq";
	char* str2 = "abcde";
	int num = 3;
	int ret = Mystrncmp(str1,str2,num);
	printf("%d\n", ret);
	system("pause");
	return 0;
}