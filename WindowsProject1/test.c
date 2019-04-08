#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int mian()
{
	printf("作为一个程序员");
	int line = 0;
	while (line <= 20000)
	{
		line++;
		printf("我要继续努力敲代码\n");
	}
	if (line > 20000)
		printf("赢取白富美\n");
	
	return 0;
	system("pause");
}