#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//struct Point  //����һ���ṹ��
//{
//	int i;
//	int j;
//};
//struct Point Reseach_sou(int arr[][3], int row, int col, int key)
//{
//	int i = 0;
//	int j = col - 1;
//	struct Point ret = { -1,-1 };
//	while ((j >= 0) && (i <= 2))
//	{
//		if (arr[i][j] == key)
//		{
//			ret.i = i;
//			ret.j = j;
//			return ret;
//		}
//		else if (arr[i][j] < key)
//			i++;
//		else
//			j--;
//	}
//	return ret;
//}
//int main()
//{
//	int arr[][3] = { 1, 2 ,3, 2, 3, 4, 3, 4, 5 };
//	int row = 3;
//	int col = 3;
//	struct Point ret = Reseach_sou(arr, row, col, 5);
//	//����һ���ṹ�����
//	if ((ret.i != -1) && (ret.j != -1))
//		printf("�ҵ��ˣ�����Ϊ��%d %d\n", ret.i, ret.j);
//	else
//		printf("�Ҳ���\n");
//	system("pause");
//	return 0;
//}


//pi,pjΪi,j�ĵ�ַ��*������Ϊi,j��ֵ
int Reseach_sou(int arr[][3], int* pi, int* pj, int key)
{
	int i = 0;
	int j = *pj - 1;
	while ((j >= 0) && (i <= *pi))
	{
		if (arr[i][j] == key)
		{
			*pi = i;
			*pj = j;
			return;
		}
		else if (arr[i][j] < key)
			i++;
		else
			j--;
	}
	*pi = -1;
	*pj = -1;
}
int main()
{
	int arr[][3] = { 1, 2 ,3, 2, 3, 4, 3, 4, 5 };
	int i = 3;
	int j = 3;
	int key = 0;
	scanf_s("%d", &key);
	Reseach_sou(arr, &i, &j, key);//ȡx,y�ĵ�ַ
	if ((i != -1) && (j != -1))
		printf("�ҵ��ˣ��±�Ϊ��%d %d\n", i, j);
	else
		printf("�Ҳ���\n");
	system("pause");
	return 0;
}
