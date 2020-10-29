//已知一个顺序表A，其中的元素按值递减有序排列，
//编写一个函数插入一个元素X后保持该顺序表仍按递减排列


#include<stdio.h>
#include<stdlib.h>
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10
#define OK 1
typedef int ElemType;
typedef int Status;
#define OVERFLOW -2
#pragma warning(disable:4996)

typedef struct {
	ElemType* elem;
	int length;
	int listsize;
}SqList;


//初始化顺序表
Status InitList_Sq(SqList& L) {
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}

void ListInsert(SqList& L, int item) {
	int i, j, t;
	for (i = 0; i < L.length; i++) {
		if (L.elem[i] < item) {
			L.length = L.length + 1;

			for (j = L.length - 1; j >= i; j--) {
				L.elem[j + 1] = L.elem[j];
				L.elem[i] = item;
			}
			break;//跳出循环
		}
	}

	//	for (i = 0; i < L.length; i++) {
//
//		if (x >= L.elem[i]) {
//
//			for (j = L.length; j >= i; j--) L.elem[j + 1] = L.elem[j]; // 结点后移
//
//			L.elem[i] = x;
//
//			L.length++;
//
//			return true;
//
//		}
//
//	}
//
//	L.elem[L.length++] = x;
}

//bool ListInsert(SqList& L,ElemType x) {
//	int i, j;
//
//
//	for (i = 0; i < L.length; i++) {
//
//		if (x >= L.elem[i]) {
//
//			for (j = L.length; j >= i; j--) L.elem[j + 1] = L.elem[j]; // 结点后移
//
//			L.elem[i] = x;
//
//			L.length++;
//
//			return true;
//
//		}
//
//	}
//
//	L.elem[L.length++] = x;
//
//	return true;
//
//}



//int main()
//{
//
//	printf("\n");
//	printf("请输入要插入的值：");
//	scanf("%d", &item);
//	ListInsert(L, item);
//	for (i = 0; i < L.length; i++)
//		printf("%5d", L.elem[i]);
//	printf("\n");
//	return 0;
//}

int main() {

	int i, item,n=10;
	SqList L;
	InitList_Sq(L);
	printf("请按递减有序输入顺序表中元素");
	for (i = 0; i < n; i++) {
		scanf("%5d", &L.elem[i]);
	}
	L.length = n;
	printf("原表为：");
	for (i = 0; i < L.length; i++)
	{
		printf("%d ", L.elem[i]);
	}
	printf("\n");
	printf("输入插入数据x:");
	scanf("%d", &item);
	ListInsert(L, item);
	printf("插入后的顺序表为:");
	for (i = 0; i < L.length; i++) {
		printf("%d ", L.elem[i]);
	}

	return 0;
}