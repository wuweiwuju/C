#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
//������̨�� һ�ο�����һ�� �� ��������������
//����n�׵�̨���м�������
//n = 1 ʱ  1��
//n = 2 ʱ  2��
//n = 3 ʱ  3��
//n = 4 ʱ  5��
//n = 5 ʱ  8��
//�����׿���������쳲��������� 
//f(n) = f(n-1) + f(n-2) n>=2
//Ҳ������ô���
//��һ����һ�� ��ʣ n - 1 �� ����f(n-1)������
//��һ�������� ��ʣ n - 2 �� ����f(n-2)������
//�����ܵ�����f(n) = f(n-1) + f(n-2)
int fib(int n)
{
	if (n == 1 || n == 2)
		return n;
	return fib(n - 1) + fib(n - 2);
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	ret = fib(n);
	printf("%d \n", ret);
	system("pause");
	return 0;
}