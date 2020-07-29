#include "HashBucket.hpp"

namespace bite
{
	// unordered_set最终是将key存储到底层的哈希桶中了
	template<class K, class HF = DefInt<K>>
	class unordered_set
	{
		typedef K ValueType;

		struct KOFV
		{
			const K& operator()(const ValueType& value)
			{
				return value;
			}
		};

		typedef HashBucket<ValueType, K, KOFV, HF> HT;
	public:

		// typename作用：明确告诉编译器，HT::iterator是HT类中的类型，而不是静态成员
		typename typedef HT::iterator iterator;


	public:
		unordered_set()
			: ht()
		{}

		///////////////////////////////////
		// 迭代器
		iterator begin()
		{
			return ht.begin();
		}

		iterator end()
		{
			return ht.end();
		}

		//////////////////////////////////////////
		// 容量
		bool empty()const
		{
			return ht.Empty();
		}

		size_t size()const
		{
			return ht.Size();
		}

		//////////////////////////////////////////////////
		// 查找
		iterator find(const K& key)
		{
			return ht.Find(key);
		}

		////////////////////////////////////////////////
		// 修改
		pair<iterator, bool> insert(const ValueType& data)
		{
			return ht.Insert(data);
		}

		size_t erase(const K& key)
		{
			return ht.Delete(key);
		}

		void clear()
		{
			ht.Clear();
		}

		void swap(unordered_map<K, HF>& m)
		{
			ht->Swap(m.ht);
		}

		////////////////////////////////////////
		// 桶相关操作
		// 获取桶的总个数
		size_t bucket_count()const
		{
			return ht.BucketCount();
		}

		// 获取bucketNo中节点的个数
		size_t bucket_size(size_t bucketNo)const
		{
			return ht.BucketSize(bucketNo);
		}

		// 获取key所在的桶号
		size_t bucket(const K& key)
		{
			return ht.Bucket(key);
		}
	private:
		HT ht;
	};
}

#include <iostream>
using namespace std;

#include <string>
void TestUnorderSet()
{
	bite::unordered_set<string, Str2Int> m;
	m.insert("apple");
	m.insert("orange");
	m.insert("peach");
	m.insert("banana");
	m.insert("watermelon");

	cout << m.size() << endl;
	cout << m.bucket("orange") << endl;
	cout << m.bucket_size(m.bucket("orange")) << endl;

	/*
	auto it  = m.begin();
	while(it != m.end())
	{
	cout << "<" << it.first << ", " << it.second << "> ";
	++it;
	}
	cout<<endl;
	*/
	for (auto e : m)
		cout << e<<" ";
	cout << endl;


	auto it = m.find("orange");
	if (it != m.end())
	{
		cout << "orange is in" << endl;
	}

	m.erase("ornage");
	if (it != m.end())
	{
		cout << "orange is in" << endl;
	}
	else
	{
		cout << "没有该键值对" << endl;
	}

	m.clear();
	cout << m.size() << endl;
}