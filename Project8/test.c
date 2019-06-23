#define _CRT_SECURE_NO_WARNINGS 1
//模拟实现strlen
//方法一
//#include<stdio.h>
//#include<assert.h>
//size_t my_strlen(const char* str)
//{
//	int count = 0;
//	assert(str != NULL);
//	while (*str)
//	{
//		str++;
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	char* a = "abcde";
//	int ret = my_strlen(a);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}
//
//方法二
//size_t my_strlen(const char* str)
//{
//	assert(str != NULL);
//	char* start = str;
//	while (*str)
//	{
//		str++;
//	}
//	return str - start;
//}
//int main()
//{
//	char* a = "abcde";
//	int ret = my_strlen(a);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}
//方法三
//size_t my_strlen(const char* str)
//{
//	assert(str != NULL);
//	if (*str != '\0')
//	{
//		return 1 + my_strlen(str + 1);
//	}
//	else
//		return 0;
//}
//int main()
//{
//	char* a = "abcde";
//	int ret = my_strlen(a);
//	printf("%d\n", ret);
//	system("pause");
//	return 0;
//}