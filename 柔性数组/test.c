#define _CRT_SECURE_NO_WARNINGS 1
typedef struct st_type
{
	int i;
	int a[0];//柔性数组成员
}type_a;
//有些编译器会报错无法编译可以改成：
typedef struct st_type
{
	int i;
	int a[];//柔性数组成员
}type_a;
//结构中的柔性数组成员前面必须至少一个其他成员。
//sizeof 返回的这种结构大小不包括柔性数组的内存。
//包含柔性数组成员的结构用malloc()函数进行内存的动态分配，并且分配的内存应该大于结构的大小，以适应
//柔性数组的预期大小。

柔性数组的特点：
结构中的柔性数组成员前面必须至少一个其他成员。
sizeof 返回的这种结构大小不包括柔性数组的内存。
包含柔性数组成员的结构用malloc()函数进行内存的动态分配，并且分配的内存应该大于结构的大小，以适应
柔性数组的预期大小。
例如：
//code1
typedef struct st_type
{
	int i;
	int a[0];//柔性数组成员
}type_a;
printf("%d\n", sizeof(type_a));//输出的是4
柔性数组的使用
//代码1
int i = 0;
type_a* p = (type_a*)malloc(sizeof(type_a) + 100 * sizeof(int));
//业务处理
p->i = 100;
for (i = 0; i < 100; i++) { p->a[i] = i; }
free(p);
这样柔性数组成员a，相当于获得了100个整型元素的连续空间。
柔性数组的优势
上述的 type_a 结构也可以设计为：
//代码2
typedef struct st_type
{
	int i;
	int* p_a;
}type_a;
type_a* p = malloc(sizeof(type_a));
p->i = 100; p->p_a = (int*)malloc(p->i * sizeof(int));
//业务处理
for (i = 0; i < 100; i++) { p->p_a[i] = i; }
//释放空间
free(p->p_a);
p->p_a = NULL;
free(p);
p = NULL;
上述 代码1 和 代码2 可以完成同样的功能，但是 方法1 的实现有两个好处： 第一个好处是：方便内存释放
如果我们的代码是在一个给别人用的函数中，你在里面做了二次内存分配，并把整个结构体返回给用户。用
户调用free可以释放结构体，但是用户并不知道这个结构体内的成员也需要free，所以你不能指望用户来发
现这个事。所以，如果我们把结构体的内存以及其成员要的内存一次性分配好了，并返回给用户一个结构体
指针，用户做一次free就可以把所有的内存也给释放掉。
第二个好处是：这样有利于访问速度.
连续的内存有益于提高访问速度，也有益于减少内存碎片。（其实，我个人觉得也没多高了，反正你跑不了