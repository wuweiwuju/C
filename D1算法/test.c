#define _CRT_SECURE_NO_WARNINGS 1
//��һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
//�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������
//ʱ�临�Ӷ� O��row+col��
#include<stdio.h>
#include<stdlib.h>
#define ROW 4
#define COL 4
int find_target(int arr[ROW][COL], int x) {
	int i = 0;
	int j = COL - 1;
	while (i < ROW && j >= 0) {
		if (arr[i][j] > x) {
			j--;
		}
		else if (arr[i][j] < x) {
			i++;
		}
		else
			return 1;
	}
	return -1;
}
int main() {
	int arr[ROW][COL] = {
		{1,2,8,9},
		{2,4,9,12},
		{4,7,10,13},
		{6,8,11,15} };
	int ret = find_target(arr, 3);
	if (ret == 1) {
		printf("find successfully!\n");
	}
	else {
		printf("find unsuccessfully\n");
	}
	system("pause");
	return 0;
}
