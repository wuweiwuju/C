#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//�ṹ�����͵Ĵ���

//struct Stu
//{
//	char name[20];//����
//	int age;//����
//	char sex[5];//�Ա�
//	char id[20];
//};//�ֺ�һ��Ҫ��

//����Ľṹ�崴��

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

//�ṹ��������� 

//struct Node
//{
//	int data;
//	struct Node* next;//������ָ��
//};
//typedef struct
//{
//	int data;
//	Node* next;
//}Node;//����д����ȫ���е�
////��ȷ��Ӧ����
//typedef struct Node
//{
//	int data;
//	struct Node* next;
//}Node;
//�ṹ��ĳ�ʼ��

//struct point
//{
//	int x;
//	int y;
//}p = {1,2};//�������͵�ͬʱ����ṹ��ı����Լ���ʼ��
//struct point p1 = { 1,2 };//����ṹ��ı����Լ���ʼ��
//struct Node
//{
//	int data;
//	struct point f;
//	struct Node* next;
//}n1={5,{1,2},NULL};
//struct Node n2 = { 5,{1,2},NULL };//�ṹ��Ƕ�׳�ʼ��
//�ṹ���ڴ����
//1.��һ����Ա�ڽṹ��ƫ��λΪ0�ĵ�ַ�ϣ�
//2.������Ա����Ҫ���뵽ĳ�����֣�������������������
//	��������������Ĭ�ϵ�һ�������� �� �ó�Ա��С�Ľ�Сֵ�� VS��Ĭ�ϵ�ֵΪ8
//          Linux�е�Ĭ��ֵΪ4��
//3.�ṹ��������Ϊ��������������������
//4.���Ƕ���˽ṹ��������Ƕ�׵Ľṹ����뵽�Լ������������������������ṹ��������С����
//  ����������������Ƕ�׽ṹ��Ķ�����������������
//struct S1
//{
//	char a;    // 1  
//	double b;   //  8 
//	char c;//  1  
//};
////��С�Ƕ��٣�
////�ṹǶ���ڴ����
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
//Ϊɶ�����ڴ���룿
//1.ƽ̨ԭ�򣺲������е�Ӳ��ƽ̨���ܷ��������ַ�ϵ��������ݵģ�ĳЩӲ��ƽֻ̨����ĳЩ��ַ
//��ȡĳЩ�ض����͵����ݣ������׳�Ӳ���쳣��
//2.����ԭ�����ݽṹ(������ջ)Ӧ�þ����ܵ�����Ȼ�߽��϶��롣 ԭ�����ڣ�Ϊ�˷���δ������ڴ棬����
//����Ҫ�������ڴ���ʣ���������ڴ����ֻ��Ҫһ�Ρ�
//�ܵ���˵�ṹ���ڴ��������ÿռ任ʱ��
//��ƽṹ���ʱ�����Ǽ�Ҫ��ʡ�ռ���Ҫ��ʡʱ�䣬��ʲô��������ѵĽṹ������أ�
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
//�޸�Ĭ�϶�����
//#pragma pack(4)
//struct S
//{
//	char a;
//	double b;
//	char c;
//};
//#pragma pack()//ȡ��Ĭ�϶�����
//int main()
//{
//	printf("%d\n", sizeof(struct S));//16
//	system("pause");
//	return 0;
//}
//�ṹ�崫��
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
//�ṹ�崫��һ��Ҫ���ṹ���ָ�룬��Ϊ��������������ܡ�
//λ��
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
//ö��
//enum DAY//����
//{
//	Mon,
//	Tues,
//	Wed,
//	Thur,
//	Fri,
//	Sat,
//	Sun
//};
//enum SEX//�Ա�
//{
//	MALE,
//	FEMALE,
//	SECRET
//};
//enum COLOR//��ɫ
//{
//	RED=1,
//	BLUE,
//	BALCK,
//	WRITE=8
//};
//enum COLOR Clr = RED;//ֻ����ö�ٳ�����������ֵ
//Clr = 5;//�����൱�ڸ���ͬ���͸�ֵ
//����
//�������͵�����
//union Un
//{
//	char i;
//	int j;
//};
////���ϱ����Ķ���
//union Un un;
////�������ϵĴ�С
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