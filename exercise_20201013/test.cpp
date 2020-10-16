//#include <iostream>
//
//using namespace std;
//typedef struct node
//{
//	struct node* lchild;
//	struct node* rchild;
//	char data;
//}BiTreeNode, * BiTree;
//
////构造二叉树表表示二叉树T
//void CreateBiTree(BiTree& T)
//{
//	char ch;
//	cin >> ch;
//
//	if (ch == '@')
//		T = NULL;
//	else
//	{
//		T = new BiTreeNode;
//		if (!T) exit(0);
//		T->data = ch;
//		CreateBiTree(T->lchild);
//		CreateBiTree(T->rchild);
//	}
//}
//
//void PreOrderTraverse(BiTree& T)
//{
//	if (T)//当结点不为空的时候执行
//	{
//		cout << T->data;
//		PreOrderTraverse(T->lchild);//  
//		PreOrderTraverse(T->rchild);
//	}
//	else cout << "@";
//}
//
//void InOrderTraverse(BiTree T)
//{
//	if (T)
//	{
//		InOrderTraverse(T->lchild);
//		cout << T->data;
//		InOrderTraverse(T->rchild);
//	}
//	else cout << "@";
//
//}
//
//void PostOrderTraverse(BiTree T)
//{
//	
//	if (T)
//	{
//		PostOrderTraverse(T->lchild); 
//		PostOrderTraverse(T->rchild); 
//		cout << T->data;
//	}
//	else cout << "@";
//
//}
//
//int main()
//{
//	BiTree T;
//	cout << "输入二叉树的前序遍历序列:" << endl;
//
//	CreateBiTree(T);
//
//	cout << "输出中序遍历结果：" << endl;
//
//	InOrderTraverse(T);
//	cout << endl;
//	cout << "输出后序遍历结果：" << endl;
//
//	PostOrderTraverse(T);
//	cout << endl;
//
//	return 0;
//}

#include <iostream>
#include<string>
using namespace std;

#define MAX_SIZE 10

int BF(const char* str, const char* sub, int &num)
{
	int i = 0;
	int j = 0;
	int lens = strlen(str);
	int lensub = strlen(sub);
	while (j < lensub && i < lens)
	{
		if (str[i] == sub[i])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 1;
			j = 0;
		}

		num++;
	}
	if (j >= lensub)
	{
		return i - j;
	}
	else return -1;
}


int Next(char* p, int* next,int &sum)
 {
     char* q = p;
     int i, j, k, l, s = 0, m = 1;
     while (*q != '\0')
     {
         s++;
         q++;
     }
     s--;
     q = p;
     next[0] = s;
     next[1] = 0;
     next[2] = 1;
     for (i = 3; i <= s; i++)
     {
         for (l = 1; l <= i - 2; l++)
         {
             for (j = 1, k = j + l; j <= i - 1 - l; j++, k++)
             {
                 if (q[j] != q[k]) { m = 0; break; }
             }
             if (m) break; 
             m = 1;

			 sum++;
         }
         next[i] = i - l;
     }
     return 0;
 }

 int KMP(char* S, char* T,int &sum)
 {
     int next[MAX_SIZE], i = 1, j = 1, s = 0, t = 0, pos = 1;
     char* p = S, * q = T;
     while (*p != '\0')
     {
         s++;
         p++;
     }
     s--;
     while (*q != '\0')
     {
         t++;
         q++;
     }
     t--;
     Next(T, next,sum);
     while (i <= s && j <= t)
     {
         if (j == 0) { i++; j++; }
		if (i > s) { break; }
         if (S[i] == T[j]) { i++; j++; }
         else j = next[j];

		 sum++;
     }
     if (j > t)
     {
         pos = i - t;
         
         return 0;
     }
     if (i > s && j <= t)
     {

         return 0;
     }
 }

int main()
{
	int sum = 0, num = 0;
	char Str[16] = "aaaabaaaabaaaab";
	char pattern[6] = "aaaaa";

	KMP(Str, pattern, sum);
	cout << "最坏情况下KMP需要比较次数:" << endl;
	cout << sum << endl;

	BF(Str, pattern,num);
	cout << "最坏情况下BF需要比较次数:" << endl;
	cout << num << endl;

	if (sum > num)
	{
		cout << "最坏情况下，KMP算法比较次数更多，BF更优" << endl;
	}
	else
		cout << "最坏情况下，KMP算法比较次数更少，KMP更优" << endl;

	return 0;
}