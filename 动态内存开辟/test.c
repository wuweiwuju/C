#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
//int main()
//{
//	////����1
//	//int num = 0;
//	//scanf("%d", &num);
//	//int arr[num] = { 0 };
//	//����2
//	int* ptr = NULL;
//	//ptr = (int*)malloc(10 * sizeof(int));
//	ptr = (int*)malloc(INT_MAX);
//	if (NULL == ptr)//�жϿ����Ƿ�ʧ��
//	{
//		//printf("%s\n", strerror(errno));
//		perror("use malloc");
//	}
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		*(ptr + i) = 0;
//	}
//	free(ptr);//�ͷ�ptr��ָ��Ķ�̬�ڴ�
//	ptr = NULL;//�Ƿ��б�Ҫ��  �����Ҫָ��յģ���Ϊfree�ͷ�֮��������ָ���ǿ�ռ䣬����Ҫ�ÿ�
//
//	return 0;
//}

//int main()
//{
//	int* p = calloc(10, sizeof(int));
//	if (NULL != p)
//	{
//		//ʹ�ÿռ�
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

//int main()
//{
//	int* ptr = malloc(100);
//	if (ptr != NULL)
//	{
//		//ҵ����
//	}
//	else
//	{
//		exit(EXIT_FAILURE);
//	}
//	//��չ����
//	//����1
//	ptr = realloc(ptr, 1000);//����������(�������ʧ�ܻ���Σ�)
//	//�����������кܴ�׶˵ģ���������ʧ�ܣ�֮ǰ������Ҳ����ʧ
//	//����2
//	int* p = NULL; p = realloc(ptr, 1000);
//	if (p != NULL)
//	{
//		ptr = p;
//	}
//	//ҵ����
//	free(ptr);
//	ptr = NULL;
//	return 0;
//}
//void test()
//{
//	int* p = (int*)malloc(INT_MAX / 4);
//	*p = 20;//���p��ֵ��NULL���ͻ�������
//	free(p);
//}
//�Զ�̬���ٿռ��Խ�����
//void test()
//{
//	int i = 0;
//	int* p = (int*)malloc(10 * sizeof(int));
//	if (NULL == p)
//	{
//		exit(EXIT_FAILURE);
//	}
//	for (i = 0; i <= 10; i++)
//	{
//		*(p + i) = i;//��i��10��ʱ��Խ�����
//	}
//	free(p);
//}
//�ԷǶ�̬�����ڴ�ʹ��free�ͷ�
//void test()
//{
//	int a = 10;
//	int* p = &a;
//	free(p);//ok?
//}
//ʹ��free�ͷ�һ�鶯̬�����ڴ��һ����
//void test()
//{
//	int* p = (int*)malloc(100);
//	p++;
//	free(p);//p����ָ��̬�ڴ����ʼλ��
//}
//��ͬһ�鶯̬�ڴ����ͷ�
//void test()
//{
//	int* p = (int*)malloc(100);
//	free(p);
//	free(p);//�ظ��ͷ�
//}
//��̬�����ڴ������ͷţ��ڴ�й©��
//void test()
//{
//	int* p = (int*)malloc(100);
//	if (NULL != p)
//	{
//		*p = 20;
//	}
//}
//int main()
//{
//	test();
//	while (1);
//}