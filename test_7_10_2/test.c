#define _CRT_SECURE_NO_WARNINGS 1
//2.�ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
//���磺����s1 = AABCD��s2 = BCDAA������1
//����s1 = abcd��s2 = ACBD������0.
//
//AABCD����һ���ַ��õ�ABCDA
//AABCD���������ַ��õ�BCDAA
//
//AABCD����һ���ַ��õ�DAABC
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//int is_left(char* arr1,char* arr2)
//{
//	assert(arr1);
//	assert(arr2);
//	char* ret = NULL;
//	int sz = strlen(arr2);
//	if (strlen(arr1) != sz)
//	{
//		return 0;
//	}
//	strncat(arr1, arr1, strlen(arr1));
//	ret = strstr(arr1, arr2);
//	if (ret == NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//}
//int main()
//{
//	char arr1[] = "abcdef";
//	char* arr2 = "cdefab";
//	int ret = is_left(arr1, arr2);
//	if (ret == 1)
//	{
//		printf("find\n");
//	}
//	else
//	{
//		printf("can't find\n");
//	}
//	system("pause");
//	return 0;
//}

void  reverse(char* start, char* end)
{
	assert(start);
	assert(end);

	while (start < end)
	{

		char temp = *start;

		*start = *end;

		*end = temp;

		start++;

		end--;

	}

}

void  left_rotate(char* str, int k)
{

	int  len = strlen(str);

	//��תǰk���ַ�

	reverse(str, str + k - 1);

	//��תʣ����ַ���

	reverse(str + k, str + len - 1);

	//��ת����

	reverse(str, str + len - 1);

}

int is_rotate(char* dest, char* src)
{

	if (strlen(dest) != strlen(src))
	{

		return 0;

	}

	if (!strcmp(dest, src))
	{

		return 1;

	}

	int  k = strlen(dest);

	k--;

	while (k--)
	{

		//ÿ����תһ��

		left_rotate(src, 1);

		//�ж���ת֮��������Ƿ��Ŀ��һ��

		if (!strcmp(dest, src))
		{

			return 1;

		}

	}

	return  0;

}

int  main()
{

	char dest[100];

	char src[100];

	scanf("%s", &dest);

	scanf("%s", &src);

	printf("%d\n", is_rotate(dest, src));

	system("pause");

	return 0;

}