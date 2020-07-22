#pragma once

#include <iostream>
using namespace std;

#include <vector>
#include <string>

#include "Common.h"


template<class T>
struct HashNode
{
	HashNode<T>* _next;
	T _data;

	HashNode(const T& data = T())
		: _next(nullptr)
		, _data(data)
	{}
};


// 将字符串转换为整形的数据？
struct Str2Int
{
	size_t operator()(const string& s)
	{
		const char* str = s.c_str();
		unsigned int seed = 131; // 31 131 1313 13131 131313
		unsigned int hash = 0;
		while (*str)
		{
			hash = hash * seed + (*str++);
		}
		return (hash & 0x7FFFFFFF);
	}
};

template<class T>
struct DefInt
{
	size_t operator()(const T& data)
	{
		return data;
	}
};


template<class T, class K, class KOFV, class DF = DefInt<T>>
class HashBucket;

template<class T, class K, class KOFV, class HF = DefInt<T>>
class HashBucketIterator
{
	typedef HashNode<T> Node;
	typedef HashBucketIterator<T, K, KOFV, HF> Self;
public:
	HashBucketIterator(HashBucket<T, K, KOFV, HF>* ht, Node* node)
		: _node(node)
		, _ht(ht)
	{}

	// 具有指针类似的操作
	T& operator*()
	{
		return _node->_data;
	}

	T* operator->()
	{
		// return &_node->_data;
		return &(operator*());
	}

	// 迭代器可以移动：一个桶遍历完，然后取下一个桶
	Self& operator++()  // 前置++
	{
		Next();
		return *this;
	}

	Self operator++(int)  // 后置++
	{
		Self temp(*this);
		Next();
		return temp;
	}

	// 注意：HashBucket的迭代器不支持--的操作，因为其底层使用的是单链表，单链表不能--往前移动

	// 能够比较
	bool operator==(const Self& s)
	{
		return _ht == s._ht && _node == s._node;
	}

	bool operator!=(const Self& s)
	{
		return !(*this == s);
	}
private:
	void Next()
	{
		if (_node->_next)
		{
			_node = _node->_next;
		}
		else
		{
			// _node是当前链表中的最后一个节点
			// 此时迭代器向后移动时，_node应该将其放在下一个非空桶的链表的首节点的位置

			// 从_node所在当前桶开始找下一个非空桶
			size_t bucketNo = _ht->HashFunc(KOFV()(_node->_data)) + 1;

			for (; bucketNo < _ht->BucketCount(); ++bucketNo)
			{
				if (_ht->_table[bucketNo])
				{
					// _table是哈希桶对象中的私有成员，该出不能直接访问
					_node = _ht->_table[bucketNo];
					return;
				}
			}

			_node = nullptr;
		}
	}
private:
	Node* _node;
	HashBucket<T, K, KOFV, HF>* _ht;   // 保存一个哈希桶的对象
};

// 简单起见，哈希桶中的元素唯一
// T: 表示哈希桶中存储元素的类型，可能是键值对，也可能是key
// K： 表示哈希桶中存储元素的key的类型
// KOFV: 从value中将key提取出来的类型
// DF: 将key转换为整形的类型
template<class T,class K, class KOFV, class DF>
class HashBucket
{
	// 为了让HashBucketIterator访问HashBucket中的私有成员--->借助友元
	friend class HashBucketIterator<T, K, KOFV, DF>;

	typedef HashNode<T> Node;
	typedef HashBucket<T, K, KOFV, DF> Self;

public:
	typedef HashBucketIterator<T, K, KOFV, DF> iterator;

public:
	HashBucket(size_t initCap = 10)
		: _table(GetNextPrime(initCap))
		, _size(0)
	{}

	~HashBucket()
	{
		Clear();
	}

	iterator begin()
	{
		// 第一个非空桶中的第一个节点的位置
		for (size_t bucketNo = 0; bucketNo < BucketCount(); ++bucketNo)
		{
			if (_table[bucketNo])
			{
				return iterator(this, _table[bucketNo]);
			}
		}

		return end();
	}

	iterator end()
	{
		return iterator(this, nullptr);
	}

	pair<iterator, bool> Insert(const T& data)
	{
		CheckCapacity();

		// 1. 先通过哈希函数计算桶号
		size_t bucketNo = HashFunc(KOFV()(data));

		// 2. 找到桶--->找到要在哪个链表中插入
		Node* cur = _table[bucketNo];

		// 3. 检测该元素是否在哈希桶中---即在bucket桶检测该元素是否存在--->在对应链表中找是否存在值为data的节点
		while (cur)
		{
			// 元素如果存在则不插入
			if (KOFV()(cur->_data) == KOFV()(data))
				return make_pair(iterator(this, cur), false);

			cur = cur->_next;
		}

		// 4. 插入新节点
		cur = new Node(data);

		// 使用头插
		cur->_next = _table[bucketNo];
		_table[bucketNo] = cur;
		++_size;
		return make_pair(iterator(this, cur), true);
	}

	size_t Delete(const K& key)
	{
		// 1. 先通过哈希函数计算桶号
		size_t bucketNo = HashFunc(key);

		// 2. 找到桶--->找到要在哪个链表中删除节点
		Node* cur = _table[bucketNo];
		Node* prev = nullptr;
		// 3. 检测该元素是否在哈希桶中---即在bucket桶检测该元素是否存在--->在对应链表中找是否存在值为data的节点
		while (cur)
		{
			// 元素如果存在则删除
			if(KOFV()(cur->_data) == key)
			{
				// 头删
				if (prev == nullptr)
				{
					_table[bucketNo] = cur->_next;
				}
				else
				{
					// 其他位置删除
					prev->_next = cur->_next;
				}

				delete cur;
				--_size;
				return 1;
			}

			prev = cur;
			cur = cur->_next;
		}


		// 哈希表中不存在值为data的节点
		return 0;
	}

	iterator Find(const K& key)
	{
		// 1. 先通过哈希函数计算桶号
		size_t bucketNo = HashFunc(key);

		// 2. 找到桶--->找到要在哪个链表中查找
		Node* cur = _table[bucketNo];

		while (cur)
		{
			if (KOFV()(cur->_data) == key)
				return iterator(this, cur);

			cur = cur->_next;
		}

		return end();
	}

	size_t Size()const
	{
		return _size;
	}

	bool Empty()const
	{
		return 0 == _size;
	}

	void Clear()
	{
		// 遍历每个桶，如果有节点则删除
		// 即：逐个删除每个链表中的所有元素
		for (size_t bucketNo = 0; bucketNo < _table.capacity(); ++bucketNo)
		{
			Node* cur = _table[bucketNo];
			while (cur)
			{
				// 头删
				_table[bucketNo] = cur->_next;
				delete cur;
				cur = _table[bucketNo];
			}
		}

		_size = 0;
	}

	size_t BucketCount()const
	{
		return _table.capacity();
	}

	// 返回bucketNo中节点个个数
	size_t BucketSize(size_t bucketNo)const
	{
		Node* cur = _table[bucketNo];
		size_t count = 0;
		while (cur)
		{
			count++;
			cur = cur->_next;
		}

		return count;
	}

	size_t Bucket(const K& key)const
	{
		return HashFunc(key);
	}

	///////////////////////////////////////////////////////
	// 测试使用辅助打印
	void PrintHashBucket()
	{
		for (size_t bucketNo = 0; bucketNo < _table.capacity(); ++bucketNo)
		{
			cout << "table[" << bucketNo << "]:";
			Node* cur = _table[bucketNo];
			while (cur)
			{
				cout << cur->_data << "--->";
				cur = cur->_next;
			}

			cout << "NULL" << endl;
		}
		cout << endl;
	}

	void Swap(Self& ht)
	{
		_table.swap(ht._table);
		swap(_size, ht._size);
	}

private:
	size_t HashFunc(const K& key)const
	{
		// DF()(data): 通过DF创建的匿名对象，调用其operator()的重载将data转换为整形
		return DF()(key) % _table.capacity();
	}

	/*
	// 思考：该中扩容方式不好的地方在哪里？
	void CheckCapacity()
	{
		// 当哈希表中有效元素个数与桶的个数相等时候则扩容
		if (_size == _table.capacity())
		{
			// 创建新的哈希表
			HashBucket<T> newHt(_size*2);

			// 将旧哈希表(this)中的元素插入到新哈希表中
			for (size_t i = 0; i < _table.capacity(); ++i)
			{
				Node* cur = _table[i];
				while (cur)
				{
					newHt.Insert(cur->_data);
					cur = cur->_next;
				}
			}

			// 将两个哈希表中元素交换--->交换之后：
			// this中存储newHt中的节点，newHt中存储的就是旧this中节点
			// 出了函数的作用域，newHt要被销毁，newHt桶中的节点就会被释放-->即将原this中的节点销毁了
			this->Swap(newHt);
		}
	}
	*/

	void CheckCapacity()
	{
		// 当哈希表中有效元素个数与桶的个数相等时候则扩容
		if (_size == _table.capacity())
		{
			// 创建新的哈希表
			Self newHt(GetNextPrime(_size));

			// 将旧哈希表(this)中的元素插入到新哈希表中
			for (size_t i = 0; i < _table.capacity(); ++i)
			{
				Node* cur = _table[i];
				while (cur)
				{
					// 将cur节点从旧哈希桶中删除--头删
					_table[i] = cur->_next;

					// 将cur节点往新的哈希桶中插入
					// 计算元素在新哈希表中的桶号
					size_t bucketNo = newHt.HashFunc(KOFV()(cur->_data));

					// 头插
					cur->_next = newHt._table[bucketNo];
					newHt._table[bucketNo] = cur;
					
					cur = _table[i];
				}
			}

			// 将两个哈希表中元素交换--->交换之后：
			// 旧哈希桶中所有的节点已经搬移到新哈希桶中了，旧哈希桶现在为空
			// this中存储newHt中的节点，newHt中存储的就是旧this中节点
			// 出了函数的作用域，newHt要被销毁，newHt桶中的节点就会被释放-->即将原this中的节点销毁了
			this->Swap(newHt);
		}
	}
private:
	vector<Node*> _table;
	size_t _size;  // 表示哈希表中有效元素的个数
};

/*
void TestHashBucket1()
{
	HashBucket<int> ht(10);

	int array[] = {1,4,5,6,7,9,11,14,15,16};
	for (auto e : array)
		ht.Insert(e);
	ht.PrintHashBucket();

	ht.Insert(17);
	ht.PrintHashBucket();

	auto it = ht.begin();
	while (it != ht.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	cout << ht.Size() << endl;
	ht.PrintHashBucket();

	ht.Insert(54);
	ht.Insert(44);
	ht.PrintHashBucket();

	if (ht.end() == ht.Find(44))
	{
		cout << "44 is not in hashbucket!!!" << endl;
	}
	else
	{
		cout << "44 is  in hashbucket!!!" << endl;
	}

	ht.Delete(44);
	if (ht.end() == ht.Find(44))
	{
		cout << "44 is not in hashbucket!!!" << endl;
	}
	else
	{
		cout << "44 is  in hashbucket!!!" << endl;
	}

	ht.Delete(54);
	ht.PrintHashBucket();

	ht.Clear();
	cout << ht.Size() << endl;
}


void TestHashBucket2()
{
	HashBucket<string, Str2Int> ht(10);
	ht.Insert("hello");
	ht.Insert("world");
}
*/

