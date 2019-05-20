#define _CRT_SECURE_NO_WARNINGS 1
//判断编辑器大小端
#include<stdio.h>
#include<stdlib.h>
int check_sys()
{
	union Un
	{
		int i;
		char c;
	}u;
	u.i=1;
	return u.c;
}
//int check_sys()
//{
//	int a = 1;
//	//返回1是小端
//	//返回0是大端
//	return *(char*)& a;
//}
int main()
{
	if (1 == check_sys())
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
	/*int a = 1;
	if (1 == *(char*)& a)
	{
		printf("小端\n");
	}
	else
	{
		printf("大端\n");
	}
*/
}