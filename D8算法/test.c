#define _CRT_SECURE_NO_WARNINGS 1
//��д��������������Ԫ�س��ִ����������鳤��һ������֣���{1,2,3,5,2,2,2,3,2,2},2Ϊ��������һ�������
#include<stdio.h>
#include<stdlib.h>
int b_num(int a[],int sz)
{
	int count = 0;
	int k = 0;
	int l = 0;
	//������{1,2,2,2,2,2,2,3,3,5}
	for (int i = 0; i < sz; i++)
	{
		for (int j = 0; j < sz - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
	for (k = 0; k < sz; k++)
	{
		if (a[k] == a[k + 1])
		{
			count++;
		}
		else
		{
			if ((count+1) > (sz / 2))
			{
				return a[k];
			}

		}
	}
}
int main()
{
	int a[] = { 1,2,3,5,2,2,2,3,2 };
	int ret = b_num(a, sizeof(a) / 4);
	printf("%d\n", ret);
	system("pause");
	return 0;
}