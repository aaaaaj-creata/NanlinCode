#pragma once

#include "RBTree.hpp"

#include <iostream>
using namespace std;


// set中只存储了一个K
namespace bite
{
	template<class K>
	class set
	{
		typedef K ValueType;

		// KOFV作用：
		struct KeyOfValue
		{
			const K& operator()(const ValueType& value)
			{
				return value;
			}
		};

	public:
		typedef RBTree<ValueType, KeyOfValue> RBTree;

		typename typedef RBTree::iterator iterator;

	public:
		set()
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
		// value的类型是：K
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
			return t.Find(key);
		}
	private:
		RBTree t;
	};
}


#include <string>

void TestSet()
{
	bite::set<string> m;
	m.insert("orange");
	m.insert("apple");
	
	if (m.find("peach") == m.end())
	{
		m.insert("peach");
	}

	cout << m.size() << endl;

	auto it = m.begin();
	while (it != m.end())
	{
		cout << (*it) << endl;
		++it;
	}
	cout << endl;

	cout << "=============================" << endl;

	// 范围for
	for (auto& e : m)
		cout << e << endl;
	cout << endl;

	m.clear();
	cout << m.size() << endl;
}