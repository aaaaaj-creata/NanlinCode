#include "HashBucket.hpp"


namespace bite
{
	// unordered_map最终是将键值对存储到底层的哈希桶中了
	template<class K, class V, class HF = DefInt<K>>
	class unordered_map
	{
		typedef pair<K, V> ValueType;

		struct KOFV
		{
			const K& operator()(const ValueType& value)
			{
				return value.first;
			}
		};

		typedef HashBucket<ValueType, K, KOFV, HF> HT;
	public:

		// typename作用：明确告诉编译器，HT::iterator是HT类中的类型，而不是静态成员
		typename typedef HT::iterator iterator;
	public:
		unordered_map()
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

		V& operator[](const K& key)
		{
			//return (*(ht.Insert(make_pair(key, V()).first))).second;
			return (*((this->insert(make_pair(key, V()))).first)).second;
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

		void swap(unordered_map<K, V, HF>& m)
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
void TestUnorderMap()
{
	bite::unordered_map<int, string> m;
	m.insert(make_pair(1, "apple"));
	m.insert(make_pair(2, "orange"));
	m.insert(make_pair(3, "peach"));
	m.insert(make_pair(4, "banana"));
	m.insert(make_pair(5, "watermelon"));

	cout << m.size() << endl;
	cout << m.bucket(2) << endl;
	cout << m.bucket_size(m.bucket(2)) << endl;

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
		cout << "<" << e.first << ", " << e.second << "> ";
	cout << endl;

	
	cout << m[1] << endl;
	auto it = m.find(1);
	if (it != m.end())
	{
		cout << it->second << endl;
	}

	m.erase(1);
	if (it != m.end())
	{
		cout << it->second << endl;
	}
	else
	{
		cout << "没有该键值对" << endl;
	}

	m.clear();
	cout << m.size() << endl;
}