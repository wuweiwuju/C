#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//题目一
//void GetMemory(char** p)
//{
//	*p = (char*)malloc(100);
//}
//void Test(void)
//{
//	char* str = NULL;
//	GetMemory(&str);
//	strcpy(str, "hello word");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}
//题目二
//char* GetMemory(void) 
//{
//	char p[] = "hello world";//局部变量存在栈中，出函数就销毁
//	return p;
//}
//void Test(void) 
//{
//	char* str = NULL;
//	str = GetMemory();
//	printf(str);
//}
//int main()
//{
//	Test();
//	return 0;
//}
//题目三
//void GetMemory(char** p, int num) {
//	*p = (char*)malloc(num);
//}
//void Test(void) {
//	char* str = NULL;
//	GetMemory(&str, 100);
//	strcpy(str, "hello");
//	printf(str);
//	free(str);
//	str = NULL;
//}
//int main()
//{
//	Test();
//	return 0;
//}
////题目四
void Test(void)
{
	char* str = (char*)malloc(100);
	strcpy(str, "hello");
	free(str);
	str = NULL;
	if (str != NULL)
	{
		strcpy(str, "word");
		printf(str);
	}
}
int main()
{
	Test();
	return 0;
}
//int* f1(void)
//{
//	int x = 10;
//	return (&x);
//}
//int main()
//{
//	int* p = f1();
//	printf("%d\n", p);
//	return 0;
//}
//
//int* f1(void)
//{
//	int* x; // x存的是随机值，是一个野指针，访问会出错
//	*x = 10;
//	return x;
//}