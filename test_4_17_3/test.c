#define _CRT_SECURE_NO_WARNINGS 1
//�ݹ�ͷǵݹ�ֱ�ʵ��strlen
//�ǵݹ�
#include<stdio.h>
#include<stdlib.h>
int my_strlen(char* str)
{
	int count = 0;
	while(*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}
int main()
{
	char a[100];
	gets(a);
	my_strlen(a);
	printf("%d\n", my_strlen(a));
	system("pause");
	return 0;
}
//�ݹ�
#include<stdio.h>
#include<stdlib.h>
int my_strlen(char* str)
{
	if (*str != '\0')
	{
		return 1+my_strlen(str + 1);
	}
	else
	{
		return 0;
	}
}
int main()
{
	char a[100];
	gets(a);
	my_strlen(a);
	printf("%d\n", my_strlen(a));
	system("pause");
	return 0;
}