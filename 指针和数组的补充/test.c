#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//void fun(char* p)
//{
//	char c = p[3];//������ char c = *(p+3);
//}
//void fun(char a[])
//{
//	char c = a[3];
//}
//int main()
//{
//	char b[10] = "abcdef";
//	fun(b);
//	return 0;
//}

//void fun(char* p)
//{
//	char c = p[3];//������ char c = *(p+3);
//}
//int main()
//{
//	char* p2 = "abcdefg";
//	fun(p2);
//	return 0;
//}

//char* GetMemory(char* p, int num)
//{
//	p = (char*)malloc(num * sizeof(char));
//	return p;
//}
//int main()
//{
//	char* str = NULL;
//	str = GetMemory(str,10);
//	strcpy(str, "hello");
//	free(str);//free ��û�������ã��ڴ�й©
//	return 0;
//}

//#include <string.h>
//char* fun(char* p1, char* p2)
//{
//	int i = 0;
//	i = strcmp(p1, p2);
//	if (0 == i)
//	{
//		return p1;
//	}
//	else
//	{
//		return p2;
//	}
//}
//int main()
//{
//	char* (*pf)(char* p1, char* p2);
//	pf = &fun;
//	(*pf) ("aa", "bb");
//	return 0;
//}

//void Function()
//{
//	printf("Call Function!\n");
//}
//int main()
//{
//	void (*p)();
//	*(int*)& p = (int)Function;
//	(*p) ();
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//char* fun1(char* p)
//{
//	printf("%s\n", p);
//	return p;
//}
//char* fun2(char* p)
//{
//	printf("%s\n", p);
//	return p;
//}
//char* fun3(char* p)
//{
//	printf("%s\n", p);
//	return p;
//}
//int main()
//{
//	char* (*pf[3])(char* p);
//	pf[0] = fun1; // ����ֱ���ú�����
//	pf[1] = &fun2; // �����ú���������ȡ��ַ��
//	pf[2] = &fun3;
//	pf[0]("fun1");
//	pf[1]("fun2");
//	pf[2]("fun3");
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//char* fun1(char* p)
//{
//	printf("%s\n", p);
//	return p;
//}
//char* fun2(char* p)
//{
//	printf("%s\n", p);
//	return p;
//}
//char* fun3(char* p)
//{
//	printf("%s\n", p);
//	return p;
//}
//int main()
//{
//	char* (*a[3])(char* p);
//	char* (*(*pf)[3])(char* p);
//	pf = &a;
//	a[0] = fun1;
//	a[1] = &fun2;
//	a[2] = &fun3;
//	pf[0][0]("fun1");
//	pf[0][1]("fun2");
//	pf[0][2]("fun3");
//	return 0;
//}

//һά����
//int main()
//{
//	int a[] = { 1,2,3,4 };
//	printf("%d\n", sizeof(a)); //16
//	printf("%d\n", sizeof(a + 0)); //4
//	printf("%d\n", sizeof(*a));//4
//	printf("%d\n", sizeof(a + 1));//4
//	printf("%d\n", sizeof(a[1]));//4
//	printf("%d\n", sizeof(&a));//4
//	printf("%d\n", sizeof(*&a));//16
//	printf("%d\n", sizeof(&a + 1));//4
//	printf("%d\n", sizeof(&a[0]));//4
//	printf("%d\n", sizeof(&a[0] + 1));//4
//	return 0;
//}
//�ַ�����
//int main()
//{
//	char arr[] = { 'a','b','c','d','e','f' };
//	printf("%d\n", sizeof(arr));//6
//	printf("%d\n", sizeof(arr + 0));//4
//	printf("%d\n", sizeof(*arr));//1
//	printf("%d\n", sizeof(arr[1]));//1
//	printf("%d\n", sizeof(&arr));//4
//	printf("%d\n", sizeof(&arr + 1));//4
//	printf("%d\n", sizeof(&arr[0] + 1));//4
//	printf("%d\n", strlen(arr));//x ���ֵ(��Ϊ��֪��'\0'����)
//	printf("%d\n", strlen(arr + 0));//x ���ֵ
//	/*printf("%d\n", strlen(*arr));*///err
//	/*printf("%d\n", strlen(arr[1]))*/;//err
//	printf("%d\n", strlen(&arr));//x ���ֵ
//	printf("%d\n", strlen(&arr + 1));//x-6 ���ֵ
//	printf("%d\n", strlen(&arr[0] + 1));//x-1 ���ֵ
//	return 0;
//}
//int main()
//{
//	char arr[] = "abcdef";
//	printf("%d\n", sizeof(arr));//7
//	printf("%d\n", sizeof(arr + 0));//4
//	printf("%d\n", sizeof(*arr));//1
//	printf("%d\n", sizeof(arr[1]));//1
//	printf("%d\n", sizeof(&arr));//4
//	printf("%d\n", sizeof(&arr + 1));//4
//	printf("%d\n", sizeof(&arr[0] + 1));//4
//	printf("%d\n", strlen(arr));//6
//	printf("%d\n", strlen(arr + 0));//6
//	//printf("%d\n", strlen(*arr));//err
//	//printf("%d\n", strlen(arr[1]));//err
//	printf("%d\n", strlen(&arr));//6
//	printf("%d\n", strlen(&arr + 1));//���ֵ����Ϊ��֪��'/0'���ģ�
//	printf("%d\n", strlen(&arr[0] + 1));//5
//	return 0;
//}
//int main()
//{
//	char* p = "abcdef";
//	printf("%d\n", sizeof(p));//4
//	printf("%d\n", sizeof(p + 1));//4
//	printf("%d\n", sizeof(*p));//1
//	printf("%d\n", sizeof(p[0]));//1
//	printf("%d\n", sizeof(&p));//4
//	printf("%d\n", sizeof(&p + 1));//4
//	printf("%d\n", sizeof(&p[0] + 1));//4
//	printf("%d\n", strlen(p));//6
//	printf("%d\n", strlen(p + 1));//5
//	//printf("%d\n", strlen(*p));//err
//	//printf("%d\n", strlen(p[0]));//err
//	printf("%d\n", strlen(&p));//���ֵ
//	printf("%d\n", strlen(&p + 1));//���ֵ
//	printf("%d\n", strlen(&p[0] + 1));//5
//  return 0;
//}
//
//��ά����
//int main()
//{
//	int a[3][4] = { 0 };
//	printf("%d\n", sizeof(a));//48
//	printf("%d\n", sizeof(a[0][0]));//4
//	printf("%d\n", sizeof(a[0]));//16
//	printf("%d\n", sizeof(a[0] + 1));//4
//	printf("%d\n", sizeof(*(a[0] + 1)));//4
//	printf("%d\n", sizeof(a + 1));//4
//	printf("%d\n", sizeof(*(a + 1)));//16
//	printf("%d\n", sizeof(&a[0] + 1));//4
//	printf("%d\n", sizeof(*(&a[0] + 1)));//16
//	printf("%d\n", sizeof(*a));//16
//	printf("%d\n", sizeof(a[3]));//16 ����ע�����ַ��ֻ��ע������ʹ�С��
//  return 0;
//}
//������1
//int main()
//{
//	int a[5] = { 1, 2, 3, 4, 5 };
//	int* ptr = (int*)(&a + 1);
//	printf("%d,%d", *(a + 1), *(ptr - 1));//2  5
//	return 0;
//}
//����Ľ����ʲô��
//������2
//struct Test
//{
//	int Num;
//	char* pcName;
//	short sDate;
//	char cha[2];
//	short sBa[4];
//}*p;
////����p ��ֵΪ0x100000�� ���±���ʽ��ֵ�ֱ�Ϊ���٣�
//int main()
//{
//	printf("%p\n", p + 0x1);
//		printf("%p\n", (unsigned long)p + 0x1);
//	printf("%p\n", (unsigned int*)p + 0x1);
//	return 0;
//}
//������3
//int main()
//{
//	int a[4] = { 1, 2, 3, 4 };
//	int* ptr1 = (int*)(&a + 1);
//	int* ptr2 = (int*)((int)a + 1);
//	printf("%x,%x", ptr1[-1], *ptr2);// 4  
//	return 0;
//}
//������4
//#include <stdio.h>
//int main(int argc, char* argv[])
//{
//	int a[3][2] = { (0, 1), (2, 3), (4, 5) };
//	int* p;
//	p = a[0];
//	printf("%d", p[0]);//1
//}
//������5
//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;
//	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
//	return 0;
//}
//������6
//int main()
//{
//	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	int* ptr1 = (int*)(&aa + 1);
//	int* ptr2 = (int*)(*(aa + 1));
//	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
//	return 0;
//}
//������7
//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	char** pa = a;
//	pa++;
//	printf("%s\n", *pa);
//	return 0;
//}
//������8
int main()
{
	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = cp;
	printf("%s\n", **++cpp);
	printf("%s\n", *-- * ++cpp + 3);
	printf("%s\n", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1] + 1);
	return 0;
}