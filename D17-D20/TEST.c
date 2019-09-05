#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//int main()
//{
//	char* szStr = "abcdef";
//	szStr += 2;
//	printf("%lu\n", szStr);
//	return 0;
//}
//int main()
//{
//	int i;
//	char acNew[20] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
//	for (i = 0; i < 10; i++)
//	{
//		acNew[i] = '0';
//	}
//	printf("%d\n", strlen(acNew));//10
//	system("pause");
//	return 0;
//}
//int main()
//{
//	int i = 10;
//	long long t = sizeof(i++);
//	printf("%d\n", sizeof(i++));//10
//	system("pause");
//	return 0;
//}
//#include <stdio.h>
//int main()
//{
//	int i;
//	i = 10;
//	printf("%d\n", i);
//	printf("%d\n", sizeof(i++));
//	printf("%d\n", i);
//	return 0;
//}
//int main()
//{
//	int i = 6;
//	if (i <= 6)
//		printf("hello\n");
//	else
//		printf("bye-bye\n");
//	return 0;
//}
//int main()
//{
//	printf("%f\n",(double)10 / 4 * 4);
//}
int main()
{
	char str[5] = { 'g', 'o', 'o', 'd', '!'  };
	char str1[8] = { 'g', 'o', 'o', 'd', '!' };
	char str2[8] = "good!";
	char *str3 = "good!";
	printf("%s\n", str);
	printf("%s\n", str1);
	printf("%s\n", str2);
	printf("%s\n", str3);
	system("pause");
	return 0;
}
//
//int main()
//{
//	int i = 10;
//	long long t = sizeof(i++);
//	printf("%d", i);
//}
//
//int main()
//{
//
//	printf("%f", (double)(10 / 4 * 4));
//}
