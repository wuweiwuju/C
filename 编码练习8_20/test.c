#define _CRT_SECURE_NO_WARNINGS 1
//дһ����������unsigned int�ͱ���x���ڴ��ж�����һ�ĸ���
#include<stdio.h>
#include<stdlib.h>
int num()
{
	int i = 0;
	int count = 0;
	unsigned int x = 0;
	printf("������һ���޷�������:>");
	scanf("%u", &x);
	for (i = 0; i < 32; i ++)
	{
		//�ж�ÿһλ��ֵ�Ƿ�Ϊ1
		if ((x & 1) == 1)
		{
			count++;
		}
		//����׼���ж���һλ��ֵ
		x >>= 1;
	}
	return count;
}
int main()
{

	int ret = num();
	printf("%d\n", ret);
	system("pause");
	return 0;
}