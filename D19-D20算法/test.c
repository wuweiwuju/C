#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
//�ַ���ѹ�� �����ַ���ֻ����a-z��ĸ�Լ�������־�����д����ʵ�ֶ��������ֵ���ͬ�ַ�����ѹ��
//���磺"xxxyyyyz"ѹ�����ַ���Ϊ"3x4yz"
//int main()
//{
//	char str[] = "xxxyyyyz";//3x4yz
//	int strLength = strlen(str);
//	int count = 1;//��¼�ظ�����
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
//			count = 1;//����
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
//��д����������¹��ܣ�ɾ���ַ�����β�Ŀո��м�������ո�ֻ��һ����ԭ���ַ�����˳�򲻱�
//���磺"*****as****adadp*****"(*�ǿո�)���"as*adadp"
void Deblank(char* str) 
{
	int flag = 0; //����û��ʼ����ո�
	int p = 0; 
	int i = 0; 
	while(str[i] !='\0')
	{
		//�����ո� ��û��ʼ����
		if(!flag &&str[i] == ' ')// �����ո� ��i�����ߵ����ǿո�ĵط� 
		{ 
			i++;
		}//�������ǿո� ��û��ʼ���� 
		else if(!flag &&str[i] != ' ')//���ǿո���ַ���ǰ��ֵ 
		{ 
			flag = 1; //��ʼ����ո� 
			str[p++] = str[i++];
		}//�����ո� ��ʼ������ 
		else if(flag &&str[i] == ' ') 
		{ 
			flag = 0; //������ 
			str[p++] = str[i++];
		}
		else 
		
		{ 
			str[p++] = str[i++]; 
			flag = 1;
		}
	}
	if(str[p-1] == ' ') //��β������ո� 
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