#include"SList.h"


void SListInit(SList* plist)
{
	assert(plist);
	plist->_head = NULL;
}
//构造结点
SListNode* BuySListNode(SLTDataType x)
{
	SListNode* pNewNode = (SListNode*)malloc(sizeof(SListNode));
	if (pNewNode == NULL)
	{
		assert(0);
		retrun NULL;
	}
	pNewNode->_data = x;
	pNewNode->_next = NULL;
	return pNewNode;
}
//头插
void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);

}
//头删
void SListPopFront(SList* plist)
{

}
//尾插
void SListPushBack(SList* plist, SLTDataType x)
{

}
//尾删
void SListPopBack(SList* plist)
{

}


















