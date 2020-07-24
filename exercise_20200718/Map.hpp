#pragma once

#include "RBTree.hpp"

#include <iostream>
using namespace std;


// map中存放的是k-v的键值对pair<K, V>
namespace bite
{
	template<class K, class V>
	class map
	{
		typedef pair<K, V> ValueType;

		// KOFV作用：从value中提取key
		struct KeyOfValue
		{
			const K& operator()(const ValueType& value)
			{
				return value.first;
			}
		};

	public:
		typedef RBTree<ValueType, KeyOfValue> RBTree;

		/*
		typedef RBTree::iterator iterator;   // 编译是报错
		原因：静态成员访问形式--->可以通过类名::静态成员名字直接进行访问
		RBTree::iterator编译在解析时，可能会将iterator解析成RBTree类中静态的成员
		如果编译器将iterator解析成RBTree中静态的成员时肯定会出错，因为iterator是RBTree中的一个类型

		typename typedef RBTree::iterator iterator;  
		typename：如果出现在typedef之前，表示类::名字  这个名字是类中的类型，而不是静态成员
		上述例子：明确告诉编译器iterator是RBTree中的一个类型
		*/
		typename typedef RBTree::iterator iterator;

	public:
		map()
			: t()
		{}

		iterator begin()
		{
			return t.begin();
		}

		iterator end()
		{
			return t.end();
		}


		//////////////////////////////////////////////////////////
		bool empty()const
		{
			return t.Empty();
		}

		size_t size()const
		{
			return t.Size();
		}

		//////////////////////////////////////////////////////////
		/*
		为什么map中[]要调用insert？
		因为operator是通过key来获取与key对应的value
		如果key对应的键值对在map中存在时，将来直接返回与key对应的value就可以了
		如果key对应的键值对不在map中存在时，没有办法进行返回了

		因此：operator[]底层使用insert来获取与key对应的value
		insert的原理：
		<key, value>的键值对向红黑树中插入时：
		   如果key在红黑树中已经存在时，insert用与key对应的节点构造一个迭代器以及true来返回<找到与key对应的节点，false>
		   如果key在红黑树中不存在时，insert会完成插入，并返回<新插入节点构造迭代器，true>

		   要获取与参数key对应的value，map也不知道里面是否存在与key相等的键值对：
		   map就用<key, 默认的value>构造一个键值对，尝试向map中插入，插入结果：
		    1. 插入成功，map中不存在与key相等的键值对，返回值<新节点对应的迭代器，true>
			2. 插入失败，map中已经存在与key相等的键值对，返回值<与key相当的节点对应的迭代器, false>

		*/
		V& operator[](const K& key)
		{
			return (*(insert(make_pair(key, V())).first)).second;
		}

		// value的类型是：pair<K, V>
		pair<iterator, bool> insert(const ValueType& value)
		{
			return t.Insert(value);
		}

		void clear()
		{
			t.Clear();
		}

		//////////////////////////////////////////////////////////////
		iterator find(const K& key)
		{
			return t.Find(make_pair(key, V()));
		}
	private:
		RBTree t;
	};
}


#include <string>

void TestMap()
{
	bite::map<string, string> m;
	m.insert(pair<string, string>("orange", "橙子"));
	m.insert(make_pair("apple", "苹果"));
	cout << m["apple"] << endl;
	cout << m["banana"] << endl;    //banana对应的key不存在，map先将<"banana", "">键值对向红黑树中插入，然后返回""

	m["banana"] = "香蕉";

	if (m.find("peach") == m.end())
	{
		m["peach"] = "桃子";
	}

	cout << m.size() << endl;

	auto it = m.begin();
	while (it != m.end())
	{
		cout << (*it).first << "--->" << it->second << endl;
		++it;
	}
	cout << endl;

	cout << "=============================" << endl;

	// 范围for
	for (auto& e : m)
		cout << e.first << "--->" << e.second << endl;
	cout << endl;

	m.clear();
	cout << m.size() << endl;
}