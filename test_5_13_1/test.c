#define _CRT_SECURE_NO_WARNINGS 1
//strcpyÄ£ÄâÊµÏÖ
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
char* my_strcpy(char* pdest, const char* psrc)
{
	char* start = pdest;
	assert(pdest != NULL);
	assert(psrc != NULL);
	while (*pdest = *psrc)
	{
		pdest++;
		psrc++;
	}
	return start;
}
int main()
{
	char arr1[20] = { 0 };
	char arr2[] = { "hello" };
	printf("%s\n", my_strcpy(arr1, arr2));
	system("pause");
	return 0;
}