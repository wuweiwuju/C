#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int func()
{
	int i, j, k = 0;
	for (i = 0, j = -1; j = 0; i++, j++)
	{
		k++;
	}
	return k;
}
int main()
{
	printf("%d\n", func());
}
//int main()
//{
//	int arr[] = { 6, 7, 8, 9, 10 };
//	int* ptr = arr;
//	*(ptr++) += 123;
//	printf("%d,%d\n", *ptr, *(++ptr));//8,8
//	system("pause");
//	return 0;
//}
int main()
{
	int k, j, s;
	for (k = 0; k < 6; k++, k++)
	{
		s = 1;
		for (j = k; j < 6; j++)
		{
			s += j;
		}
	}
	printf("%d\n", s);
	return 0;
}
//int main()
//{
//	int i = 0;
//	int a = 1;
//	//int b = (a++, a++);
//	//printf("%d %d\n", a, b);//3 2
//	return 0;
//}
struct student
{
	int num;
	char name[32];
	float score;
}stu;
//int main()
//{
//	int j = 4;
//	int i = j;
//	for (; i <= 2 * j; i++)
//	{
//		switch (i / j)
//		{
//		case 0:
//		case 1:
//			printf("*");
//			break;
//		case 2:
//			printf("#");
//		}
//	}
//	return 0;
//}
int main()
{
	unsigned int a = 0xfffffff7;
	unsigned char i = (unsigned char)a;
	char* b = (char*)& a;
	printf("%08x,%08x", i, *b);//000000f7,fffffff7
	//%08x 8位对齐的16进制格式
	system("pause");
	return 0;
}