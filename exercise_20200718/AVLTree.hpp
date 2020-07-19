#pragma once

#include <iostream>
using namespace std;


// 孩子双亲表示
template<class T>
struct AVLTreeNode
{
	AVLTreeNode<T>* _left;
	AVLTreeNode<T>* _right;
	AVLTreeNode<T>* _parent;
	T _data;
	int _bf;   // 该节点的平衡因子

	AVLTreeNode(const T& data = T())
		: _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _bf(0)
	{}
};


// 假设：AVL树中值域是唯一的
template<class T>
class AVLTree
{
	typedef AVLTreeNode<T> Node;
public:
	AVLTree()
		: _root(nullptr)
	{}

	/*
	AVL树： 二叉搜索树 + 每个节点的平衡因子的绝对值不会超过1
	*/
	bool Insert(const T& data)
	{
		// 构建一棵二叉搜索树
		if (nullptr == _root)
		{
			_root = new Node(data);
			return true;
		}

		// 按照二叉搜索树的性质将data的节点插入
		// 按照二叉搜索树的性质找待插入节点在树中的位置
		Node* cur = _root;
		Node* pParent = nullptr;
		while (cur)
		{
			pParent = cur;
			if (data < cur->_data)
				cur = cur->_left;
			else if (data > cur->_data)
				cur = cur->_right;
			else
				return false;
		}

		// 插入新节点
		cur = new Node(data);
		if (data < pParent->_data)
			pParent->_left = cur;
		else
			pParent->_right = cur;

		cur->_parent = pParent;

		// 二叉搜新节点插入之后就可以结束了
		// AVL：因为新节点插入后可能会破坏树的平衡性
		// 更新parent节点的平衡因子
		while (pParent)
		{
			if (cur == pParent->_left)
				pParent->_bf--;
			else
				pParent->_bf++;

			// 检测parent的平衡因子是否违反AVL树的性质
			if (0 == pParent->_bf)
				return true;
			else if (1 == pParent->_bf || -1 == pParent->_bf)
			{
				// 说明：在插入之前parent一定是叶子节点
				// parent的平衡因子更新完成之后如果是1说明：parent右子树的高度增加了一层
				// parent的平衡因子更新完成之后如果是-1说明：parent左子树的高度增加了一层
				// 以parent为根的二叉树整个的到底就增加了1层，需要继续往上更新
				cur = pParent;
				pParent = cur->_parent;
			}
			else
			{
				// parent的平衡因子：2或者-2---->parent节点违反了AVL树的性质
				// 旋转处理
				// parent的平衡因子如果是2--->最后需要进行的肯定是左单旋
				// 如果parent与cur是同号--->左单旋
				// 如果parent与cur是异号--->右左双旋
				if (2 == pParent->_bf)
				{
					// 双亲的右子树比较高--->最后一次肯定是左单旋
					if (1 == cur->_bf)
						RotateLeft(pParent);
					else
						RotateRL(pParent);
				}
				else
				{
					// 双亲的左子树比较高--->最后一次肯定需要右单旋
					if (-1 == cur->_bf)
						RotateRight(pParent);
					else
						RotateLR(pParent);
				}

				// 旋转完成之后，以parent为根的二叉树高度与插入新节点之前的高度相同
				// 旋转完成之后就不会对parent的上层造成影响
				break;
			}
		}

		return true;
	}

	void InOrder()
	{
		_InOrder(_root);
	}

private:

	void _InOrder(Node* root)
	{
		if (root)
		{
			_InOrder(root->_left);
			cout << root->_data << " ";
			_InOrder(root->_right);
		}
	}

	void RotateLeft(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		// 右单支：subRL为空
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		Node* PParent = parent->_parent;

		// 更新parent和subR的双亲
		parent->_parent = subR;
		subR->_parent = PParent;

		// 循环之前：parent是根节点
		if (NULL == PParent)
		{
			_root = subR;
			subR->_parent = NULL;
		}
		else
		{
			// 循环之前：parent有双亲
			if (PParent->_left == parent)
				PParent->_left = subR;
			else
				PParent->_right = subR;
		}

		parent->_bf = subR->_bf = 0;
	}

	void RotateRight(Node* pParent)
	{
		// pSubL: pParent的左孩子
		// pSubLR: pParent左孩子的右孩子，注意：该
		Node* pSubL = pParent->_left;
		Node* pSubLR = pSubL->_right;
		// 旋转完成之后，30的右孩子作为双亲的左孩子
		pParent->_left = pSubLR;
		// 如果30的左孩子的右孩子存在，更新亲双亲
		if (pSubLR)
			pSubLR->_parent = pParent;
		// 60 作为 30的右孩子
		pSubL->_right = pParent;

		// 因为60可能是棵子树，因此在更新其双亲前必须先保存60的双亲
		Node* pPParent = pParent->_parent;
		// 更新60的双亲
		pParent->_parent = pSubL;
		// 更新30的双亲
		pSubL->_parent = pPParent;
		// 如果60是根节点，根新指向根节点的指针
		if (NULL == pPParent)
		{
			_root = pSubL;
			pSubL->_parent = NULL;
		}
		else
		{
			// 如果60是子树，可能是其双亲的左子树，也可能是右子树
			if (pPParent->_left == pParent)
				pPParent->_left = pSubL;
			else
				pPParent->_right = pSubL;
		}
		// 根据调整后的结构更新部分节点的平衡因子
		pParent->_bf = pSubL->_bf = 0;
	}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		// 旋转之前必须要保存subRL的平衡因子
		// 因为旋转完成之后，需要根据subRL之前的平衡因子调整旋转之后部分节点的平衡因子
		int bf = subRL->_bf;
		RotateRight(parent->_right);
		RotateLeft(parent);

		if (1 == bf)
			parent->_bf = -1;
		else if (-1 == bf)
			subR->_bf = 1;
	}

	// 旋转之前，60的平衡因子可能是-1/0/1，旋转完成之后，根据情况对其他节点的平衡因子进行调整
	void RotateLR(Node* pParent)
	{
		Node* pSubL = pParent->_left;
		Node* pSubLR = pSubL->_right;
		// 旋转之前，保存pSubLR的平衡因子，旋转完成之后，需要根据该平衡因子来调整其他节点的平衡因子
		
		int bf = pSubLR->_bf;
		// 先对30进行左单旋
		RotateLeft(pParent->_left);
		// 再对90进行右单旋
		RotateRight(pParent);

		if (1 == bf)
			pSubL->_bf = -1;
		else if (-1 == bf)
			pParent->_bf = 1;
	}

private:
	Node* _root;
};


void TestAVLTree()
{
	int array[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };

	AVLTree<int> t;
	for (auto e : array)
		t.Insert(e);

	t.InOrder();
}