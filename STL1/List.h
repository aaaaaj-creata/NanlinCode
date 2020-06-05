#pragma once

namespace bite
{
	template<class T>
	struct ListNode
	{
		ListNode<T>* next;
		ListNode<T>* prev;
		T val;

		ListNode(const T& value)
			: next(nullptr)
			, prev(nullptr)
			, val(value)
		{}
	};


	template<class T>
	class list
	{
		typedef ListNode<T> Node;
		typedef T* iterator;   // list的迭代器能否给成原生态的指针？？？
	public:
		list()
		{
			CreateHead();
		}


		list(int n, const T& value = T())
		{
			CreateHead();
			for (int i = 0; i < n; ++i)
				push_back(value);
		}


		template<class Iterator>
		list(Iterator first, Iterator last)
		{
			CreateHead();
			while (first != last)
			{
				push_back(*first);
			}
		}

		list(const list<T>& L)
		{
			CreateHead();
			auto it = L.begin();

			while (it != L.end())
			{
				push_back(*it);
			}
		}

		list<T>& operator=(const list<T>& L);

		~list()
		{
			// 1. 删除有效节点
			// 2. 删除头结点
			erase(begin(), end());
			delete head;
			head = nullptr;
		}

		///////////////////////////////////////////////
		// 迭代器操作
		iterator begin();
		iterator end();


		///////////////////////////////////////////////
		// 容量相关的操作
		size_t size()const
		{
			size_t count = 0;
			auto it = begin();
			while (it != v.end()) ++it, ++count;
			return count;
		}

		bool empty()const
		{
			return head->next == head;
		}

		void resize(size_t newsize, const T& data = T())
		{
			size_t oldsize = size();
			if (newsize < oldsize)
			{
				for (size_t i = newsize; i < oldsize; ++i)
					pop_back();
			}
			else
			{
				for (size_t i = oldsize; < i < newsize; ++i)
					push_back(data);
			}
		}

		/////////////////////////////////////////////////
		// 元素访问

		// 访问链表中第一个元素
		T& front()
		{
			return head->next->val;
		}

		const T& front()const
		{
			return head->next->val;
		}

		// 访问链表最后一个节点中的元素
		T& back()
		{
			return head->prev->val;
		}

		const T& back()const
		{
			return head->prev->val;
		}

		////////////////////////////////////////////////////
		// 修改操作
		void push_back(const T& data)
		{
			insert(v.end(), data);
		}

		void pop_back()
		{
			auto it = v.end();
			erase(--it);
		}

		void push_front(const T& data)
		{
			insert(begin(), data);
		}

		void pop_front()
		{
			erase(begin());
		}

		iterator insert(iterator pos, const T& data)
		{
			return begin();
		}

		iterator erase(iterator pos)
		{
			return begin();
		}

		iterator erase(iterator first, iterator last)
		{
			return begin();
		}

		void clear()
		{
			erase(begin(), end());
		}

		void swap(list<T>& l)
		{
			std::swap(head, L.head);
		}

	private:
		void CreateHead()
		{
			head = new Node;
			head->prev = head;
			head->next = head;
		}
	private:
		Node* head;
	};
}