#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//要求写一个函数，将字符串中的空格替换成%20。样例："abc defgx yz"->"abc%20defgx%20yz"
//
void ReplaceBlank(char* str, int len) {
	int MLen = 0;//计算字符的个数 
	int NumBlank = 0;//计算空格的数组 
	int IndexofMLen = 0; 
	int Indexofnew = 0; 
	int newlen = 0;
	int i = 0;//从0号下标开始遍历 
	if(str == NULL || len <= 0) 
	{ 
		return ; 
	}
	while(str[i] != '\0')
	{ 
		++MLen;
		if(str[i] == ' ')
		{ 
			++NumBlank;
		}
		++i;
	}
	newlen = MLen + NumBlank * 2;//a%20b%20c%20d a b c d
	if(newlen > len)//newlen是扩充后数组的大小，所以一定要小于len原来大小，不然放不下
	{ 
		return; 
	}
	IndexofMLen = MLen; 
	Indexofnew = newlen; 
	while(IndexofMLen >= 0 && Indexofnew >IndexofMLen) 
	{ 
		if(str[IndexofMLen] == ' ') 
		{ 
			str[Indexofnew--] = '0';
			str[Indexofnew--] = '2';
			str[Indexofnew--] = '%';
		}
		else
		{ 
			str[Indexofnew--] = str[IndexofMLen]; 
		}
		--IndexofMLen; 
	} 
}
int main()
{ 
	char str[30] = "a b c d";
	int len = (sizeof(str) / sizeof(str[0])); 
	ReplaceBlank(str, len);
	printf("%s\n", str);
	return 0; 
}