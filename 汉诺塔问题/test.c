#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//��ŵ������
//A����ʼ B�ǹ��� C���ն�

int t = 0;
void hanoi(int n,char a,char b,char c)
{
	if (n == 1)
	{
		printf("%c->%c\n", a, c);
		t++;
	}
	else
	{
		hanoi(n - 1, a, c, b);
		printf("%c->%c\n", a, c);
		t++;
		hanoi(n - 1, b, a, c);
	}
}
int main()
{
	int x = 0;
	printf("���뺺ŵ���Ĳ���:>");
	scanf("%d", &x);
	hanoi(x, 'A', 'B', 'C');
	printf("�ƶ���%d��\n", t);

}