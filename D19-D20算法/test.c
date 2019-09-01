#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//字符串压缩 输入字符串只包含a-z字母以及结束标志，请编写函数实现对连续出现的相同字符进行压缩
//例如："xxxyyyyz"压缩后字符串为"3x4yz"
//int main()
//{
//	char str[] = "xxxyyyyz";//3x4yz
//	int strLength = strlen(str);
//	int count = 1;//记录重复个数
//	int i;
//	for (i = 0; i < strLength; i++)
//	{
//		if (str[i + 1] == str[i])
//		{
//			count++;
//		}
//		else
//		{
//			if (count == 1)
//			{
//				printf("%c", str[i]);
//			}
//			else
//			{
//				printf("%d%c", count, str[i]);
//			}
//			count = 1;//重置
//		}
//	}
//	printf("\n");
//	system("pause");
//	return 0;
//}
//void Compress(char* str)
//{ 
//	int count = 1;
//	int i = 0;
//	assert(str != NULL);
//	while (str[i] != '\0') 
//	{ 
//		if (str[i] == str[i + 1]) 
//		{ 
//			count++;
//		} 
//		else
//		{ 
//			if (count != 1)
//				printf("%d", count);
//				printf("%c", str[i]);
//			count = 1;
//		}
//		i++;
//	}
//	printf("\n");
//}
//int main()
//{
//	Compress("xxyyyz");
//	Compress("xyyyz");
//	Compress("xxxxx");
//	Compress("aabbccdaa");
//	return 0; 
//}
//编写代码完成如下功能：删除字符串首尾的空格，中间的连续空格只留一个，原来字符串的顺序不变
//例如："*****as****adadp*****"(*是空格)变成"as*adadp"
void Deblank(char* str) 
{
	int flag = 0; //代表没开始处理空格
	int p = 0; 
	int i = 0; 
	while(str[i] !='\0')
	{
		//遇到空格 还没开始处理
		if(!flag &&str[i] == ' ')// 遇到空格 让i往后走到不是空格的地方 
		{ 
			i++;
		}//遇到不是空格 还没开始处理 
		else if(!flag &&str[i] != ' ')//不是空格的字符向前赋值 
		{ 
			flag = 1; //开始处理空格 
			str[p++] = str[i++];
		}//遇到空格 开始处理了 
		else if(flag &&str[i] == ' ') 
		{ 
			flag = 0; //不处理 
			str[p++] = str[i++];
		}
		else 
		
		{ 
			str[p++] = str[i++]; 
			flag = 1;
		}
	}
	if(str[p-1] == ' ') //结尾处多余空格 
		str[p-1] = '\0';
	else str[p] = '\0';
}
int main() 
{ 
	char str[] = " as adad q ";
	Deblank(str);
	printf("%s",str);
	return 0;
}