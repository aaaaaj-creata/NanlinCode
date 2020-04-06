#pragma once
//带头单链表
typedef int DataType;

typedef struct LinkNode
{
	int data;
	struct LinkNode* next;
}LinkNode;

//typedef struct LinkNode LinkNode;//如果上面不使用typedef这里就加上

//void InitLinklist(LinkNode* head);//初始化链表
void PushBack(LinkNode** head,DataType data);//尾插
void PopBack(LinkNode** head);//尾删
void PushFront(LinkNode** head, DataType data);//头插
void PopFront(LinkNode** head);//头删

//////////////////////////
void PrintLinklist(LinkNode* head);//打印链表
void Testlist();//测试函数