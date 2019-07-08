#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<memory.h>
#include<malloc.h>
//顺序表的静态存储
//#define N 100
typedef int SLDataType;
//
//typedef struct Seqlist
//{
//	SLDataType array[N];//定长数组
//	size_t size;  //有效数据的个数
//}Seqlist;
//顺序表的动态存储


typedef struct Seqlist
{
	SLDataType* array;//指向动态开辟的数组
	size_t size;//有效数据的个数
	size_t capicity;//容量空间的大小
}Seqlist;

void SeqlistInit(Seqlist* psl);
void SeqlistDestory(Seqlist* psl);
void CheckCapicity(Seqlist* psl);
void SeqlistPushBack(Seqlist* psl, SLDataType x);
void SeqlistPopBack(Seqlist* psl);
void SeqlistPushFront(Seqlist* psl, SLDataType x);
void SeqlistPopFront(Seqlist* psl);
int SeqlistFind(Seqlist* psl, SLDataType x);
void SeqlistInsert(Seqlist* psl, size_t pos, SLDataType x);
void SeqlistErase(Seqlist* psl, size_t pos);
void SeqlistRemove(Seqlist* psl, SLDataType x);
void SeqlistModify(Seqlist* psl, size_t pos, SLDataType x);
void Seqlistprint(Seqlist* psl);
void SeqlistBubbleSort(Seqlist* psl);
int SeqlistBinaryFind(Seqlist* psl, SLDataType x);
void SeqlistRemoveAll(Seqlist* psl, SLDataType x);