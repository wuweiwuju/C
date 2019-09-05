#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//int main()
//{
//	int a[10];
//	int* pa;
//	pa = a;
//	return 0;
//}
int Change(int** px)
{
	int y = 8;
	y = y - **px;
	*px = &y;
	return 0;
}
int main()
{
	int xx = 3;
	int* pY = &xx;
	Change(&pY);
	printf("%d\n", *pY);
	return 0;
}
//int main()
//{
//	char arr[2][4];
//	strcpy((char*)arr, "you");
//	strcpy(arr[1], "me");
//	arr[0][3] = '&';
//	printf("%s\n", arr);
//	return 0;
//}
int main()
{
	int a = 4, b = 3, *p, *q, * w;
	p = &a;
	q = &b;
	w = q;
	q = NULL;
	//*q = 0;
	//w = p;
	//*p = a;
	*p = *w;
	return 0;
}
int fun(int x)
{
	int count = 0;
	while (x)
	{
		count++;
		x = x & (x - 1);
	}
	return count;
}
int main()
{
	printf("fun(2017)=%d\n", fun(2019));
}
#define CIR(r) r*r
void main()
{
	int a = 1;
	int b = 2;
	int t;
	t = CIR(a + b);
	printf("%d\n", t);
	return;
}
unsigned long g_ulGobal = 0;
void GlobalInit(unsigned long ulArg)
{
	ulArg = 0x01;
	return;
}
void Test()
{
	GlobalInit(g_ulGobal);
	printf("%lu", g_ulGobal);
	return;
}