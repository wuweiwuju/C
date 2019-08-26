#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//int main()
//{
//	char s[] = "\\123456\123456\t";
//	printf("%d\n", strlen(s));
//}
//int main()
//{
//	char acx[] = "abc";//4
//	char acy[] = { 'a','b','c' };//3
//	printf("%d %d", sizeof(acx), sizeof(acy));
//}
//int main()
//{
//	int s = 0, n;
//	for (n = 0; n < 4; n++)
//	{
//		switch (n)
//		{
//		defult: s += 4;
//		case 1:s += 1;
//		case 2:s += 2;
//		case 3:s += 3;
//		}
//	}
//	printf("%d\n", s);
//	return 0;
//}
//int main()
//
//{
//	char* pcColor = "blue1";
//	char acColor[] = "blue1";
//	printf("%d\n", sizeof(pcColor));
//	printf("%d\n", sizeof(acColor));
//	printf("%d\n", strlen(pcColor));
//	printf("%d\n", strlen(acColor));
//}
int main()
{
	unsigned long ulA = 0x11000000;
	printf("%x\n", *(unsigned char*)& ulA);
}