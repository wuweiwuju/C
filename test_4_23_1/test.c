#define _CRT_SECURE_NO_WARNINGS 1
/*��ȡһ�������������������е�ż��λ������λ��
�ֱ��������������*/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>



int main()

{

	int num = 10;

	int i = 0;

	printf("Please enter the num:\n");

	scanf("%d", &num);

	int a[32];
	/*10000000000000000000000000000
	00000000000000000000000000001*/
	for (; i < 32; i++)

	{

		a[i] = num % 2;//���Ŵ�Ŷ�����

		num /= 2;

	}



	printf("ż�����У�\n");

	for (i = 31; i >= 0; i -= 2)

		printf("%d", a[i]);

	printf("\n");



	printf("�������У�\n");

	for (i = 30; i >= 0; i -= 2)

		printf("%d", a[i]);



	printf("\n");

	system("pause");

	return 0;

}


//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//
//	int arr[32];
//	int m = 0, i = 0, count = 0;
//	printf("������һ��ʮ������:\n");
//	scanf("%d", &m);
//	for (i = 0; m != 0; i++)
//	{
//		arr[i] = m % 2;
//		m = m / 2;
//		count = i + 1;
//	}
//	for (; count < 32; count++)
//	{
//		arr[count] = 0;
//	}
//	printf("ת��Ϊ�����ƺ�����λΪ:\n");
//	for (i = 31; i >= 0; i -= 2)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	printf("ת��Ϊ�����ƺ�ż��λΪ��\n");
//	for (i = 30; i >= 0; i -= 2)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}

//#include <stdio.h>  
//
//int main()
//
//{
//
//	int num = 0, i = 0;
//
//	scanf("%d", &num);
//
//	printf("��������Ϊ��");
//
//	for (i = 31; i >= 0; i -= 2)  //Ҳ�ǿ���32�Σ�ÿ����������32λ���㣩��ֻ�Ǵ�31λ��ʼ�ƶ�  
//
//	{
//
//		printf("%d ", (num >> i) & 1);  //��һ�������ƶ�31λ��1��õ���һλ�����ÿ�α仯2λ�����ɵõ�����λ���  
//
//	}
//
//	printf("\n");
//
//	printf("ż������Ϊ��");
//
//	for (i = 30; i >= 0; i -= 2)  //�����ƶ�30λ������1���ý����ԭ�����ֵĵڶ�λ������28λ...  
//
//	{
//
//		printf("%d ", (num >> i) & 1);  //  
//
//	}
//
//	printf("\n");
//
//
//
//	return 0;
//
//}
