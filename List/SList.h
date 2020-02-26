#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

// 单向 不带头 不循环
typedef double SLTDataType;

typedef struct SListNode
{
	SLTDataType	_data;
	struct SListNode* _next;
}SListNode;

typedef struct SList
{
	SListNode* _head;
}SList;

void SListInit(SList* plt);
void SListPushBack(SList* plt, SLTDataType x);
void SListPopBack(SList* plt);
void SListPushFront(SList* plt, SLTDataType x);
void SListPopFront(SList* plt);

void SListDestory(SList* plt);

void TestSList1();