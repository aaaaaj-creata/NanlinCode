#pragma once

#include <iostream>
using namespace std;


enum Color{RED, BLACK};


template<class T>
struct RBTreeNode
{
	RBTreeNode(const T& data = T(), Color color = RED)
	: _left(nullptr)
	, _right(nullptr)
	, _parent(nullptr)
	, _data(data)
	, _color(color)
	{}

	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	T _data;
	Color _color;
};


#if 0
// 假设：为了简单起见，创建的红黑树中的值是唯一的
template<class T>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	RBTree()
	{
		head = new Node;
		head->_left = head;
		head->_right = head;
		head->_parent = nullptr;
	}

	bool Insert(const T& data)
	{
		// root就是头结点中parent的别名
		Node*& root = GetRoot();

		// 1. 按照二叉搜索树的规则插入新节点
		//if (NULL == head->_parent)
		if(NULL == root)  // 因为root是head中parent的别名，即修改root的指向就是修改head中parent的指向
		{
			root = new Node(data, BLACK);
			root->_parent = head;
			head->_left = root;
			head->_right = root;
			return true;
		}

		// 树非空
		// 按照二叉搜索树的规则找待插入节点在红黑树中位置
		Node* cur = root;
		Node* parent = NULL;
		while (cur)
		{
			parent = cur;
			if (data < cur->_data)
				cur = cur->_left;
			else if (data > cur->_data)
				cur = cur->_right;
			else
				return false;
		}

		// 插入新节点
		cur = new Node(data);
		if (data < parent->_data)
			parent->_left = cur;
		else
			parent->_right = cur;

		cur->_parent = parent;

		// 2. cur节点默认的颜色是红色，如果cur的双亲parent节点的颜色是黑色，没有违反任何红黑树的性质
		//    如果cur的双亲parent节点的颜色是红色，违反了性质3：没有连在一起的红色节点
		// 需要对节点颜色进行调整 + 旋转处理
		while (parent != head && RED == parent->_color)  // 注意：循环条件可能有点问题
		{
			// 违反了性质三：没有连在一起的红色节点
			Node* grandFather = parent->_parent;
			if (parent == grandFather->_left)
			{
				Node* uncle = grandFather->_right;
				if (uncle && RED == uncle->_color)
				{
					// 叔叔节点存在且为红---场景一
					parent->_color = BLACK;
					uncle->_color = BLACK;
					grandFather->_color = RED;
					cur = grandFather;
					parent = cur->_parent;
				}
				else
				{
					// 叔叔节点不存在 || 叔叔节点存在但是颜色是黑色
					if (cur == parent->_right)
					{
						// 场景三
						RotateLeft(parent);
						swap(parent, cur);
					}

					// 场景二：
					grandFather->_color = RED;
					parent->_color = BLACK;
					RotateRight(grandFather);
				}
			}
			else
			{
				Node* uncle = grandFather->_left;
				if (uncle && RED == uncle->_color)
				{
					parent->_color = BLACK;
					uncle->_color = BLACK;
					grandFather->_color = RED;
					cur = grandFather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						RotateRight(parent);
						swap(parent, cur);
					}

					grandFather->_color = RED;
					parent->_color = BLACK;
					RotateLeft(grandFather);
				}
			}
		}

		root->_color = BLACK;
		head->_left = LeftMost();
		head->_right = RightMost();
		return true;
	}

	void InOrder()
	{
		_InOrder(GetRoot());
		cout << endl;
	}

	Node* LeftMost()
	{
		Node* root = GetRoot();
		if (NULL == root)
			return head;

		Node* cur = root;
		while (cur->_left)
			cur = cur->_left;

		return cur;
	}

	Node* RightMost()
	{
		Node* root = GetRoot();
		if (NULL == root)
			return head;

		Node* cur = root;
		while (cur->_right)
			cur = cur->_right;

		return cur;
	}

	bool IsValidRBTree()
	{
		Node* root = GetRoot();
		if (nullptr == root)
			return true;

		if (BLACK != root->_color)
		{
			cout << "违反性质二：根节点必须是黑色--->根节点不是黑色的" << endl;
			return false;
		}

		// 获取一条路径中黑色节点的个数: 获取的是最左侧路径中节点的个数
		size_t blackCount = 0;
		Node* cur = root;
		while (cur)
		{
			if (BLACK == cur->_color)
				blackCount++;

			cur = cur->_left;
		}

		// 用其他路径中黑色节点的个数与当前路径中黑色节点个数对比
		size_t pathCount = 0;
		return _IsValidRBTree(root, blackCount, pathCount);
	}


private:
	bool _IsValidRBTree(Node* root, const size_t blackCount, size_t pathCount)
	{
		if (nullptr == root)
			return true;

		if (BLACK == root->_color)
			pathCount++;

		Node* parent = root->_parent;
		// root的双亲确实是存在
		if (parent != head)
		{
			if (RED == root->_color && parent->_color == RED)
			{
				cout << "违反了性质3：没有连在一起的红色节点--->现在有" << endl;
				return false;
			}
		}

		// root是一个叶子节点，说明已经找到了一条路径
		if (nullptr == root->_left && nullptr == root->_right)
		{
			if (pathCount != blackCount)
			{
				cout << "违反了性质4：每天路径中黑色节点个数相等--->现在不相等" << endl;
				return false;
			}
		}

		return _IsValidRBTree(root->_left, blackCount, pathCount) &&
			   _IsValidRBTree(root->_right, blackCount, pathCount);
	}

	void _InOrder(Node* root)
	{
		if (root)
		{
			_InOrder(root->_left);
			cout << root->_data << " ";
			_InOrder(root->_right);
		}
	}

	Node*& GetRoot()
	{
		return head->_parent;
	}

	// parent的右子树高
	void RotateLeft(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;

		Node* pparent = parent->_parent;
		subR->_parent = pparent;
		parent->_parent = subR;

		if (pparent == head)
		{
			// 旋转之前parent是根节点
			head->_parent = subR;
		}
		else
		{
			if (parent == pparent->_left)
				pparent->_left = subR;
			else
				pparent->_right = subR;
		}
	}

	void RotateRight(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;

		Node* pparent = parent->_parent;
		subL->_parent = pparent;
		parent->_parent = subL;

		if (pparent == head)
		{
			head->_parent = subL;
		}
		else
		{
			if (parent == pparent->_left)
				pparent->_left = subL;
			else
				pparent->_right = subL;
		}
	}

private:
	Node* head;
};

void TestRBTree()
{
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	RBTree<int> bt;
	for (auto e : a)
		bt.Insert(e);

	bt.InOrder();
	cout << bt.LeftMost()->_data << endl;
	cout << bt.RightMost()->_data << endl;

	if (bt.IsValidRBTree())
	{
		cout << "bt is rbtree!!!" << endl;
	}
	else
	{
		cout << "bt is not rbtree!!!" << endl;
	}
}
#endif

/*
添加迭代器的步骤：
1. 根据容器底层数据结构的特性封一个迭代器的类
2. 在容器类中给迭代器取别名 iterator
3. 给容器类增加begin和end的方法
*/


template<class T>
struct RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T> Self;

	RBTreeIterator(Node* node)
		: _node(node)
	{}

	// 让迭代器具有指针类似的操作
	T& operator*()
	{
		return _node->_data;
	}

	T* operator->()
	{
		//return &_node->_data;
		return &(operator*());
	}

	// 让迭代器可以移动
	Self& operator++()
	{
		Increment();  // 取node的下一个节点
		return *this;
	}

	Self operator++(int)
	{
		Self temp(*this);
		Increment();  // 取node的下一个节点
		return temp;
	}

	Self& operator--()
	{
		Decrement();  // 取node的下一个节点
		return *this;
	}

	Self operator--(int)
	{
		Self temp(*this);
		Decrement();  // 取node的下一个节点
		return temp;
	}

	// 迭代器可以比较
	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}

	bool operator==(const Self& s)
	{
		return _node == s._node;
	}

	// 让迭代器取后一个节点
	void Increment()
	{
		if (_node->_right)
		{
			// _node的下一个节点就为其右子树中最小的节点--->最左侧的节点
			_node = _node->_right;
			while (_node->_left)
				_node = _node->_left;
		}
		else
		{
			// 如果node的右子树不存在，比node大的节点可以再在其双亲中寻找
			Node* parent = _node->_parent;
			while (_node == parent->_right)
			{
				_node = parent;
				parent = _node->_parent;
			}

			// 注意：迭代器在根接待你的位置 然后根节点没有右子树的特殊场景
			if (_node->_right != parent)
				_node = parent;
		}
	}

	// 让迭代器取前一个节点
	void Decrement()
	{
		// 找_node小的节点，优先到_node的左子树中查找
		// 应该到左子树中找最大的节点--->就是左子树中最右侧节点
		if (_node == _node->_parent->_parent && _node->_color == RED)
		{
			// 迭代器在end()的位置
			_node = _node->_right;
		}
		else if (_node->_left)
		{
			_node = _node->_left;
			while (_node->_right)
				_node = _node->_right;
		}
		else
		{
			// _node没有左子树,让_node向上找
			Node* parent = _node->_parent;
			while (_node == parent->_left)
			{
				_node = parent;
				parent = _node->_parent;
			}

			_node = parent;
		}
	}

private:
	Node* _node;
};

// 假设：为了简单起见，创建的红黑树中的值是唯一的
// T: 表示红黑树中存储元素的类型
// KOFV: 表示从data中提取key的仿函数类型
template<class T, class KOFV>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef RBTreeIterator<T> iterator;

public:
	RBTree()
		: _size(0)
	{
		head = new Node;
		head->_left = head;
		head->_right = head;
		head->_parent = nullptr;
	}

	~RBTree()
	{
		DestroyRBTree(head->_parent);
		delete head;
	}

	iterator begin()
	{
		return iterator(head->_left);
	}

	iterator end()
	{
		return iterator(head);
	}
	
	pair<iterator, bool> Insert(const T& data)
	{
		// root就是头结点中parent的别名
		Node*& root = GetRoot();

		// 1. 按照二叉搜索树的规则插入新节点
		//if (NULL == head->_parent)
		if (NULL == root)  // 因为root是head中parent的别名，即修改root的指向就是修改head中parent的指向
		{
			root = new Node(data, BLACK);
			root->_parent = head;
			head->_left = root;
			head->_right = root;
			_size++;
			return make_pair(begin(), true);
		}

		// 树非空
		// 按照二叉搜索树的规则找待插入节点在红黑树中位置
		Node* cur = root;
		Node* parent = NULL;
		KOFV kofv;
		while (cur)
		{
			parent = cur;
			//if (kofv.operator()(data) < kofv.operator()(cur->_data))
			if (kofv(data) < kofv(cur->_data))
				cur = cur->_left;
			else if (kofv(data) > kofv(cur->_data))
				cur = cur->_right;
			else
				return make_pair(iterator(cur), false);
		}

		// 插入新节点
		cur = new Node(data);
		Node* newNode = cur;
		if (kofv(data) < kofv(parent->_data))
			parent->_left = cur;
		else
			parent->_right = cur;

		cur->_parent = parent;

		// 2. cur节点默认的颜色是红色，如果cur的双亲parent节点的颜色是黑色，没有违反任何红黑树的性质
		//    如果cur的双亲parent节点的颜色是红色，违反了性质3：没有连在一起的红色节点
		// 需要对节点颜色进行调整 + 旋转处理
		while (parent != head && RED == parent->_color)  // 注意：循环条件可能有点问题
		{
			// 违反了性质三：没有连在一起的红色节点
			Node* grandFather = parent->_parent;
			if (parent == grandFather->_left)
			{
				Node* uncle = grandFather->_right;
				if (uncle && RED == uncle->_color)
				{
					// 叔叔节点存在且为红---场景一
					parent->_color = BLACK;
					uncle->_color = BLACK;
					grandFather->_color = RED;
					cur = grandFather;
					parent = cur->_parent;
				}
				else
				{
					// 叔叔节点不存在 || 叔叔节点存在但是颜色是黑色
					if (cur == parent->_right)
					{
						// 场景三
						RotateLeft(parent);
						swap(parent, cur);
					}

					// 场景二：
					grandFather->_color = RED;
					parent->_color = BLACK;
					RotateRight(grandFather);
				}
			}
			else
			{
				Node* uncle = grandFather->_left;
				if (uncle && RED == uncle->_color)
				{
					parent->_color = BLACK;
					uncle->_color = BLACK;
					grandFather->_color = RED;
					cur = grandFather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						RotateRight(parent);
						swap(parent, cur);
					}

					grandFather->_color = RED;
					parent->_color = BLACK;
					RotateLeft(grandFather);
				}
			}
		}

		root->_color = BLACK;
		head->_left = LeftMost();
		head->_right = RightMost();
		_size++;
		return make_pair(iterator(newNode), true);
	}

	iterator Find(const T& data)
	{
		Node* cur = GetRoot();
		while (cur)
		{
			// KOFV是一个类型  KOFV(): 调用默认的无参构造函数创建一个匿名对象(没有名字的对象)
			// 让KOFV的匿名对象调用()的重载来提取data中的key
			if (KOFV()(data) == KOFV()(cur->_data))
				return iterator(cur);
			else if (KOFV()(data) < KOFV()(cur->_data))
				cur = cur->_left;
			else
				cur = cur->_right;
		}

		return end();
	}

	void InOrder()
	{
		_InOrder(GetRoot());
		cout << endl;
	}

	void Clear()
	{
		DestroyRBTree(GetRoot());
		_size = 0;
	}

	Node* LeftMost()
	{
		Node* root = GetRoot();
		if (NULL == root)
			return head;

		Node* cur = root;
		while (cur->_left)
			cur = cur->_left;

		return cur;
	}

	Node* RightMost()
	{
		Node* root = GetRoot();
		if (NULL == root)
			return head;

		Node* cur = root;
		while (cur->_right)
			cur = cur->_right;

		return cur;
	}

	bool IsValidRBTree()
	{
		Node* root = GetRoot();
		if (nullptr == root)
			return true;

		if (BLACK != root->_color)
		{
			cout << "违反性质二：根节点必须是黑色--->根节点不是黑色的" << endl;
			return false;
		}

		// 获取一条路径中黑色节点的个数: 获取的是最左侧路径中节点的个数
		size_t blackCount = 0;
		Node* cur = root;
		while (cur)
		{
			if (BLACK == cur->_color)
				blackCount++;

			cur = cur->_left;
		}

		// 用其他路径中黑色节点的个数与当前路径中黑色节点个数对比
		size_t pathCount = 0;
		return _IsValidRBTree(root, blackCount, pathCount);
	}

	bool Empty()const
	{
		return nullptr == head->_parent;
	}

	size_t Size()const
	{
		return _size;
	}


private:
	void DestroyRBTree(Node*& root)
	{
		if (root)
		{
			DestroyRBTree(root->_left);
			DestroyRBTree(root->_right);
			delete root;
			root = nullptr;
		}
	}

	bool _IsValidRBTree(Node* root, const size_t blackCount, size_t pathCount)
	{
		if (nullptr == root)
			return true;

		if (BLACK == root->_color)
			pathCount++;

		Node* parent = root->_parent;
		// root的双亲确实是存在
		if (parent != head)
		{
			if (RED == root->_color && parent->_color == RED)
			{
				cout << "违反了性质3：没有连在一起的红色节点--->现在有" << endl;
				return false;
			}
		}

		// root是一个叶子节点，说明已经找到了一条路径
		if (nullptr == root->_left && nullptr == root->_right)
		{
			if (pathCount != blackCount)
			{
				cout << "违反了性质4：每天路径中黑色节点个数相等--->现在不相等" << endl;
				return false;
			}
		}

		return _IsValidRBTree(root->_left, blackCount, pathCount) &&
			_IsValidRBTree(root->_right, blackCount, pathCount);
	}

	void _InOrder(Node* root)
	{
		if (root)
		{
			_InOrder(root->_left);
			cout << root->_data << " ";
			_InOrder(root->_right);
		}
	}

	Node*& GetRoot()
	{
		return head->_parent;
	}

	// parent的右子树高
	void RotateLeft(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;

		Node* pparent = parent->_parent;
		subR->_parent = pparent;
		parent->_parent = subR;

		if (pparent == head)
		{
			// 旋转之前parent是根节点
			head->_parent = subR;
		}
		else
		{
			if (parent == pparent->_left)
				pparent->_left = subR;
			else
				pparent->_right = subR;
		}
	}

	void RotateRight(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;

		Node* pparent = parent->_parent;
		subL->_parent = pparent;
		parent->_parent = subL;

		if (pparent == head)
		{
			head->_parent = subL;
		}
		else
		{
			if (parent == pparent->_left)
				pparent->_left = subL;
			else
				pparent->_right = subL;
		}
	}

private:
	Node* head;
	size_t _size;  // 表示红黑树中节点的个数
};
