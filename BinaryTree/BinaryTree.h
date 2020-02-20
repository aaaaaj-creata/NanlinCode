#pragma once
#include <assert.h>
#include <stdio.h>
#include <malloc.h>
#include"Queue.h"

typedef struct BTDataType;
typedef struct BinaryTreeNode
{
	char _data;
	struct BinaryTreeNode*_left;
	struct BinaryTreeNode*_right;
}BTNode;

//通过前序遍历的数组"ABD##E#E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)//创建树
{

}

void BinaryTreeDestory(BTNode* root)//删除这颗树
{
	if (root == NULL)
	{
		return;
	}
	if (root->_left == NULL && root->_right == NULL)
	{
		free(root);
	}
	return BinaryTreeDestory(root->_left) + BinaryTreeDestory(root->_right);
}

int BinaryTreeSize(BTNode* root)//节点个数
{
	if (root == NULL)
	{
		return 0;
	}
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}

int BinaryTreeLeafSize(BTNode* root)//叶子个数
{
	if (root = NULL)
	{
		return;
	}
	if (root->_left = NULL && root->_right = NULL)
	{
		return 1;
	}
	return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root = NULL)
	{
		return 0;
	}
	if (k = 1)
	{
		return 1;
	}
	return BinaryTreeLevelKSize(root->_left, k - 1) + BinaryTreeLevelKSize(root->_right, k - 1);
}

BTNode* BinaryTreeFind(BTNode* root, char x)
{
	if (root = NULL)
	{
		return NULL;
	}
	if (root->_data = x)
	{
		return root;
	}
	BTDataType* lret = BinaryTreeFind(root->_left, x);
	if (lret != NULL)
	{
		return lret;
	}
	BTDataType* rret = BinaryTreeFind(root->_right, x);
	if (rret != NULL)
	{
		return rret;
	}
	return NULL;
}

