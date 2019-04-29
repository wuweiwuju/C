
#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//	int a = -10;
//	int* p = NULL;
//	printf("%d\n", !2);
//	printf("%d\n", !0);
//	a = -a;
//	p = &a;
//	printf("%d\n", sizeof(a));
//	printf("%d\n", sizeof(int));
//		printf("%d\n", sizeof a);//这样写行不行？
//	//printf("%d\n", sizeof int);//这样写行不行？
//	return 0;
//}

//#include <stdio.h>
//void test1(int arr[])
//{
//	printf("%d\n", sizeof(arr));//(2)
//}
//void test2(char ch[])
//{
//	printf("%d\n", sizeof(ch));//(4)
//}
//int main()
//{
//	int arr[10] = { 0 };
//	char ch[10] = { 0 };
//	printf("%d\n", sizeof(arr));//(1)
//	printf("%d\n", sizeof(ch));//(3)
//	test1(arr);
//	test2(ch);
//	return 0;
//}
//问：
//（1）、（2）两个地方分别输出多少？
//（3）、（4）两个地方分别输出多少？
////++和--运算符
////前置++和--
////前置++和--：
//#include <stdio.h>
//int main()
//{
//	int a = 10;
//	int x = ++a;
//	//先对a进行自增，然后对使用a，也就是表达式的值是a自增之后的值。x为11。
//	int y = --a;
//	//先对a进行自减，然后对使用a，也就是表达式的值是a自减之后的值。y为10;
//	return 0;
//}
////后置++和--
//#include <stdio.h>
//int main()
//{
//	int a = 10;
//	int x = a++;
//	//先对a先使用，再增加，这样x的值是10；之后a变成11；
//	int y = a--;
//	//先对a先使用，再自减，这样y的值是11；之后a变成10；
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int i = 0, a = 0, b = 2, c = 3, d = 4;
//	i = a++ && ++b && d++;
//	//i = a++||++b||d++;
//	printf("a = %d\nb = %d\nc = %d\nd = %d\n", a, b, c, d);
//	return 0;
//}
//程序输出的结果是什么？


//#include<stdio.h>
//int main()
//{
//	int a = 0;
//	printf("%d", a > 5 ? 3 : -3);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a = 1;
//	int b = 2;
//	int d = 2;
//	int c = (a > b, a = b + 10, a, b = a + 1);
//	printf("%d\n", c);
//	if (a = b + 1, c = a / 2, d > 0)
//	return 0;
//}
////代码1
//int a = 1;
//int b = 2;
//int c = (a > b, a = b + 10, a, b = a + 1);//逗号表达式
//c是多少？
////代码2
//if (a = b + 1, c = a / 2, d > 0)
////代码3
//a = get_val();
//count_val(a);
//while (a > 0)
//{
//	//业务处理
//	
//}
//如果使用逗号表达式，改写：
//while (a = get_val(), count_val(a), a > 0)
//{
//	//业务处理
//}

//#include <stdio.h>
//void test1()
//{
//	printf("hehe\n");
//}
//void test2(const char* str)
//{
//	printf("%s\n", str);
//}
//int main()
//{
//	test1();  //实用（）作为函数调用操作符。
//	test2("hello bit.");//实用（）作为函数调用操作符。
//	return 0;
//}
//#include <stdio.h>
//struct Stu
//{
//	char name[10];
//	int age;
//	char sex[5];
//	double score;
//};
//void set_age1(struct Stu stu)
//{
//	stu.age = 18;
//}
//void set_age2(struct Stu* pStu)
//{
//	pStu->age = 18;//结构成员访问
//}
//int main()
//{
//	struct Stu stu;
//	struct Stu* pStu = &stu;//结构成员访问
//
//	stu.age = 20;//结构成员访问
//	set_age1(stu);
//
//	pStu->age = 20;//结构成员访问
//	set_age2(pStu);
//	return 0;
//}

//#include<stdio.h>
////实例1
//int main()
//{
//	char a = 0xb6;
//	short b = 0xb600;
//	int c = 0xb6000000;
//	if (a == 0xb6)
//		printf("a");
//	if (b == 0xb600)
//		printf("b");
//	if (c == 0xb6000000)
//		printf("c");
//	return 0;
////}
//实例2
#include<stdio.h>
int main()
{
	char c = 1;
	printf("%u\n", sizeof(c));
	printf("%u\n", sizeof(+c));
	printf("%u\n", sizeof(!c));
	return 0;
}


