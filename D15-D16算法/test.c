#define _CRT_SECURE_NO_WARNINGS 1
//ģ��ʵ�ֺ���pow(x,y),��ʵ��x��y�η��������x,y��������
#include<stdio.h>
#include<stdlib.h>

int my_pow(int x,int y)
{
	int sum = 1;
	if (y == 0)
		return 1;
	if (y == 1)
		return x;
	if (y < 0)
	{
		sum = 1 / (x * y);
		return sum;
	}
	while (y--)
	{
		sum *= x;
	}
	return sum;
}
int main()
{
	int x = 0;
	int y = 0;
	int ret = 0;
	scanf("%d %d", &x, &y);
	ret = my_pow(x, y);
	printf("%d\n", ret);
	system("pause");
	return 0;
}