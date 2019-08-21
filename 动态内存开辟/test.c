#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
//int main()
//{
//	////代码1
//	//int num = 0;
//	//scanf("%d", &num);
//	//int arr[num] = { 0 };
//	//代码2
//	int* ptr = NULL;
//	//ptr = (int*)malloc(10 * sizeof(int));
//	ptr = (int*)malloc(INT_MAX);
//	if (NULL == ptr)//判断开辟是否失败
//	{
//		//printf("%s\n", strerror(errno));
//		perror("use malloc");
//	}
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(ptr + i) = 0;
//	}
//	free(ptr);//释放ptr所指向的动态内存
//	ptr = NULL;//是否有必要？  这个是要指向空的，因为free释放之后它还是指向那块空间，所以要置空
//
//	return 0;
//}

//int main()
//{
//	int* p = calloc(10, sizeof(int));
//	if (NULL != p)
//	{
//		//使用空间
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

//int main()
//{
//	int* ptr = malloc(100);
//	if (ptr != NULL)
//	{
//		//业务处理
//	}
//	else
//	{
//		exit(EXIT_FAILURE);
//	}
//	//扩展容量
//	//代码1
//	ptr = realloc(ptr, 1000);//这样可以吗？(如果申请失败会如何？)
//	//这样申请是有很大弊端的，假设申请失败，之前的数据也会消失
//	//代码2
//	int* p = NULL; p = realloc(ptr, 1000);
//	if (p != NULL)
//	{
//		ptr = p;
//	}
//	//业务处理
//	free(ptr);
//	ptr = NULL;
//	return 0;
//}
//void test()
//{
//	int* p = (int*)malloc(INT_MAX / 4);
//	*p = 20;//如果p的值是NULL，就会有问题
//	free(p);
//}
//对动态开辟空间的越界访问
//void test()
//{
//	int i = 0;
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (NULL == p)
//	{
//		exit(EXIT_FAILURE);
//	}
//	for (i = 0; i <= 10; i++)
//	{
//		*(p + i) = i;//当i是10的时候越界访问
//	}
//	free(p);
//}
//对非动态开辟内存使用free释放
//void test()
//{
//	int a = 10;
//	int* p = &a;
//	free(p);//ok?
//}
//使用free释放一块动态开辟内存的一部分
//void test()
//{
//	int* p = (int*)malloc(100);
//	p++;
//	free(p);//p不再指向动态内存的起始位置
//}
//对同一块动态内存多次释放
//void test()
//{
//	int* p = (int*)malloc(100);
//	free(p);
//	free(p);//重复释放
//}
//动态开辟内存忘记释放（内存泄漏）
//void test()
//{
//	int* p = (int*)malloc(100);
//	if (NULL != p)
//	{
//		*p = 20;
//	}
//}
//int main()
//{
//	test();
//	while (1);
//}