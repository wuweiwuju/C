#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//Ҫ��дһ�����������ַ����еĿո��滻��%20��������"abc defgx yz"->"abc%20defgx%20yz"
//
void ReplaceBlank(char* str, int len) {
	int MLen = 0;//�����ַ��ĸ��� 
	int NumBlank = 0;//����ո������ 
	int IndexofMLen = 0; 
	int Indexofnew = 0; 
	int newlen = 0;
	int i = 0;//��0���±꿪ʼ���� 
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
	if(newlen > len)//newlen�����������Ĵ�С������һ��ҪС��lenԭ����С����Ȼ�Ų���
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