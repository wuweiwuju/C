#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	char ch = 'w';
	char* pc = &ch;
	*pc = 'q';
	printf("%c\n", ch);
	return 0;
}
