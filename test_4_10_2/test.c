#define _CRT_SECURE_NO_WARNINGS 1
//��д����ģ��������������ĳ�����
//����������������룬������ȷ����ʾ����¼�ɹ���, �������
//�����������룬����������Ρ����ξ�������ʾ�˳�����
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int password[20] = { 0 };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("����������\n");
		scanf("%s", password);
		if (0 == strcmp(password, "666666"))
		{
			printf("��½�ɹ�\n");
			break;
		}
		else
		{
			printf("�����������������\n");
		}
	}
	if (i == 3)
	{
		printf("������������������½������\n");
	}
	system("pause");
	return 0;
}