#define _CRT_SECURE_NO_WARNINGS 1
//
//�ձ�ĳ�ط�����һ��ıɱ��������ͨ���Ų�ȷ��ɱ�����ֱ�Ϊ4�����ɷ���һ��������Ϊ4�����ɷ��Ĺ��ʡ�
//A˵�������ҡ�
//B˵����C��
//C˵����D��
//D˵��C�ں�˵
//��֪3����˵���滰��1����˵���Ǽٻ���
//�����������Щ��Ϣ��дһ��������ȷ������˭�����֡�
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int murder=0;
	for (murder = 'A'; murder <= 'D'; murder++)
	{
		if ((murder != 'A') + (murder == 'C') + (murder == 'D') + (murder != 'D') == 3)
		{
			printf("�����ǣ�%c\n", murder);
		}
	}
	system("pause");
	return 0;
}