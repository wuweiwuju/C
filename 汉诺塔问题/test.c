#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//汉诺塔问题
//A是起始 B是过渡 C是终端

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
	printf("输入汉诺塔的层数:>");
	scanf("%d", &x);
	hanoi(x, 'A', 'B', 'C');
	printf("移动了%d次\n", t);

}