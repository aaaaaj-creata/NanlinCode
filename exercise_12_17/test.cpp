//////#include<stdio.h>
//////#include<stddef.h>
//////
//////typedef struct BiTNode
//////{
//////	int data;
//////	struct BiTNode* lchild, * rchild;
//////}BiTNode, * BiTree;
//////
//////void preOrder(BiTNode* root)
//////{
//////	if (root == NULL)
//////		return;
//////	printf("%d ", root->data);
//////
//////	preOrder(root->lchild);
//////
//////	preOrder(root->rchild);
//////}
//////
//////
//////void inOrder(BiTNode* root)
//////{
//////	if (root)
//////	{
//////		inOrder(root->lchild);
//////		printf("%d ", root->data);
//////		inOrder(root->rchild);
//////	}
//////}
//////
//////void postOrder(BiTNode* root)
//////{
//////	if (root)
//////	{
//////		postOrder(root->lchild);
//////		postOrder(root->rchild);
//////		printf("%d ", root->data);
//////	}
//////}
//////int main()
//////{
//////
//////	return 0;
//////}
////
/////*
////* 问题描述：树的先序非递归遍历
////* C/C++ 语言
////*
////* @author Erice_s
////* binbin_Erices@163.com
////* @date 2017/10/28
////*
////*/
//////#define _CRT_SECURE_NO_WARNINGS
//////#include <iostream>
//////#include <stack>
//////#define   MAX_STACK  50
//////
//////using namespace std;
////
//////typedef struct BiTNode
//////{
//////	int data;
//////	struct BiTNode* lchild, * rchild;
//////}BiTNode, * BiTree;
//////
////////创建二叉树  从键盘接受数据 先序遍历递归算法
//////BiTree CreateBT()
//////{
//////	char ch;
//////	BiTree T;
//////
//////	scanf("%c", &ch);
//////	if (ch == '#')
//////		return NULL;
//////	else
//////	{
//////		T = (BiTree)malloc(sizeof(BiTNode));
//////		T->data = ch;
//////		T->lchild = CreateBT();
//////		T->rchild = CreateBT();
//////	}
//////
//////	return T;
//////}
////////树的先序非递归遍历算法
//////void preOrder(BiTree T)
//////{
//////	BiTree STACK[MAX_STACK], p = T;
//////	int top = -1;
//////	while (p != NULL || top != -1)
//////	{
//////		while (p != NULL)
//////		{
//////			printf("%c ", p->data);
//////			STACK[++top] = p;
//////			p = p->lchild;
//////		}
//////		p = STACK[top--];
//////		p = p->rchild;
//////	}
//////}
////

////#define _CRT_SECURE_NO_WARNINGS
////#include <iostream>
////#include <stack>
////#define   MAX_STACK  50
////
////using namespace std;
////
////typedef struct BiTNode
////{
////	int data;
////	struct BiTNode* lchild, * rchild;
////}BiTNode, * BiTree;
////
////BiTree CreateBT()
////{
////	char ch;
////	BiTree T;
////
////	scanf("%c", &ch);
////	if (ch == '#')
////		return NULL;
////	else
////	{
////		T = (BiTree)malloc(sizeof(BiTNode));
////		T->data = ch;
////		T->lchild = CreateBT();
////		T->rchild = CreateBT();
////	}
////
////	return T;
////}
////
////void preOrder(BiTNode* root)
////{
////	if (root == NULL)
////		return;
////	printf("%d ", root->data);
////
////	preOrder(root->lchild);
////
////	preOrder(root->rchild);
////}
////
////int main(void)
////{
////	BiTree root;
////	cout << "请初始化树：";
////	root = CreateBT();
////
////	cout << "树的先序非递归遍历：";
////	preOrder(root);
////	return 0;
////}
////
//
//#include<iostream>
//#include<stack>
//#include<queue>
//using namespace std;
//
//typedef struct node
//{
//	int data;
//	struct node* lchild;
//	struct node* rchild;
//}Btree;
////非递归算法
//void PreOrder1(Btree* b)
//{
//	stack<node*>s;
//	Btree* p;
//	//if (b) s.push(b);
//	if (b)
//	{
//		while (b || !s.empty())
//		{
//			while (b)
//			{
//				cout << b->data << " ";
//				s.push(b);
//				b = b->lchild;
//			}
//			if (!s.empty())
//			{
//				p = s.top();
//				s.pop();
//				if (p->rchild) s.push(p->rchild);
//			}
//		}
//	}
//}
//void PreOrder2(Btree* b)
//{
//	stack<Btree*>s;
//	Btree* p;
//	if (b)
//	{
//		s.push(b);
//		while (!s.empty())
//		{
//			p = s.top();
//			s.pop();
//			cout << p->data << " ";
//			if (p->rchild) s.push(p->rchild);
//			if (p->lchild) s.push(p->lchild);
//		}
//	}
//}
////中序遍历的非递归遍历
//void InOrder(Btree* b)
//{
//	Btree* p;
//	stack<Btree*>s;
//	if (b)
//	{
//		while (b || !s.empty())
//		{
//			while (b)
//			{
//				s.push(b);
//				b = b->lchild;
//			}
//			if (!s.empty())
//			{
//				p = s.top();
//				s.pop();
//				cout << p->data << " ";
//				if (p->rchild) s.push(p->rchild);
//			}
//		}
//	}
//}
////后序遍历的非递归算法
//void PostOrder(Btree* b)
//{
//	Btree* p, * r;
//	stack<Btree*>s;
//	p = b;
//	bool flag;
//	do
//	{
//		while (p)
//		{
//			s.push(p);
//			p = p->lchild;
//		}
//		r = NULL;
//		flag = true;//flag == true 表示正在处理栈顶结点
//		while (!s.empty() && flag)
//		{
//			p = s.top();
//			if (p->rchild == r)//如果右子树为空或者已经被访问过
//			{
//				cout << p->data << " ";
//				s.pop();
//				r = p;
//			}
//			else
//			{
//				p = p->rchild;
//				flag = false;
//			}
//		}
//
//	} while (!s.empty());
//}
////层次遍历
//void LevelOrder(Btree* b)
//{
//	queue<Btree*>q;
//	Btree* p;
//	if (b)
//	{
//		q.push(b);
//		while (!q.empty())
//		{
//			p = q.back();
//			q.pop();
//			cout << p->data << " ";
//			if (p->lchild) q.push(p->lchild);
//			if (p->rchild) q.push(p->rchild);
//		}
//	}
//}
//void CreateTree(Btree*& b)
//{
//	b = new Btree;
//	b->lchild = b->rchild = NULL;
//	int x;
//	cin >> x;
//	if (x != 0)
//	{
//		b->data = x;
//		CreateTree(b->lchild);
//		CreateTree(b->rchild);
//	}
//	else b = NULL;
//}
//int main()
//{
//	Btree* b;
//	CreateTree(b);
//	cout << "先序遍历算法1如下：" << endl;
//	PreOrder1(b);
//	cout << "先序遍历算法2如下：" << endl;
//	PreOrder2(b);
//	cout << "中序遍历算法如下：" << endl;
//	InOrder(b);
//	cout << "后序遍历的算法如下:" << endl;
//	PostOrder(b);
//	cout << "层次遍历的算法如下：" << endl;
//	LevelOrder(b);
//	return 0;
//}


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include<queue>
#include<stdlib.h>
#include<stddef.h>

using namespace std;

typedef struct BiTNode
{
	int data;
	struct BiTNode* lchild, * rchild;
}BiTNode, * BiTree;

//创建二叉树  从键盘接受数据 先序遍历递归算法
BiTree CreateBT()
{
	char ch;
	BiTree T;

	scanf("%c", &ch);
	if (ch == '#')
		return NULL;
	else
	{
		T = new BiTree;
		T->data = ch;
		T->lchild = CreateBT();
		T->rchild = CreateBT();
	}

	return T;
}

//销毁一棵树
void  BiTree_Free(BiTNode* T)
{
	if (T != NULL)
	{
		if (T->rchild != NULL) BiTree_Free(T->rchild);
		if (T->lchild != NULL) BiTree_Free(T->lchild);
		if (T != NULL)
		{
			delete T;
			T = NULL;
		}
	}
}


//一直往左走找到中序遍历的起点
BiTNode* goL(BiTNode* T, stack<BiTNode*>& s)
{
	if (T == NULL)
		return NULL;
	while (T->lchild)
	{
		s.push(T);
		T = T->lchild;
	}
	return T;
}

void inOrder2(BiTNode* T) //非递归描述
{
	BiTNode* t = NULL;
	stack<BiTNode*>s;

	t = goL(T, s);

	while (t)
	{
		printf("%c ", t->data);
		//如果t有右子树 重复步骤
		if (t->rchild)
		{
			t = goL(t->rchild, s);  //右子树中中序遍历的起点
		}
		else if (!s.empty())  //如果没有右子树   根据栈顶指示
		{
			t = s.top();
			s.pop();
		}
		else //如果t 没有右子树   根据栈顶为空
		{
			t = NULL; //结束循环
		}
	}
}


//中序遍历递归
void inOrder(BiTNode* root)
{
	if (root)
	{
		inOrder(root->lchild);
		printf("%c ", root->data);
		inOrder(root->rchild);
	}
}

int main(void)
{
	BiTree root;
	root = CreateBT();

	inOrder(root);
	cout << endl;

	inOrder2(root);
	BiTree_Free(root);

	return 0;
}