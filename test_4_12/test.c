#define _CRT_SECURE_NO_WARNINGS 1
//ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ����
//����9�����9 * 9�ھ�������12�����12 * 12�ĳ˷��ھ���
#include<stdio.h>
#include<stdlib.h>
int mul_(int n)
{
	int i = 0;
	int j = 0;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%-2d ", j, i, i * j);
		}
		printf("\n");
	}
}
int main()
{
	int n = 0;
	int ret = 0;
	printf("������һ����:> ");
	scanf_s("%d", &n);
	ret = mul_(n);
	system("pause");
	return 0;
}