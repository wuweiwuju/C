#define _CRT_SECURE_NO_WARNINGS 1
//��С�˵����ַ���
#include<stdio.h>
#include<stdlib.h>
//��һ��������
//union Un
//{
//	int b;
//	char a;
//};
//union Un un = { 1 };
//void print(char* x)
//{
//	if (x == 1)
//	{
//		printf("С��\n");
//	}
//	else
//	{
//		printf("���\n");
//	}
//}
//int main()
//{
//	print(un.a);
//	system("pause");
//	return 0;
//}
union un
{
	char a;
	int b;
};
int test_little_endian(void)
{
	union un p;
	p.b = 1;
	return p.a;
}
int main()
{
	if (1 == test_little_endian())
	{
		printf("С��\n");
	}
	else
		printf("���\n");
	system("pause");
	return 0;
}
//�ڶ����ַ�ָ���ж�
//int main()
//{
//	int a = 1;
//	if (1 == *(char*)& a)
//	{
//		printf("С��\n");
//	}
//	else
//		printf("���\n");
//	system("pause");
//	return 0;
//}
