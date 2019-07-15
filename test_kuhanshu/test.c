#define _CRT_SECURE_NO_WARNINGS 1
//strtok
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
//int main()
//{
//	char str[] = "- This, a sample string.";
//	char* pch;
//	printf("Splitting string \"%s\" into tokens:\n", str);
//	pch = strtok(str, " ,.-");
//	while (pch != NULL)
//	{
//		printf("%s\n", pch);
//		pch = strtok(NULL, " ,.-");
//	}
//	return 0;
//}
//int main()
//{
//	char* p = "lipeng@fei.jsp";
//	const char* seq = "@.";
//	char arr[30];
//	char* str = NULL;
//	strcpy(arr, p);//拷贝一份数据，处理arr数组的内容
//	for (str = strtok(arr, seq); str != NULL; str = strtok(NULL, seq))
//	{
//		printf("%s\n", str);
//	}
//	return 0;
//}
//strerror
//#include<errno.h>//必须包含的头文件
//int main()
//{
//	FILE* pFile;
//	pFile = fopen("unexist.ent", "r");
//	if (pFile == NULL)
//		printf("Error opening file unexist.ent: %s\n", strerror(errno));
//	//errno: Last error number
//	return 0;
//}
//tolower
//int main()
//{
//	int i = 0;
//		char str[] = "test string.\n";
//	char c;
//	while (str[i])
//	{
//		c = str[i];
//		if (islower(c))
//			c = toupper(c);
//		putchar(c);
//		i++;
//	}
//	return 0;
//}
//memcmp
//int main()
//{
//	char buffer1[] = "DWgaOtP12df0";
//	char buffer2[] = "DWGAOTP12DF0";
//	int n; n = memcmp(buffer1, buffer2, 6);
//	if (n > 0) printf("'%s' is greater than '%s'.\n", buffer1, buffer2);
//	else if (n < 0) printf("'%s' is less than '%s'.\n", buffer1, buffer2);
//	else printf("'%s' is the same as '%s'.\n", buffer1, buffer2);
//	return 0;
//}
//memset

#include <memory.h>
#include <stdio.h>

int main( )
{
	char buffer[] = "This is a test of the memset function";

	printf("Before: %s\n", buffer);
	memset(buffer, '*', 4);
	printf("After:  %s\n", buffer);
}
