#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int main()
//{
//	int m, n;
//	for (m = 0, n = -1; n = 0; m++, n++)
//	{
//		n++;
//	}
//}
//int a = 1;
//void test()
//{
//	int a = 2;
//	a += 1;
//}
//int main()
//{
//	test();
//	printf("%d\n", a);
//	return 0;
//}
//int main()
//{
//	int i = 0;
//	int j = 0;
//	if (((++i) > 0) || (++j > 0))
//	{
//		printf("i=%d;j=%d\n", i, j);
//	}
//		
//
//}
//int main()
//{
//	int x = 0;
//	switch (++x)
//	{
//	case 0: ++x;
//	case 1: ++x;
//	case 2: ++x;
//	}
//
//}
//int main()
//{
//	int y = 10;
//	int x = y++;
//	printf("%d %d\n", x, y);
//}
#define MOD(x,y) x%y
int main()
{
	int a = 13, b = 94;
	printf("%d\n", MOD(b, a + 4));
}
