#define _CRT_SECURE_NO_WARNINGS 1
//�жϱ༭����С��
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
//	//����1��С��
//	//����0�Ǵ��
//	return *(char*)& a;
//}
int main()
{
	if (1 == check_sys())
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}
	/*int a = 1;
	if (1 == *(char*)& a)
	{
		printf("С��\n");
	}
	else
	{
		printf("���\n");
	}
*/
}