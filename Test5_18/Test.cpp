#include<iostream>
#include<vld.h>
using namespace std;

void main()
{
	//char str[] = "Hello";
	//char *str = "Hello";
	char *str = (char*)malloc(sizeof(char)*(strlen("Hello")+1));
	strcpy(str, "Hello");
	cout<<"str = "<<str<<endl;
	str[0] = 'h';
	cout<<"str = "<<str<<endl;
	//free(str);
}

/*
int main()
{
	char str1[] = "hello bit.";
	char str2[] = "hello bit.";

	char *str3 = "hello bit.";
	char *str4 = "hello bit.";

	if(str1 == str2)
		printf("str1 and str2 are same\n");
	else
		printf("str1 and str2 are not same\n");
	
	if(str3 == str4)
		printf("str3 and str4 are same\n");
	else
		printf("str3 and str4 are not same\n");
	
	return 0;
}

/*
int main(int argc, char *argv[])
{
	return 0;
}

/*
//�༭��
//������
//������
//�����в���
int main(int argc, char *argv[])
{
	//argument count
	//argument value

	printf("Hello Bit.\n");
	system("pause");
	return 0;
}


/*
//����ָ��
int (*func)(int *, int (*)(int *));
//
int (*func[5])(int *);
//
int (*(*func)[5])(int *);
//
int (*(*func)(int *)) [5];
//
int*(*func(int*))[5]
//

(*(void(*)())0)()  // ????????????

/*
�ñ���a��������Ķ���
a) һ��������  
int a;
b) һ��ָ����������ָ��
int *a;
c) һ��ָ��ָ���ָ�룬��ָ���ָ����ָ��һ��������
int **a;
d) һ����10��������������
int a[10];
e) һ����10��ָ������飬��ָ����ָ��һ���������ġ�
int *a[10]
f) һ��ָ����10�������������ָ��
int(*a)[10]
g) һ��ָ������ָ�룬�ú�����һ�����Ͳ���������һ��������
int(*a)(int)
h) һ����10��ָ������飬��ָ��ָ��һ��������
    �ú�����һ�����Ͳ���������һ��������
int(*a[10])(int)


/*
int fun(int a, int b)
{
	return a + b;
}

//double (*pfun)(char, float, int);

double fun2(char a, float b, int c)
{
	return 0.0;
}

int* fun1(int a, int b) //ָ�뺯��
{
	int v = a + b;
	return &v;
}

void main()
{
	cout<<fun(10,20)<<endl;

	int (*pfun)(int,int); //����ָ��
	pfun = &fun;
	cout<<(*pfun)(100,200)<<endl;

	pfun = fun;
	cout<<pfun(1,2)<<endl;

}

/*
#define AR_SIZE 10

void main()
{
	int ar[AR_SIZE] = {0};

	int (*q)[10] = &ar;
	int *p = &ar[0];
}

/*
void main()
{
	int ar[AR_SIZE] = {0};

	cout<<sizeof(ar)<<endl;    //10*4
	cout<<sizeof(&ar)<<endl;   //4
	cout<<sizeof(&ar[0])<<endl;//4

	cout<<&ar<<endl;
	cout<<&ar[0]<<endl;

	cout<<&ar<<" : "<<&ar+1<<endl;
	cout<<&ar[0]<<" : "<<&ar[0]+1<<endl;

}

/*
void main()
{
	int ar[AR_SIZE] = {0};

	cout<<sizeof(ar)<<endl;    //10*4
	cout<<sizeof(&ar)<<endl;   //4
	cout<<sizeof(&ar[0])<<endl;//4

	cout<<ar<<endl;
	cout<<&ar<<endl;
	cout<<&ar[0]<<endl;

	cout<<typeid(ar).name()<<endl;
	cout<<typeid(&ar).name()<<endl;
	cout<<typeid(&ar[0]).name()<<endl;
}

/*
void main()
{
	int ar[AR_SIZE];
	for(int i=0; i<AR_SIZE; ++i)
	{
		ar[i] = i + 1;
	}

	for(i=0; i<AR_SIZE; ++i)
	{
		cout<<ar[i]<<" ";
	}
	cout<<endl;

	for(i=0; i<AR_SIZE; ++i)
	{
		cout<<*(ar+i)<<" ";
	}
	cout<<endl;

	int *p = ar;
	for(i=0; i<AR_SIZE; ++i)
	{
		cout<<p[i]<<" ";
	}
	cout<<endl;

	for(i=0; i<AR_SIZE; ++i)
	{
		cout<<*(p+i)<<" ";
	}
	cout<<endl;

}

/*
//15
void Swap(int &a ,int &b) //����
{
	a = a + b;
	b = a - b;
	a = a - b;
}

void main()
{
	int a = 4719741401410;
	int b = 20;
	printf("before swap a = %d, b = %d\n", a, b);
	Swap(a, b);
	printf("before swap a = %d, b = %d\n", a, b);
}

/*
void Swap(int &a ,int &b) //����
{
	int tmp = a;
	a = b;
	b = tmp;
}

void main()
{
	int a = 10;
	int b = 20;
	printf("before swap a = %d, b = %d\n", a, b);
	Swap(a, b);
	printf("before swap a = %d, b = %d\n", a, b);
}

/*
void Swap(int *a ,int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void main()
{
	int a = 10;
	int b = 20;
	printf("before swap a = %d, b = %d\n", a, b);
	Swap(&a, &b);
	printf("before swap a = %d, b = %d\n", a, b);
}

/*
void Swap(int *a ,int *b)
{
	int *tmp = a;
	a = b;
	b = tmp;
}

void main()
{
	int a = 10;
	int b = 20;
	printf("before swap a = %d, b = %d\n", a, b);
	Swap(&a, &b);
	printf("before swap a = %d, b = %d\n", a, b);
}

/*
void Swap(int a ,int b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

void main()
{
	int a = 10;
	int b = 20;
	printf("before swap a = %d, b = %d\n", a, b);
	Swap(a, b);
	printf("before swap a = %d, b = %d\n", a, b);
}

/*
void main()
{
	int a = 10;
	int b = 20;
	const int *const p = &a;

	//*p = 100;
	//p = &b;
}


void main()
{
	int a = 10;
	int b = 20;

	int *p = NULL;
	int **s = NULL;

	p = &a;
	s = &p;

	*p = 100;
	*s = &b;
}


/*
void main()
{
	char ch = 'A';
	int i = 10;
	double d = 12.34;
	//xxxx = xxxxx

	int *p = &i; //ָ����� = ��ַ ==> ָ��==��ַ
}


/*
unsigned char i = 0;

void main()
{
	float f = 10.5;  // ==> �ڴ�
	//1  float ==> ������
	//2  ������ ==> (-1)^s * m * 2^e 
	//3  �������и�� s  m  e
	//4  1<0��1��> 8<e+127> 23<��ȥ���1������23λ>

	float f1 = 12.625;
	//1 �ڴ����� ==> �����Ʊ�ʾ
	//2 ���ֶ�����<1,8,23>
	//3 (-1)^s * m * 2^e ��ȡs m e
}

/*
int main()
{
	for(i = 0; i<=255; i++)
	{
		printf("hello world\n");
	}
	return 0;
}

/*
int main()
{
	char a[1000];

	int i;
	for(i=0; i<1000; i++)
	{
		a[i] = -1-i;  //a[0] = -1-0
	}

	printf("%d\n",strlen(a));//
	return 0;
}

/*
//void fun(char br[])
void fun(char *br)
{
	cout<<strlen(br)<<endl; //9
	cout<<sizeof(br)<<endl; //4
}

void main()
{
	char ar[10] = "abcdefghi";
	fun(ar);
}

/*
void main()
{
	int *ar[10][10];
	cout<<sizeof(ar)<<endl;
}


void main()
{
	char *ar = "Hello";
	cout<<strlen(ar)<<endl; //5
	cout<<sizeof(ar)<<endl; //4
}


/*
char ar[10];
void main()
{
	cout<<strlen(ar)<<endl; //
	cout<<sizeof(ar)<<endl; //10
}

void main()
{
	char ar[10] = {'A'};
	cout<<strlen(ar)<<endl; //
	cout<<sizeof(ar)<<endl; //10
}

/*
void main()
{
	char ar[10];
	cout<<strlen(ar)<<endl; //
	cout<<sizeof(ar)<<endl; //10
}

/*
void main()
{
	char ar[] = {'H','\0','l','l','o'};
	cout<<strlen(ar)<<endl; //
	cout<<sizeof(ar)<<endl; //5
}
/*
void main()
{
	char ar[] = {'H','e','l','l','o'};
	cout<<strlen(ar)<<endl; // //???
	cout<<sizeof(ar)<<endl; // 10
}

/*
void main()
{
	char ar[10] = {'H','e','l','l','o'};
	cout<<strlen(ar)<<endl; // 5
	cout<<sizeof(ar)<<endl; // 10
}

/*
void main()
{
	char ar[10] = "Hello";
	cout<<strlen(ar)<<endl; // 5
	cout<<sizeof(ar)<<endl; // 
}


/*
void main()
{
	char ar[] = "Hello";
	cout<<strlen(ar)<<endl; // 5
	cout<<sizeof(ar)<<endl; // 6
}

/*
int main()
{
	char a[1000];
	int i;
	for(i=0; i<1000; i++)
	{
		a[i] = -1-i;
	}
	printf("%d",strlen(a)); //
	return 0;
}

/*
void main()
{
	for(int i=0; i<100; ++i)
	{
		printf("i = %d\n", i);
	}
}

/*
int main()
{
	char a[1000];
	int i;
	for(i=0; i<1000; i++)
	{
		a[i] = -1-i;
	}
	printf("%d",strlen(a));
	return 0;
}

/*
unsigned int i;
void main()
{
	for(i=9; i>=0; i--)
		printf("%u\n", i);
}

/*
int main()
{
	int i= -20;
	unsigned int j = 10;

	printf("%d\n", i+j);
}

/*
int main()
{
	char a = -128;
	printf("%u\n",a);
	return 0;
}

/*
               //419971
int Small_Int(long value)  //-128 ~ 127
{
	while(value > 127)
		value -= 256;
	while(value < -128)
		value += 256;
	return value;
}

void main()
{
	char ch = 200;
	long value;
	while(1)
	{
		cout<<"input value:>";
		cin>>value;
		
		int res = Small_Int(value);
		cout<<"result = "<<res<<endl;
	}

}
/*
void main()
{
	char ch = -128 - 1;

	cout<<"ch = "<<(int)ch<<endl;
}

/*
//char 
int main()
{
	char a = -128;      //
	printf("%u\n",a);
	return 0;
}

/*
int main()
{
	char a = -1;          //1111 1111
	signed char b = -1;   //
	unsigned char c = -1; //1111 1111

	printf("a=%d,b=%d,c=%d\n",a,b,c);

	return 0;
}
*/