#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//int main()
//{
//	int num1 = 1;
//	int num2 = 2;
//	int a, b, c;
//	a=num1& num2;
//	printf("%d\n",a);
//	c=num1 | num2;
//	printf("%d\n", c);
//	b=num1^ num2;
//	printf("%d\n", b);
//	return 0;
//}

//���ܴ�����ʱ��������������������ʵ���������Ľ�����
//#include <stdio.h>
//int main()
//{
//	int a = 10;
//	int b = 20;
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("a = %d b = %d\n", a, b);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	int num = 10;
//	int count = 0;//����
//	while (num)
//	{
//		if (num % 2 == 1)
//			count++;
//		num = num / 2;
//	}
//	printf("��������1�ĸ��� = %d\n", count);
//	return 0;
//}


//#include <stdio.h>
//int main()
//{
//	int num = 10;
//	int i = 0;
//	int count = 0;//����
//	for (i = 0; i < 32; i++)
//	{
//		if (((num >> i) & 1) == 1)
//			count++;
//	}
//	printf("��������1�ĸ��� = %d\n", count);
//	return 0;
//}
//˼�����ܲ��ܸ����Ż����������ѭ��32�εġ�
//����3��
#include <stdio.h>
int main()
{
	int num = -1;
	int i = 0;
	int count = 0;//����
	while (num)
	{
		count++;
		num = num & (num - 1);
	}
	printf("��������1�ĸ��� = %d\n", count);
	return 0;
}