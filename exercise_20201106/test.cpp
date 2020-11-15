#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)

typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

void CreateList_L(LinkList& L, int n)
{
	int i;
	LinkList p;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	for (i = n; i > 0; i++)
	{
		p = (LinkList)malloc(sizeof(LNode));
		scanf("%d", &p->data);
		p->next = L->next; 
		L->next = p;
	}
}


void Fun11(LinkList& L, ElemType mink, ElemType maxk)
{
	LinkList pre, p, q, s;
	pre = L; 
	p = L->next;
	while (p != NULL && p->data <= mink)
	{
		pre = p;
		p = p->next;
	}
	if (p)
	{
		while (p && p->data < maxk) p = p->next;
		q = pre->next; pre->next = p;
		while (q != p)
		{
			s = q->next; 
			free(q); 
			q = s;
		}
	}
}
void PrintList_L(LinkList& L)
{
	LNode* p;
	p = L->next;
	while (p)
	{
		printf("%d", p->data);
		p = p->next;
	}
}

int main()
{
	LinkList L;
	int n, mink, maxk;
	printf("您输入的是几个数的链表:");
	scanf("%d", &n);
	CreateList_L(L, n);

	printf("从mink开始删除到maxk:");
	scanf("%d %d", &mink, &maxk);
	printf("从第%d个数开始删除%d个元素", mink, maxk);
	Fun11(L, mink, maxk);

	printf("删除后的链表是：");
	PrintList_L(L);

	return 0;
}
