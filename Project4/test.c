#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main()
//{
//	int i = 0;
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	return 0;
//}
//
////��unsigned int ������Ϊuint_32, ����uint_32Ҳ��һ��������
//typedef unsigned int uint_32;
//int main()
//{
//	//�۲�num1��num2,������������������һ����
//	unsigned int num1 = 0;
//	uint_32 num2 = 0;
//	return 0;
//}
//����1
#include <stdio.h>
void test()
{
	int i = 0;
	i++;
	printf("%d ", i);
}
int main()
{
	int i;
	for (i = 0; i < 10; i++)
	{
		test();
	}
	return 0;
}
////����2
//#include <stdio.h>
//void test()
//{
//	static int i = 0;
//	i++;
//	printf("%d ", i);
//}
//int main()
//{
//	for (i = 0; i < 10; i++)
//	{
//		test();
//	}
//	return 0;