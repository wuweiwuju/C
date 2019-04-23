#define _CRT_SECURE_NO_WARNINGS 1
/*获取一个数二进制序列中所有的偶数位和奇数位，
分别输出二进制序列*/

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

		a[i] = num % 2;//倒着存放二进制

		num /= 2;

	}



	printf("偶数序列：\n");

	for (i = 31; i >= 0; i -= 2)

		printf("%d", a[i]);

	printf("\n");



	printf("奇数序列：\n");

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
//	printf("请输入一个十进制数:\n");
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
//	printf("转换为二进制后奇数位为:\n");
//	for (i = 31; i >= 0; i -= 2)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//	printf("转换为二进制后偶数位为：\n");
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
//	printf("奇数序列为：");
//
//	for (i = 31; i >= 0; i -= 2)  //也是控制32次（每个整型数按32位来算），只是从31位开始移动  
//
//	{
//
//		printf("%d ", (num >> i) & 1);  //第一次向右移动31位和1与得到第一位情况，每次变化2位，即可得到奇数位情况  
//
//	}
//
//	printf("\n");
//
//	printf("偶数序列为：");
//
//	for (i = 30; i >= 0; i -= 2)  //向右移动30位，再与1所得结果是原来数字的第二位，再移28位...  
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
