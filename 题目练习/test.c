#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//int main()
//{
//	int a[] = { 2,4,6,8,10,12,14,16,18,20,22,24 }, * q[4], k;
//	for (k = 0; k < 4; k++)
//	{
//		q[k] = &a[k * 3];
//	}
//	printf("%d\n", q[3][1]);
//}
//int main()
//{
//	int i, j, a = 0;
//	for (i = 0; i < 2; i++)
//	{
//		for (j = 0; j < 4; j++)
//		{
//			if (j % 2)
//				break;//直接就跳出这个for循环了
//			a++;
//		}
//		a++;
//	}
//	printf("%d\n", a);
//}
//
//int main()
//{
//	char a ;
//	int b;
//	float c;
//	double d;
//
//}
//int main()
//{
//	const char* p = "Hello!";
//	printf("%c\n", *p);
//}
//int main()
//{
//	int a = 10;
//	a += a *= a -= a / 3;
//
//}
//int main()
//{
//	int i = 0;
//	while (i < 10)
//	{
//		if (i < 1) continue;
//		if (i == 5) break;
//		i++;
//	}
//
//}
//int main()
//{
//	int a = 5;
//	if (a = 0)
//	{
//		printf("%d", a - 10);
//	}
//	else
//	{
//		printf("%d", a++);
//	}
//	return 0;
//}
//int main()
//{
//	int x, y, z;
//		x = z = 2, y = 3;
//	if (x > y)
//		z = 1;
//	else if (x == y)
//		z = 0;
//	else
//		z = -1;
//}
//int main()
//{
//	char acHello[] = "hello\0world";
//	char acNew[15] = { 0 };
//	strcpy(acNew, acHello);
//	printf("%d %d\n", strlen(acNew), sizeof(acHello));
//}
//int main()
//{
//	char a[20];
//	char* p1 = (char*)a;
//	char* p2 = (char*)a + 5;
//	int n = p2 - p1;
//	printf("%d", n);
//}
//#define F(X,Y) ((X)+(Y))
//int main()
//{
//	int a = 3, b = 4;
//	printf("%d\n", F(a++, b++));
//}
//int main()
//{
//	int i = 1, sum = 0;
//	while (i < 10)
//	{
//		sum = sum + 1;
//		i++;
//	}
//	printf("%d %d\n", i, sum);
//}
//#pragma pack(4)
//int main()
//{
//	struct A
//	{
//		short a;
//		long c;
//		char d;
//		long b;
//		//long c;
//	};
//	printf("%d", sizeof(struct A));
//}
//#pragma pack()
//enum A
//{
//	 X1,
//	 Y1,
//	 Z1,
//	 A1,
//	 B1
//};
//enum A enumA = Y1;
//enum A enumB = B1;
//int main()
//{
//	printf("%d %d", enumA, enumB);
//	return 0;
//}
int fun(int x, int y)
{
	static int m = 0;
	static int i = 2;
	i += m + 1;
	m = i + x + y;
	return m;
}
void main()
{
	int j = 4;
	int m = 1;
	int k;
	k = fun(j, m);
	printf("%d, ", k);
	k = fun(j, m);
	printf("%d\n", k);
	return;
}