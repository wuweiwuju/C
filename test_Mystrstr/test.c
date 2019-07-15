#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
char* Mystrstr(const char* str1, const char* str2)
{
	assert(str1 && str2);
	const char* s1 = str1;
	const char* s2 = str2;
	const char* cur = str1;

	if (str2 == '\0')
		return (char*)str1;
	while (*cur)
	{
		s1 = cur;
		s2 = str2;
		//chazhao
		while (*s1 == *s2 && *s1 && *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0')
		{
			return (char*)cur;
		}
		cur++;
	}
	return NULL;
}
int main()
{
	char str1[] = "abbbcgygy";
	char* str2 = "bbc";
	char* ret = Mystrstr(str1, str2);
	printf("%s\n", ret);
	system("pause");
	return 0;
}