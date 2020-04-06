#include"Link.h"
#include<stdio.h>
#include<assert.h>
#include<malloc.h>


//void Initlist(LinkNode* head)
//{
//	assert(head);
//	head->next = NULL;
//}

LinkNode* BuyLinkNode(DataType data)//创建新节点
{
	LinkNode* newNode = (LinkNode*)malloc(sizeof(LinkNode));
	if (NULL == newNode)
	{
		printf("申请节点失败");
		assert(newNode);
	}
	newNode->data = data;
	newNode->next = NULL;

	return newNode;
}

//head中的内容就是&L
//如果要改变实参L的指向，*head结果就是L本身
//注意空链表和链表不存在的区别，
//空链表：是链表已经存在，没有有效的节点
//链表不存在：都没有头指针
void PushBack(LinkNode** head, DataType data)//尾插
{
	assert(head);//断言链表是否存在
	LinkNode* newNode = BuyLinkNode(data);

	//检测链表是否为空链表(没有任何节点的链表)
	if (*head == NULL)
	{
		*head = newNode;//第一个节点的插入方式
	}
	else//后续节点的插入方式
	{
		//1.找到最后一个节点
		LinkNode* tail = *head;
		while (tail->next)//判断tail后面为不为空，为空则跳出循环
		{
			tail = tail->next;//不为空则继续往后遍历
		}

	   //2.让最后一个节点的next域指向新结点
		tail->next = newNode;
	}

}

void PopBack(LinkNode** head)//尾删
{
	assert(head);
	//找到最后一个节点，free掉，让倒数第二个节点的next域指向NULL
	LinkNode* slow = *head;//找倒数第二个节点
	LinkNode* fast = *head;//找最后一个节点
	fast = fast->next;
	while (fast->next)
	{
		slow = slow->next;
		fast = fast->next;
	}
	slow->next = NULL;
	free(fast);
}

void PushFront(LinkNode** head, DataType data)//头插
{
	assert(head);
	LinkNode* newNode = BuyLinkNode(data);
	LinkNode* front = *head;
	//插入第一个节点
	if (*head == NULL)
	{
		front->next = newNode;
		newNode->next = NULL;
	}
	else
	{
		newNode->next = front->next;
		front->next = newNode;
	}
}
void PopFront(LinkNode** head)//头删
{
	assert(head);
	LinkNode* first = *head;
	LinkNode* second = *head;
	LinkNode* front = *head;
	first = first->next;
	second = second->next->next;
	front->next = second;
	free(first);
}

//////////////////////////////////////////////////
void PrintLinklist(LinkNode* head)//打印链表
{
	assert(head);
	LinkNode* print = head;
	while (print)
	{
		printf("%d->", print->data);
		print = print->next;
	}
	printf("NULL");
	printf("\n");
}

//////////////////////////////////////////////////
void Testlist1()
{
	LinkNode* L = NULL;
	//Initlist(L);
	PushBack(&L, 1);
	PushBack(&L, 2);
	PushBack(&L, 3);
	PushBack(&L, 4);
	PushBack(&L, 5);
	//PopBack(&L);
	//PushFront(&L, 1);
	//PopFront(&L);
	PrintLinklist(L);
}

void Testlist()
{
	Testlist1();
}