#define _CRT_SECURE_NO_WARNINGS 1
//дһ���������ز����������� 1 �ĸ���
//���磺 15 0000 1111 4 �� 1
//����ԭ�ͣ�
#include<stdio.h>
#include<stdlib.h>

int count_one_bits(unsigned int value)
{
	// ���� 1��λ�� 
	int num = 0;
	while (value)
	{
		if (value % 2)
			num++;
		value /= 2;
	}
	return num;
}
int main()
{
	int i = 0;
	int num = 0;
	scanf_s("%d", &i);
	num=count_one_bits(i);
	printf("%d\n",num);
	system("pause");
	return 0;
}
//#include<stdio.h>
//#include<stdlib.h>
//int count_one_bits(unsigned int value)
//{
//	int num = 0;
//	while (value)//valueΪ0ʱ����ѭ��
//	{
//		if (value % 2)//�������Ϊ1����num�Լ�1
//			num++;
//		value = value / 2;//���õ������ٸ���value
//	}
//	return num;
//}
//int main()
//{
//	int i = 0;
//	int num = 0;
//	printf("������һ��������");
//	scanf("%d", &i);
//	num = count_one_bits(i);//numΪ��¼1 �ĸ���
//	printf("num=%d\n", num);
//	system("pause");
//	return 0;
//}
