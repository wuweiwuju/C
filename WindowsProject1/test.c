#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int mian()
{
	printf("��Ϊһ������Ա");
	int line = 0;
	while (line <= 20000)
	{
		line++;
		printf("��Ҫ����Ŭ���ô���\n");
	}
	if (line > 20000)
		printf("Ӯȡ�׸���\n");
	
	return 0;
	system("pause");
}