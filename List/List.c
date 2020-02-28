#include "List.h"

void ListInit(List* plt)
{
	assert(plt);

	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->_next = head;
	head->_prev = head;

	plt->_head = head;
}

ListNode* BuyListNode(LTDataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->_next = NULL;
	node->_prev = NULL;
	node->_data = x;

	return node;
}

void ListPushBack(List* plt, LTDataType x)
{
	assert(plt);

	//ListNode* head = plt->_head;
	//ListNode* tail = head->_prev;
	//ListNode* newnode = BuyListNode(x);

	//// head	==== tail  newnode
	//tail->_next = newnode;
	//newnode->_prev = tail;

	//head->_prev = newnode;
	//newnode->_next = head;

	ListInsert(plt->_head, x);
}

void ListPushFront(List* plt, LTDataType x)
{
	//ListNode* head = plt->_head;
	//ListNode* first = head->_next;
	//ListNode* newnode = BuyListNode(x);

	//// head newnode first ====

	//head->_next = newnode;
	//newnode->_prev = head;
	//newnode->_next = first;
	//first->_prev = newnode;
	assert(plt);
	ListInsert(plt->_head->_next, x);
}

void ListPrint(List* plt)
{
	assert(plt);
	ListNode* head = plt->_head;
	ListNode* cur = head->_next;

	printf("head<=>");
	while (cur != head)
	{
		printf("%d<=>", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

void ListPopBack(List* plt)
{
	assert(plt);
	ListNode* head = plt->_head;
	assert(head->_next != head);

	//ListNode* tail = head->_prev;
	//ListNode* prev = tail->_prev;
	//// head ====prev  tail 

	//free(tail);
	//prev->_next = head;
	//head->_prev = prev;

	ListErase(head->_prev);
}

void ListPopFront(List* plt)
{
	assert(plt);
	ListNode* head = plt->_head;
	assert(head->_next != head);

	//ListNode* first = head->_next;
	//ListNode* second = first->_next;

	//// head first second=====
	//free(first);
	//head->_next = second;
	//second->_prev = head;

	ListErase(head->_next);
}

ListNode* ListFind(List* plt, LTDataType x)
{
	assert(plt);
	ListNode* head = plt->_head;
	ListNode* cur = head->_next;
	while (cur != head)
	{
		if (cur->_data == x)
		{
			return cur;
		}

		cur = cur->_next;
	}

	return NULL;
}

// 在pos之前插入x
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* prev = pos->_prev;
	ListNode* newnode = BuyListNode(x);

	// prev newnode pos
	prev->_next = newnode;
	newnode->_prev = prev;
	newnode->_next = pos;
	pos->_prev = newnode;
}

// 删除pos位置的节点
void ListErase(ListNode* pos)
{
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;

	free(pos);
	prev->_next = next;
	next->_prev = prev;
}


void ListDestroy(List* plt)
{
	assert(plt);

	ListNode* head = plt->_head;
	ListNode* cur = head->_next;
	while (cur != head)
	{
		ListNode* next = cur->_next;
		free(cur);

		cur = next;
	}

	plt->_head = NULL;
}