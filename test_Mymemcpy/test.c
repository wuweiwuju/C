#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
void* Mymemcpy(void* dest,const void* src,size_t count)
{
	assert(dest && src);
	void* ret = dest;
	while (count--)
	{
		*((char*)dest)++ = *((char*)src)++;
	}
	return ret;
}
int main()
{
	int i = 0;
	int dest[20] = { 0 };
	int src[] = { 1,2,3,4,5,6,7,8,9,0 };
	size_t count = 16;
	Mymemcpy(dest, src, count);
	for (i = 0; i < 10; i++)
	{
		printf("%d ", dest[i]);
	}
	system("pause");
	return 0;
}