#define _CRT_SECURE_NO_WARNINGS 1

//��ʹ�ã�a + b�� / 2���ַ�ʽ������������ƽ��ֵ
#include<stdio.h>
#include<stdlib.h>
#include <windows.h>
int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	printf("%d\n", (a & b) + ((a ^ b) >> 1));
	system("pause");
	return 0;
}
