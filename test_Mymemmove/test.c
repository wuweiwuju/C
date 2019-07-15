#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>;
#include<stdlib.h>
#include<assert.h>
void* Mymemmove(void* dest,const void* src,size_t count)
{
	assert(dest && src);
	void* ret = dest;
	while (count--)
	{
		if (dest < src)
		{
			*((char*)dest)++ = *((char*)src)++;
		}
		else
		{
			*((char*)dest + count)  = *((char*)src + count);
		}
	}
	return ret;
}
int main()
{
	int arr1[20] = { 1,2,3,4,5,6,7,8,9,10 };
	size_t count = 16;
	Mymemmove(arr1, arr1+2, count);
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr1[i]);
	}
	system("pause");
	return 0;
}