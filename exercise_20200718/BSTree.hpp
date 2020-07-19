#pragma once


#include <iostream>
using namespace std;

template<class K, class V>
struct BSTNode
{
	BSTNode<K, V>* _left;
	BSTNode<K, V>* _right;
	K _key;
	V _value;

	BSTNode(const K& key = K(), const V& value = V())
		: _left(nullptr)
		, _right(nullptr)
		, _key(key)
		, _value(value)
	{}
};


/*
1. 坚持上课，做好总结
2. 补课：前面欠的课程，或者学的不扎实及时去补
3. 学过知识点及时做好总结：知识点 + 课堂代码
4. 坚持刷题：每日一题 + 剑指offer
*/
template<class K, class V>
class BSTree
{
	typedef BSTNode<K, V> Node;
public:
	BSTree()
		: _root(nullptr)
	{}

	~BSTree()
	{
		_Destroy(_root);
	}

	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (key == cur->_key)
				return cur;
			else if (key < cur->_key)
				cur = cur->_left;
			else
				cur = cur->_right;
		}

		return nullptr;
	}

	bool Insert(const K& key, const V& value)
	{
		// 空树---直接插入
		if (nullptr == _root)
		{
			_root = new Node(key, value);
			return true;
		}

		// 非空：
		// 1. 找待插入节点在二叉搜索树中的位置， 找的过程中保存cur的双亲
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			parent = cur;
			if (key < cur->_key)
				cur = cur->_left;
			else if (key > cur->_key)
				cur = cur->_right;
			else
				return false;
		}


		// 插入节点
		cur = new Node(key, value);
		if (key < parent->_key)
			parent->_left = cur;
		else
			parent->_right = cur;

		return true;
	}

	bool Erase(const K& key)
	{
		// 树空----直接返回
		/*if (nullptr == _root)
			return false;*/

		// 树非空
		// 先在二叉搜索树中找到值为key的节点
		// 并且要保存cur的双亲
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (key == cur->_key)
				break;
			else if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				parent = cur;
				cur = cur->_right;
			}
		}

		// 二叉搜索树中不存在key的节点
		if (cur == nullptr)
			return false;

		// cur不空，说明在完全二叉树中已经找到key的节点
		// 将该节点从二叉搜索树中删除
		if (nullptr == cur->_right)   // cur一定没有右孩子
		{
			// cur：可能有左孩子 || 没有左孩子---->直接删除
			if (nullptr == parent)
			{
				// cur节点是根节点
				_root = cur->_left;
			}
			else
			{
				// cur的双亲一定存在
				if (cur == parent->_left)
					parent->_left = cur->_left;
				else
					parent->_right = cur->_left;
			}
		}
		else if (nullptr == cur->_left)  // cur一定有右孩子
		{
			// cur只有右孩子--->直接删除
			if (nullptr == parent)
				_root = cur->_right;
			else
			{
				if (cur == parent->_left)
					parent->_left = cur->_right;
				else
					parent->_right = cur->_right;
			}
		}
		else
		{
			// cur节点左右孩子均存在---不能直接删除
			// 1. 在cur的子树中找一个替代节点
			// cur左子树中找：在其左子树中找最大的节点，即左子树最右侧节点
			// cur右子树中找：在其右子树中找最小的节点，即右子树最左侧节点

			parent = cur;
			Node* pDelNode = cur->_right;
			while (pDelNode->_left)
			{
				parent = pDelNode;
				pDelNode = pDelNode->_left;
			}
				
			cur->_key = pDelNode->_key;

			// 删除替代节点
			if (pDelNode == parent->_left)
				parent->_left = pDelNode->_right;
			else
				parent->_right = pDelNode->_right;

			cur = pDelNode;
		}
		
		delete cur;
		return true;
	}

	void InOrder()
	{
		_InOrder(_root);
	}

	Node* LeftMost()
	{
		if (NULL == _root)
			return nullptr;

		Node* cur = _root;
		while (cur->_left)
			cur = cur->_left;

		return cur;
	}

	Node* RightMost()
	{
		if (NULL == _root)
			return nullptr;

		Node* cur = _root;
		while (cur->_right)
			cur = cur->_right;

		return cur;
	}

	void Clear()
	{
		_Destroy(_root);
	}

private:
	void _Destroy(Node*& root)
	{
		if (root)
		{
			_Destroy(root->_left);
			_Destroy(root->_right);
			delete root;
			root = nullptr;
		}
	}

	void _InOrder(Node* root)
	{
		if (root)
		{
			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);
		}
	}

private:
	Node* _root;
};


void TestBSTree()
{
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	BSTree<int, int> bt;
	for (auto e : a)
		bt.Insert(e, e);

	bt.InOrder();
	cout << bt.LeftMost()->_key << endl;
	cout << bt.RightMost()->_key << endl;


	bt.Erase(8);
	bt.InOrder();

	bt.Erase(0);
	bt.InOrder();

	bt.Erase(1);
	bt.InOrder();

	bt.Erase(5);
	bt.InOrder();
}