//#include <stdio.h>
//#include <stdlib.h>
//#define NULL 0
//#define M 100 
//typedef struct node
//{
//	int data;
//	int cishu;
//	struct node* lchild;
//	struct node* rchild;  //树节点中cishu是为了计数用。在后序遍历中，子树的根节点在第一次遍历的时候不会输出，只有在第二次遍历的时候才输出。
//}bitree;
//
//
//typedef struct stack
//{
//	bitree* elements[M];
//	int top;
//}seqstack;//定义一个储存树类型地址的栈，方便遍历的时候追踪到树的地址。
//
//bitree* root;//定义一个树根
//seqstack s;//定义栈
//
//void setnull()//初始化栈
//{
//	s.top = 0;
//}
//
//void push(bitree* temp)//入栈操作
//{
//	s.elements[s.top++] = temp;
//}
//
//bitree* pop()//取栈顶并出栈顶
//{
//	return s.elements[--s.top];
//}
//
//int empty()//判断空栈
//{
//	return s.top == 0;
//}
//
//bitree* creat()   /*建立二叉树的递归算法*/
//{
//	bitree* t;
//	int x;
//	scanf_s("%d", &x);
//	if (x == 0) t = NULL; /*以x=0表示输入结束*/
//	else {
//		t = (bitree*)malloc(sizeof(bitree));//动态生成结点t,分别给结点t的数据域、左右孩子域  
//		t->data = x;                  //赋值,给左右孩子域赋值时用到了递归的思想。
//		t->lchild = creat();
//		t->rchild = creat();
//	}
//	return t;
//}
//
//
//void inorder(bitree* t)//中序遍历的非递归算法
//{
//	bitree* temp = t;
//	while (temp != NULL || s.top != 0)
//	{
//		while (temp != NULL)//先把左孩子入栈，所有左孩子入栈结束
//		{
//			push(temp);
//			temp = temp->lchild;
//		}
//		if (s.top != 0)//左孩子入栈结束，取栈顶，输出栈顶元素，遍历右孩子
//		{
//			temp = pop();
//			printf("%4d", temp->data);
//			temp = temp->rchild;
//		}
//	}
//	printf("\n");
//}
//
//
//
//
//int main()
//{
//	bitree* root;//创建根
//	setnull();//制空栈
//	printf("请创建一颗二叉树：\n");
//	root = creat();//创建二叉树:尝试输入：1 2 3 0 0 4 0 0 5 6 0 0 7 0 0
//
//	printf("中序遍历:\n");
//	inorder(root);
//
//	return 0;
//}

#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define ERROR 0
#define OVERFLOW -1
#define TRUE 1
#define FALSE 0
#define SIZEINIT 10
#define INCRESIZE 5

typedef int Status;
typedef char TElemType;

typedef struct node {
	TElemType data;
	struct node* lchild, * rchild;
}BiTNode, * BiTree;

//前序创建二叉树
void CreateBiTree(BiTree& T) {
	char ch;
	scanf_s("%c", &ch);
	if (ch == '#') {
		T = NULL;
	}
	else {
		T = (BiTree)malloc(sizeof(struct node));
		T->data = ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
}

//前序遍历
Status PreOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) {
	if (T) {
		if (Visit(T->data)) {
			if (PreOrderTraverse(T->lchild, Visit)) {
				if (PreOrderTraverse(T->rchild, Visit)) return OK;
			}
		}
		return ERROR;
	}
	return OK;
}

//中序遍历
Status InOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) {
	if (T) {
		if (InOrderTraverse(T->lchild, Visit)) {
			if (Visit(T->data)) {
				if (InOrderTraverse(T->rchild, Visit)) return OK;
			}
		}
		return ERROR;
	}
	return OK;
}

//后序遍历
Status PostOrderTraverse(BiTree T, Status(*Visit)(TElemType e)) {
	if (T) {
		if (PostOrderTraverse(T->lchild, Visit)) {
			if (PostOrderTraverse(T->rchild, Visit)) {
				if (Visit(T->data)) return OK;
			}
		}
		return ERROR;
	}
	return OK;
}

//访问函数
Status Visit(TElemType e) {
	printf("%c", e);
	return OK;
}

int main() {
	BiTree T = NULL;
	printf("请前序创建第一棵树(空位置用'#'来代替)\n");
	CreateBiTree(T);
	printf("\n二叉树前序遍历的结果\n");
	PreOrderTraverse(T, Visit);
	printf("\n二叉树中序遍历的结果\n");
	InOrderTraverse(T, Visit);
	printf("\n二叉树后序遍历的结果\n");
	PostOrderTraverse(T, Visit);
	printf("\n");
	return 0;
}
//AB#D##CE###

