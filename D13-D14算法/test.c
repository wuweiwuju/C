#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//int main()
//{
//	int i = 0;
//	while (1)
//	{
//		if (i == 1)
//		{
//			;
//		}
//		else
//		{
//			break;
//		}
//		i = 3;
//	}
//	printf("%d\n", i);
//	return 0;
//}
//��дһ����������һ�������Ƿ��ǻ��������������������һ�����������˳���������һ���ġ�
//int JP_number(int num)
//{
//	//1221
//	//n = 1221; 1221 ; 1221/10
//	//tmp = 1
//	//sum = 1
//	//n = 122 122 122/10
//	//tmp = 2
//	//sum = 12
//	//n = 12  12  12/10
//	//tmp = 2
//	//sum = 122
//	//n = 1  1  1/10
//	//tmp = 1
//	//sum = 1221
//	int n = 0;
//	int tmp = 0;
//	int sum = 0;
//	for (n = num; n; n /= 10)
//	{
//		tmp = n % 10;
//		sum = sum * 10 + tmp;
//	}
//	if (sum == num)
//		return 1;
//		return 0;
//
//}
//int main()
//{
//	int a = 0;
//	int ret = 0;
//	scanf("%d", &a);
//	ret = JP_number(a);
//	if (ret == 0)
//	{
//		printf("���ǻ�������\n");
//	}
//	if (ret == 1)
//	{
//		printf("�ǻ�������\n");
//	}
//	system("pause");
//	return 0;
//}
//���������ַ��������ڵ�һ���ַ�����ɾ���ڶ����ַ���������
//eg: "abc de fasd"��"cds" ��� "ab e fa"
int main()
{
	char s1[]= "They are students.";
	char s2[] = "aeiou";
	int sz1 = strlen(s1);
	int sz2 = strlen(s2);
	int num = 0;
	for (int j = 0; j < sz2; j++)
	{
		for (int i = 0; i < sz1; i++)
		{
			if (s1[i] == s2[j])
			{
				num = i;
				while (s1[i])
				{
					s1[i] = s1[i + 1];
					i++;
				}
				sz1--;
				i = num;
			}
		}
	}
	printf("%s\n", s1);
	system("pause");
	return 0;
}