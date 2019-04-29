#define _CRT_SECURE_NO_WARNINGS 1
//编写代码模拟三次密码输入的场景。
//最多能输入三次密码，密码正确，提示“登录成功”, 密码错误，
//可以重新输入，最多输入三次。三次均错，则提示退出程序。
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int password[20] = { 0 };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("请输入密码\n");
		scanf("%s", password);
		if (0 == strcmp(password, "666666"))
		{
			printf("登陆成功\n");
			break;
		}
		else
		{
			printf("密码错误，请重新输入\n");
		}
	}
	if (i == 3)
	{
		printf("三次输入均错误，请重新进入程序\n");
	}
	system("pause");
	return 0;
}