#define _CRT_SECURE_NO_WARNINGS 1
//strlenÄ£ÄâÊµÏÖ
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
int my_strlen(const char* str)
{
	int num = 0;
	assert(str != NULL);
	while(*str != '\0')
	{
		*str++;
		num++;
	}
	return num;
}
int main()
{
	int len = my_strlen("abc");
	printf("%d\n", len);
	system("pause");
	return 0;
}