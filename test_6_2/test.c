#define _CRT_SECURE_NO_WARNINGS 1
//1.��д������
//unsigned int reverse_bit(unsigned int value);
//��������ķ���ֵvalue�Ķ�����λģʽ�����ҷ�ת���ֵ��
//
//�磺
//��32λ������25���ֵ�������и�λ��
//00000000000000000000000000011001
//��ת�󣺣�2550136832��
//10011000000000000000000000000000
//���������أ�
//2550136832
//δ�Ż�
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
//#include<math.h>
//unsigned int reverse_bit(unsigned int value)
//{
//	int i = 0;
//	int sum = 0;
//	for (i = 0; i < 32; i++)
//	{
//		sum+=((value >> i) & 1) * pow(2, 31 - i);
//	}
//	return sum;
//}
//int main()
//{
//	unsigned int a = 25;
//	unsigned int ret = reverse_bit(a);
//	printf("%u\n", ret);
//	system("pause");
//	return 0;
//}
//�Ż���
//unsigned int reverse_bit(unsigned int value)
//{
//	int i = 0;
//	unsigned int sum = 0;
//	for (i = 0; i < 32; i++)
//	{
//		sum <<= 1;
//		sum |= ((value >> i) & 1);
//	}
//	return sum;
//}
//int main()
//{
//	unsigned int a = 25;
//	unsigned int ret = reverse_bit(a);
//	printf("%u\n", ret);
//	system("pause");
//	return 0;
//}
//2.��ʹ�ã�a + b�� / 2���ַ�ʽ������������ƽ��ֵ��
//int average_value(int a, int b)
//{
//	/*return (a + b) >>1;*/
//	return (a & b) + ((a ^ b) >> 1);
//}
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int ret = 0;
//	scanf_s("%d %d", &a, &b);
//	ret = average_value(a, b);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}
//3.���ʵ�֣�
//һ��������ֻ��һ�����ֳ�����һ�Ρ������������ֶ��ǳɶԳ��ֵġ�
//���ҳ�������֡���ʹ��λ���㣩
//δ��չ
//int find(int* arr, int sz)
//{
//	assert(arr != NULL);
//	int i = 0;
//	int num = 0;
//	for (i = 0; i < sz; i++)
//	{
//		num ^= arr[i];
//	}
//	return num;
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,5,4,2,3,1 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//	printf("%d\n", find(arr, n));
//	system("pause");
//	return 0;
//}
//4.
//��һ���ַ����������Ϊ:"student a am i",
//	���㽫��������ݸ�Ϊ"i am a student".
//	Ҫ��
//	����ʹ�ÿ⺯����
//	ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���
void reverse_str(char* left, char* right)
{
	assert(left != NULL);
	assert(right != NULL);
	while (left < right)
	{
		int temp = *left;
		*left = *right;
		*right = temp;
		left++;
		right--;
	}
}
void reverse(char* str,int sz)
{
	assert(str != NULL);
	//���������ַ���
	reverse_str(str, str + sz - 1);
	//���򵥸�����
	while (*str)
	{
		char* start = str;
		while ((*str != ' ')&&(*str!='\0'))
		{
			str++;
		}
		reverse_str(start, str - 1);
		if (*str != '\0')
		{
			str++;
		}
	}
}
int Strlen(char* str)
{
	int len = 0;
	assert(str != NULL);
	while (*str)
	{
		len++;
		str++;
	}
	return len;
}
int main()
{
	char arr[] = "student a am i";
	int n = Strlen(arr);
	printf("ԭ��������Ϊ:>%s\n", arr);
	reverse(arr, n);
	printf("����������Ϊ:>%s\n", arr);
	system("pause");
	return 0;
}