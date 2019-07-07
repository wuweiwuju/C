#include"Seqlist.h"
//顺序表的初始化
void SeqlistInit(Seqlist* psl)
{
	assert(psl);
	psl->array = (SLDataType*)malloc(sizeof(SLDataType)*10);
	if (NULL == psl->array)
	{
		assert(0);
		return;
	}
	psl->capicity = 10;
	psl->size = 0;

}
//释放顺序表
void SeqlistDestory(Seqlist* psl)
{
	assert(psl);
	if (psl->array)
	{
		free(psl->array);
			psl->array = NULL;
			psl->capicity = 0;
			psl->size = 0;
	}
}
//检查顺序表，看是否需要扩容
void CheckCapicity(Seqlist* psl)
{
	assert(psl);
	if (psl->capicity == psl->size)
	{
		int newCapicity = psl->capicity * 2;
		SLDataType* pTmp = (SLDataType*)malloc(sizeof(SLDataType)*newCapicity);
		if (NULL == pTmp)
		{
			assert(0);
			return;
		}
		memcpy(pTmp, psl->array, psl->size * sizeof(SLDataType));
		free(psl->array);
		psl->array = pTmp;
		psl->capicity = newCapicity;
		
	}
}
//尾插
void SeqlistPushBack(Seqlist* psl, SLDataType x)
{
	assert(psl);
	CheckCapicity(psl);
	psl->array[psl->size] = x;
	psl->size++;
}
//尾删
void SeqlistPopBack(Seqlist* psl)
{
	assert(psl);
	psl->size--;
}
//头插
void SeqlistPushFront(Seqlist* psl, SLDataType x)
{
	int i = 0;
	assert(psl);
	CheckCapicity(psl);
	for (i = 0; i < psl->size; i++)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[0] = x;
	psl->size++;

}
//头删
void SeqlistPopFront(Seqlist* psl)
{
	int i = 0;
	assert(psl);
	for (i = 0; i < psl->size; i++)
	{
		psl->array[i] = psl->array[i+1];
	}
	psl->size--;
}
//查找某个元素
int SeqlistFind(Seqlist* psl, SLDataType x)
{
	int i = 0;
	assert(psl);
	for ( i = 0; i < psl->size; i++)
	{
		if (x == psl->array[i])
		{
			return i;
		}
	}
	return -1;
}
//在某个位置插入一个元素
void SeqlistInsert(Seqlist* psl, size_t pos, SLDataType x)
{
	int i = 0;
	assert(psl);
	CheckCapicity(psl);
	for (i = pos; i < psl->size; i++)
	{
		psl->array[i + 1] = psl->array[i];
	}
	psl->array[pos] = x;
	psl->size++;
}
//在某个位置删除一个元素
void SeqlistErase(Seqlist* psl, size_t pos)
{
	int i = 0;
	assert(psl);
	for (i = pos; i < psl->size; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}
//移除一个数
void SeqlistRemove(Seqlist* psl, SLDataType x)
{
	assert(psl);
	SeqlistErase(psl, SeqlistFind(psl, x));
}
//在某个位置更改一个数
void SeqlistModify(Seqlist* psl, size_t pos, SLDataType x)
{
	assert(psl);
	psl->array[pos] = x;
}
//展示顺序表
void Seqlistprint(Seqlist* psl)
{
	int i = 0;
	assert(psl);
	if (psl->size == 0)
	{
		printf("NULL\n");
		return;
	}
	for (i = 0; i < psl->size; i++)
	{
		printf("%d ", psl->array[i]);
	}
	printf("\n");
}