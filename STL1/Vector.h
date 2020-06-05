#pragma once

#include <assert.h>


namespace bite
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

	public:
		vector()
			: start(nullptr)
			, finish(nullptr)
			, end_of_storage(nullptr)
		{}

		vector(int n, const T& data = T())
		{
			start = new T[n];
			for (size_t i = 0; i < n; ++i)
				start[i] = data;

			finish = start + n;
			end_of_storage = finish;
		}

		template<class Iterator>
		vector(Iterator first, Iterator last)
		{
			size_t size = 0;
			auto it = first;
			while (it++ != last) ++size;

			start = new T[size];
			finish = start;
			while (first != last)
			{
				*finish++ = *first++;
			}

			end_of_storage = finish;
		}

		vector(const vector<T>& v)
		{
			start = new T[v.size()];
			finish = start;
			auto it = v.begin();
			while (it != v.end())
				*finish++ = *it++;

			end_of_storage = finish;
		}

		vector<T>& operator=(const vector<T>& v);
		~vector()
		{
			if (start)
				delete[] start;
			start = finish = end_of_storage = nullptr;
		}


		////////////////////////////////////////////////////////////////////
		// 迭代器
		iterator begin()
		{
			return start;
		}

		iterator end()
		{
			return finish;
		}

		const_iterator begin()const
		{
			return start;
		}

		const_iterator end()const
		{
			return finish;
		}

		///////////////////////////////////////////////////////////////////
		// 容量
		size_t size()const
		{
			return finish - start;
		}

		size_t capacity()const
		{
			return end_of_storage - start;
		}

		bool empty()const
		{
			return start == finish;
		}

		void resize(size_t newsize, const T& data = T())
		{
			size_t oldsize = size();
			if (newsize <= oldsize)
			{
				// 将元素减少到newsize
				finish = start + newsize;
			}
			else
			{
				// 将元素增加到newsize----可能需要扩容
				if (newsize > capacity())
				{
					reserve(newsize);
				}

				// 填充元素
				for (size_t i = oldsize; i < newsize; ++i)
					*finish++ = data;
			}
		}

		void reserve(size_t newcapacity)
		{
			size_t oldCapacity = capacity();
			if (newcapacity > oldCapacity)
			{
				// 需要扩容
				// 1. 申请新空间
				T* temp = new T[newcapacity];

				size_t oldsize = size();
				if (start)
				{
					// 2. 拷贝元素
					// 因为memcpy是浅拷贝
					 //memcpy(temp, start, oldsize*sizeof(T));


					for (size_t i = 0; i < oldsize; ++i)
					{
						temp[i] = start[i];  //调用赋值运算符重载：深拷贝方式实现的
					}


					// 3. 释放旧空间
					delete[] start;
				}

				// 4. 使用新空间
				start = temp;
				finish = start + oldsize;
				end_of_storage = start + newcapacity;
			}
		}

		////////////////////////////////////////////////////////////////////
		// acess
		T& operator[](size_t index)
		{
			assert(index < size());
			return start[index];
		}

		const T& operator[](size_t index)const
		{
			assert(index < size());
			return start[index];
		}

		T& front()
		{
			return *start;
		}

		const T& front()const
		{
			return *start;
		}


		T& back()
		{
			return *(finish-1);
		}

		const T& back()const
		{
			return *(finish - 1);
		}

    //////////////////////////////////////////////////
	// modify
		void push_back(const T& data)
		{
			if (finish == end_of_storage)
				reserve(2 * capacity() + 3);

			*finish++ = data;
		}

		void pop_back()
		{
			erase(end() - 1);
		}

		// 返回新插入元素的位置
		iterator insert(iterator pos, const T& data)
		{
			if (pos < start || pos > end())
				return end();

			if (finish == end_of_storage)
				reserve(2 * capacity()+3); // capacity()可能为0--->2*capacity()也是0，不加3则没有办法进行扩容而都导致程序崩溃

			auto cur = finish - 1;
			auto next = finish;
			while (cur >= pos)
			{
				*next-- = *cur--;
			}

			*next = data;
			finish++;
			return pos;
		}

		// 返回值：返回待删除元素的下一个位置
		iterator erase(iterator pos)
		{
			if (pos < start || pos >= finish)
				return finish;

			auto prev = pos;
			auto cur = prev + 1;  // cur就是需要搬移的第一个元素的位置
			while (cur < finish)
			{
				*prev++ = *cur++;
			}

			--finish;
			return pos;
		}
		
		void clear()
		{
			finish = start;
		}

	private:
		iterator start;   // 空间起始位置
		iterator finish;  // 最后一个元素的下一个位置
		iterator end_of_storage;   // 空间的末尾
	};
}

