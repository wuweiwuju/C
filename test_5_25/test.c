#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//template<class Type>
//void Swap(Type &a,Type &b)
//{
//	Type tmp = a;
//	a = b;
//	b = tmp;
//}
int SecValue(int* ar, int n)//�ڶ���ֵ
{
	assert(ar != 'NULL' && n > 1);
	int i = 0;
	int max = 0;
	int second = 0;
	ar[0] > ar[1] ? (max = ar[0], second = ar[1]) : (max = ar[1],second = ar[0]);
	for (i = 2; i < n; i++)
	{
		if (ar[i] > max)
		{
			second = max;
			max = ar[i];
		}
		else if (ar[i] > second)
		{
			second = ar[i];
		}
	}
	return second;
}
void Sort(int* ar,int n)//����
{
	assert(ar != 'NULL' && n > 0);
	int i = 0;
	int j = 0;
	int tmp = 0;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (ar[j] > ar[j + 1])
			{
				tmp = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = tmp;
			}
		}
	}
	printf("�����С���������>:");
	for (i = 0; i < n; i++)
	{
		printf("%d ", ar[i]);
	}
	printf("\n");
}
void Revers(int* ar, int n)//ת��
{
	/*assert(ar != 'NULL' && n > 0);*/
	int start = 0;
	int i = 0;
	int end = n - 1;
	int tmp = 0;

	while (start < end)
	{
		tmp = ar[start];
		ar[start] = ar[end];
		ar[end] = tmp;
		start++;
		end--;
	}
	printf("ת�ú�>: ");
	for (i = 0; i < n; i++)
	{
		printf("%d ", ar[i]);
	}
	printf("\n");
}
int main()
{
	int ar[] = { 11,2,3,4,5,61,7,8,92,10 };
	int n = sizeof(ar) / sizeof(int);
	int i = 0;
	int ret = 0;
	printf("ԭ������ > :");
	for (i = 0; i < n; i++)
	{
		printf("%d ", ar[i]);
	}
	printf("\n");
	ret = SecValue(ar, n);
	printf("�ڶ���ֵ��>:%d\n", ret);
	Revers(ar, n);
	Sort(ar, n);
	system("pause");
	return 0;
}