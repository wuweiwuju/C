#define _CRT_SECURE_NO_WARNINGS 1
//冒泡排序的三种实现
//第一种常规函数实现
//#include<stdio.h>
//#include<stdlib.h>
//void bubble_sort(int *arr,int sz)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < sz - 1; i++)
//	{
//		for (j = 0; j < sz - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j + 1];
//				arr[j + 1] = arr[j];
//				arr[j] = tmp;
//			}
//		}
//	}
//}
//void print_sort(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%3d ", arr[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//	int arr[] = { 2,5,6,8,14,65,98,63,0,4 };
//	int n = sizeof(arr) / sizeof(int);
//	print_sort(arr, n);
//	bubble_sort(arr, n);
//	print_sort(arr, n);
//	system("pause");
//	return 0;
//}
//只能进行整数的排序
//库函数排序
//-整数的比较
//#include<stdio.h>
//#include<stdlib.h>
///*void qsort(void* base,
//	size_t num,
//	size_t width,
//	int(__cdecl* compare)(const void* elem1, const void* elem2));
//	*/
//int  cmp_int(const void* e1, const void* e2)
//{
//	return *(int *)e1 - *(int *)e2;
//}
//void print_sort(int* arr, int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%3d ", arr[i]);
//	}
//	printf("\n");
//}
//int main()
//{
//	int arr[] = { 2,5,6,8,14,65,98,63,0,4 };
//	int n = sizeof(arr) / sizeof(int);
//	print_sort(arr, n);
//	qsort(arr,n, sizeof(int),cmp_int);
//	print_sort(arr, n);
//	system("pause");
//	return 0;
//}
//-结构体的比较
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//struct S
//{
//	char name[20];
//	int age;
//};
////int s_b_name(const char* e1, const char* e2)
////{
////	return strcmp(((struct S*)e1)->name, ((struct S*)e2)->name);
////}
//int s_b_age(const char* e1, const char* e2)
//{
//	return ((struct S*)e1)->age-((struct S*)e2)->age;
//}
//void output(struct S s[], int n)
//{
//	int i = 0;
//	for(i=0;i<n;i++)
//	{
//		printf("%d ", s[i].age);
//	}
//	printf("\n");
//}
////void test()
////{
////	struct S arr[] = { {"zhangsan",15},{"lisi",35},{"wangwu",20} };
////	output(arr, sizeof(arr) / sizeof(arr[0]));
////	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(struct S), s_b_name);
////	output(arr, sizeof(arr) / sizeof(arr[0]));
////}
//void test1()
//{
//	struct S arr[] = { {"zhangsan",15},{"lisi",35},{"wangwu",20} };
//	output(arr, sizeof(arr) / sizeof(arr[0]));
//	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(struct S), s_b_age);
//	output(arr, sizeof(arr) / sizeof(arr[0]));
//}
//int main()
//{
//	/*test();*/
//	test1();
//	system("pause");
//	return 0;
//}
//自己定义的库函数排序
#include<stdio.h>
#include<stdlib.h>
struct S
{
	char name[20];
	int age;
};
void swap(char* buf1,char* buf2,int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		int tmp = *buf2;
		*buf2 = *buf1;
		*buf1 = tmp;
		buf2++;
		buf1++;
	}
}
int s_b_name(const char* e1, const char* e2)
{
	return strcmp(((struct S*)e1)->name, ((struct S*)e2)->name);
}
//int s_b_age(const char* e1, const char* e2)
//{
//	return ((struct S*)e1)->age-((struct S*)e2)->age;
//}
//int cmp_int(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
void bubble_sort(void *base,int num,int width, int(* cmp)(const void* e1, const void* e2))
{
	int i = 0;
	int j = 0;
	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j < num - i - 1; j++)
		{
			if (cmp((char *)base+j*width,(char*)base + (j+1) * width)>0)
			{
				swap((char*)base + j * width, (char*)base + (j + 1) * width,width);
			}
		}
	}
}
//void print_sort(int* arr,int sz)
//{
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
void output(struct S s[], int n)
{
	int i = 0;
	for(i=0;i<n;i++)
	{
		printf("%s ", s[i].name);
	}
	printf("\n");
}
//void test1()
//{
//	int arr[] = { 1,3,5,7,9,2,4,6,8,0 };
//	print_sort(arr, sizeof(arr) / sizeof(int));
//	bubble_sort(arr, sizeof(arr) / sizeof(int), sizeof(int), cmp_int);
//	print_sort(arr, sizeof(arr) / sizeof(int));
//}
void test2()
{
	/*int arr[] = { 1,3,5,7,9,2,4,6,8,0 };*/
	struct S arr[] = { {"zhangsan",15},{"lisi",35},{"wangwu",20} };
	output(arr, sizeof(arr) / sizeof(arr[0]));
	qsort(arr, sizeof(arr) / sizeof(arr[0]), sizeof(struct S), s_b_name);
	output(arr, sizeof(arr) / sizeof(arr[0]));
}
int main()
{
	/*test1();*/
	test2();
	system("pause");
	return 0;
}
//任意数都可以排序



//#include <stdio.h>
//#include <stdlib.h>
//#include<string.h>
//struct record
//{
//	char name[35];
//	int point;
//	int match[3];
//	int goal[2];
//};
//
//int compare(const void* p1, const void* p2);
//void input(struct record s[], int n);
//void output(struct record s[], int n);
//
//int main()
//{
//	struct record team[35];
//	int teams = 35;
//	input(team, 5);
//	qsort(team, teams, sizeof(team[0]), compare);
//	output(team, 5);
//	return 0;
//}
//
//int compare(const void* p1, const void* p2)
//{
//	struct record* a = (struct record*)p1;
//	struct record* b = (struct record*)p2;
//	int result = 0;
//	if (a->point > b->point)
//		return -1;
//	else if (a->point < b->point)
//		return 1;
//	else
//		return 0;
//
//}
//
//void output(struct record s[], int n)
//{
//	int i = 0;
//	while (i < n)
//	{
//		printf("%d ", s[i].point);
//		i++;
//	}
//	return;
//}
//
//void input(struct record s[], int n)
//{
//
//	int i = 0;
//	while (i < n)
//	{
//		scanf("%d", &(s[i].point));
//		i++;
//	}
//	return;
//}