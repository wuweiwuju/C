#define _CRT_SECURE_NO_WARNINGS 1
//��дһ������ʵ��n^k��ʹ�õݹ�ʵ�� 
#include<stdio.h>
#include<stdlib.h>
int my_pow(int n, int k)
{
	if (k == 0)
	{
		return 1;
	}
	else if (k == 1)
	{
		return n;
	}
	else
	{
		return my_pow(n, k - 1) * n;
	}
}
int main()
{
	int n = 0;
	int k = 0;
	int ret = 0;
	scanf_s("%d %d", &n, &k);
	ret = my_pow(n, k);
	printf("%d\n", ret);
	system("pause");
	return 0;
}