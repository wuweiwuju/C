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
	for (i = psl->size-1; i >= 0; i--)
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
//冒泡排序
void SeqlistBubbleSort(Seqlist* psl)
{
	int i = 0;
	int j = 0;
	int count = 0;
	assert(psl);
	for (i = 0; i < psl->size-1; i++)
	{
		count = 0;
		for (j = 0; j < psl->size - i - 1; j++)
		{
			if (psl->array[j] > psl->array[j + 1])
			{
				int tmp = psl->array[j];
				psl->array[j] = psl->array[j + 1];
				psl->array[j + 1] = tmp;
				count = 1;
			}
			if (count == 0)
			{
				break;
			}
		}
	}
}
//二分查找(时间复杂度：O(N) 空间复杂度 O(1))(只能是非递归)
int SeqlistBinaryFind(Seqlist* psl,SLDataType x)
{
	int mid = 0;
	int left = 0;
	int right = psl->size-1;
	while (left<=right)
	{
		mid = left + (right - left) / 2;
		if (psl->array[mid] < x)
		{
			left = mid + 1;
		}
		else if (psl->array[mid] > x)
		{
			right = mid - 1;
		}
		else if(psl->array[mid] == x)
		{
			return mid;
		}
	}
	return -1;
}
//移除相同的一个数字
void SeqlistRemoveAll(Seqlist* psl, SLDataType x)
{
	assert(psl);
	int count = 0;
	for (int i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			count++;
		}
		else
		{
			psl->array[i - count] = psl->array[i];
		}
	}
	psl->size -= count;
}