#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//int main()
	/*int i = 10;
	int* p = &i;
	*p = NULL;*/
	/*int n = 10;
	char* pc = (char*)& n;
	int* pi = &n;
	printf("%p\n", &n);
	printf("%p\n", pc);
	printf("%p\n", pc+1);
	printf("%p\n", pi);
	printf("%p\n", pi+1);
	return 0;*/
//#include <stdio.h>
//int main()
//{
//	int n = 0x11223344;
//	char* pc = (char*)& n;
//	char* pi = &n; 
//	*pc = 0x55;//重点在调试的过程中观察内存的变化。
//	*pi = 0; //重点在调试的过程中观察内存的变化。
//	return 0;
//}
//#include <stdio.h>
//int main(int argc, char* argv[])
//{
//	int a[3][2] = { (0,1),(2,3),(4,5) };
//	int* p;
//	p = a[0];
//	printf("%d", p[0]);
//}
//#include<stdio.h>
//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;
//	printf("a_ptr=%#p,p_ptr=%#p\n", &a[4][2], &p[4][2]);
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a[5] = { 1,2,3,4,5 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));
//}
#include<stdio.h>
//int main()
//{
//	char a[5] = { 'A','B','C','D' };
//	char(*p3)[10] = &a;
//	char(*p4)[10] = a;
//	return 0;
//}
int main()
{
	int a[4] = { 1,2,3,4 };
	int* ptr1 = (int*)(&a + 1);
	int* ptr2 = (int*)((int)a + 1);
	printf("%x,%x", ptr1[-1], *ptr2);
	return 0;
}