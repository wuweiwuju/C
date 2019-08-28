#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//void Func(char str_arg[2])
//{
//	int m = sizeof(str_arg);
//	int n = strlen(str_arg);
//	printf("%d %d\n", m, n);
//}
//int main()
//{
//	char str[] = "Hello";
//	Func(str);
//	return 0;
//}
//int main()
//{
//	int a, x;
//	for (a = 0, x = 0; a <= 1 && !x++; a++)
//	{
//		a++;
//	}
//	printf("%d %d", a, x);
//	return 0;
//}
int main() {
	int a[5] = { 1,2,3,4,5 };
	//int* p1 = (int*)(&a + 1);
	int* p2 = (int*)((int)a + 1);
	//int* p3 = (int*)(a + 1);
	//printf("%d,%x,%d\n", p1[-1], p2[0], p3[1]);
	printf("%x\n", p2[0]);
	return 0;
}