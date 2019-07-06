#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//结构体类型的创建

//struct Stu
//{
//	char name[20];//名字
//	int age;//年龄
//	char sex[5];//性别
//	char id[20];
//};//分号一定要有

//特殊的结构体创建

//struct
//{
//	int a;
//	char b;
//	float c;
//}x;
//struct
//{
//	int a;
//	char b;
//	float c;
//}a[10],*b;

//结构体的自引用 

//struct Node
//{
//	int data;
//	struct Node* next;//必须是指针
//};
//typedef struct
//{
//	int data;
//	Node* next;
//}Node;//这样写是完全不行的
////正确的应该是
//typedef struct Node
//{
//	int data;
//	struct Node* next;
//}Node;
//结构体的初始化

//struct point
//{
//	int x;
//	int y;
//}p = {1,2};//声明类型的同时定义结构体的变量以及初始化
//struct point p1 = { 1,2 };//定义结构体的变量以及初始化
//struct Node
//{
//	int data;
//	struct point f;
//	struct Node* next;
//}n1={5,{1,2},NULL};
//struct Node n2 = { 5,{1,2},NULL };//结构体嵌套初始化
//结构体内存对齐
//1.第一个成员在结构体偏移位为0的地址上；
//2.其它成员变量要对齐到某个数字（对齐数）的整数倍上
//	对齐数：编译器默认的一个对齐数 与 该成员大小的较小值。 VS中默认的值为8
//          Linux中的默认值为4；
//3.结构体最终数为最大对齐数的整数倍数；
//4.如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，结构体的整体大小就是
//  所有最大对齐数（含嵌套结构体的对齐数）的整数倍。
//struct S1
//{
//	char a;    // 1  
//	double b;   //  8 
//	char c;//  1  
//};
////大小是多少？
////结构嵌套内存对齐
//struct S2
//{
//	char a;    // 1  
//	struct S1 p;//24
//	double b;   //  8 
//};
//int main()
//{
//	printf("%d\n", sizeof(struct S1));//24
//	printf("%d\n", sizeof(struct S2));//40
//	system("pause");
//	return 0;
//}
//为啥存在内存对齐？
//1.平台原因：不是所有的硬件平台都能访问任意地址上的任意数据的；某些硬件平台只能在某些地址
//处取某些特定类型的数据，否则抛出硬件异常。
//2.性能原因：数据结构(尤其是栈)应该尽可能地在自然边界上对齐。 原因在于，为了访问未对齐的内存，处理
//器需要作两次内存访问；而对齐的内存访问只需要一次。
//总的来说结构体内存对齐就是用空间换时间
//设计结构体的时候我们既要节省空间又要节省时间，那什么样才是最佳的结构体设计呢？
//struct S
//{
//	char a;
//	double b;
//	char c;
//};
//struct S1
//{
//	char a;
//	char c;
//	double b;
//};
//修改默认对齐数
//#pragma pack(4)
//struct S
//{
//	char a;
//	double b;
//	char c;
//};
//#pragma pack()//取消默认对齐数
//int main()
//{
//	printf("%d\n", sizeof(struct S));//16
//	system("pause");
//	return 0;
//}
//结构体传参
//struct s
//{
//	int data[100];
//	int num;
//};
//struct s x = { {1,2,3},1000 };
//void print(struct s p)
//{
//	printf("%d\n", p.num);
//}
//void print1(struct s *p)
//{
//	printf("%d\n", p->num);
//}
//int main()
//{
//	print(x);
//	print1(&x);
//	system("pause");
//	return 0;
//}
//结构体传参一定要传结构体的指针，因为这样可以提高性能。
//位段
//struct A
//{
//	int a : 2;
//	int b : 5;
//	int c : 10;
//	int d : 30;
//};
//struct S {
//	char a : 3;
//	char b : 4;
//	char c : 5;
//	char d : 4;
//};
//struct S s = { 0 };
//int main()
//{
//	s.a = 10;
//	s.b = 12;
//	s.c = 3;
//	s.d = 4;
//	printf("%d\n", sizeof(struct S));//3
//	system("pause");
//	return  0;
//}
//枚举
//enum DAY//星期
//{
//	Mon,
//	Tues,
//	Wed,
//	Thur,
//	Fri,
//	Sat,
//	Sun
//};
//enum SEX//性别
//{
//	MALE,
//	FEMALE,
//	SECRET
//};
//enum COLOR//颜色
//{
//	RED=1,
//	BLUE,
//	BALCK,
//	WRITE=8
//};
//enum COLOR Clr = RED;//只能拿枚举常量给变量赋值
//Clr = 5;//这种相当于给不同类型赋值
//联合
//联合类型的声明
//union Un
//{
//	char i;
//	int j;
//};
////联合变量的定义
//union Un un;
////计算联合的大小
//int main()
//{
//	printf("%d\n", sizeof(un));
//	//printf("%d\n", &(un.i));
//	//printf("%d\n", &(un.j));
//	un.i = 0x55;
//	un.j = 0x11223344;
//	printf("%x\n", un.j);
//	system("pause");
//	return 0;
//}

union Un
{
	char c[5];
	int i;
};
union Un1
{
	char c[7];
	int i;
};
int main()
{
	printf("%d\n", sizeof(union Un));//8
	printf("%d\n", sizeof(union Un1));//8
	system("pause");
	return 0;
}