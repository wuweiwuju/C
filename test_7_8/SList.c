#include"SList.h"


void SListInit(SList* plist)
{
	assert(plist);
	plist->_head = NULL;
}
//������
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
//ͷ��
void SListPushFront(SList* plist, SLTDataType x)
{
	assert(plist);

}
//ͷɾ
void SListPopFront(SList* plist)
{

}
//β��
void SListPushBack(SList* plist, SLTDataType x)
{

}
//βɾ
void SListPopBack(SList* plist)
{

}


















