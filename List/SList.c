#include "SList.h"

void SListInit(SList* plt)
{
	assert(plt);

	plt->_head = NULL;
}

void SListPushBack(SList* plt, SLTDataType x)
{
	assert(plt);

	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;

	// 1.空
	// 2.非空
	if (plt->_head == NULL)
	{
		plt->_head = newnode;
	}
	else
	{
		SListNode* cur = plt->_head;
		// 找尾
		while (cur->_next != NULL)
		{
			cur = cur->_next;
		}

		cur->_next = newnode;
	}
}

void SListPushFront(SList* plt, SLTDataType x)
{
	assert(plt);

	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;

	newnode->_next = plt->_head;
	plt->_head = newnode;
}

void SListPopBack(SList* plt)
{
	assert(plt);
	SListNode* cur = plt->_head;
	if (cur == NULL)
	{
		return;
	}
	else if (cur->_next == NULL)
	{
		free(cur);
		plt->_head = NULL;
	}
	else
	{
		while (cur->_next->_next != NULL)
		{
			cur = cur->_next;
		}

		free(cur->_next);
		cur->_next = NULL;
	}
}

void SListPopFront(SList* plt)
{
	assert(plt);

	if (plt->_head == NULL)
	{
		return;
	}
	else
	{
		SListNode* cur = plt->_head;
		plt->_head = cur->_next;
		free(cur);
		cur = NULL;
	}
}

SListNode* SlistFind(SList* plt, SLTDataType x)
{
	assert(plt);
	SListNode* cur = plt->_head;
	while (cur != NULL)
	{
		if (cur->_data == x)
		{
			return cur;
		}

		cur = cur->_next;
	}

	return NULL;
}

void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->_data = x;
	newnode->_next = NULL;

	newnode->_next = pos->_next;
	pos->_next = newnode;
}

void SListEraseAfter(SListNode* pos)
{
	assert(pos);
	if (pos->_next == NULL)
	{
		return;
	}
	else
	{
		SListNode* next = pos->_next;
		pos->_next = next->_next;
		free(next);
		next = NULL;
	}
}

void SListRemove(SList* plt, SLTDataType x)
{
	assert(plt);

	SListNode* prev = NULL;
	SListNode* cur = plt->_head;
	while (cur != NULL)
	{
		if (cur->_data == x)
		{
			if (prev == NULL)
				plt->_head = cur->_next;
			else
				prev->_next = cur->_next;

			free(cur);
			cur = NULL;
			return;
		}
		else
		{
			prev = cur;
			cur = cur->_next;
		}
	}
}


// 1.先画图分析考虑常规情况
// 2.再画图分析考虑非常规情况(边界条件)

void SListPrint(SList* plt)
{
	assert(plt);

	SListNode* cur = plt->_head;
	while (cur != NULL)
	{
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("NULL\n");
}

void SListDestory(SList* plt)
{
	SListNode* cur = plt->_head;
	while (cur != NULL)
	{
		SListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
}


void TestSList1()
{
	SList lt;
	SListInit(&lt);
	SListPushBack(&lt, 1);
	SListPushBack(&lt, 2);
	SListPushBack(&lt, 3);
	SListPushBack(&lt, 4);
	SListPushFront(&lt, 0);
	SListPrint(&lt);

	SListPopBack(&lt);
	SListPopBack(&lt);
	SListPopBack(&lt);
	SListPrint(&lt);

	SListPopFront(&lt);
	SListPopFront(&lt);
	SListPrint(&lt);
}

void TestSList2()
{
	SList lt;
	SListInit(&lt);
	SListPushBack(&lt, 1);
	SListPushBack(&lt, 2);
	SListPushBack(&lt, 3);
	SListPushBack(&lt, 2);
	SListPushBack(&lt, 4);
	SListPushBack(&lt, 2);
	SListPrint(&lt);

	SListNode* pos = SlistFind(&lt, 3);
	SListInsertAfter(pos, 30);
	SListPrint(&lt);

	SListEraseAfter(pos);
	SListPrint(&lt);

	SListRemove(&lt, 2);
	SListPrint(&lt);

	SListDestory(&lt);
}