#define _CRT_SECURE_NO_WARNINGS 1
//��дһ������ reverse_string(char* string)���ݹ�ʵ�֣�
//ʵ�֣��������ַ����е��ַ��������С�
//Ҫ�󣺲���ʹ��C�������е��ַ�������������
#include<stdio.h>
#include<stdlib.h>
int reverse_string(char* string)
{
	if (*string != '\0')
	{
		string++;
		reverse_string(string);
		printf("%c", *(string-1));
	}
	else
		return 0;
}
int main()
{
	char string[100];
	gets(string);
	reverse_string(string);
	printf("\n");
	system("pause");
	return 0;
}