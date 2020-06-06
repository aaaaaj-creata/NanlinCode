#pragma once

namespace bite
{
	template<class T>
	struct ListNode
	{
		ListNode<T>* next;
		ListNode<T>* prev;
		T val;

		ListNode(const T& value = T())
			: next(nullptr)
			, prev(nullptr)
			, val(value)
		{}
	};

	// list的迭代器必须要对原生态指针(节点类型的指针)进行封装
	template<class T, class Ref, class Ptr>
	struct ListIterator
	{
	public:
		typedef ListNode<T> Node;
		typedef ListIterator<T, Ref, Ptr>  Self;
	public:
		// 构造
		ListIterator(Node* node = nullptr)
			: _node(node)
		{}

		// 具有类似指针的行为
		Ref operator*()
		{
			return _node->val;
		}

		Ptr operator->()
		{
			// return &(_node->val);
			return &(operator*());
		}

		// 迭代器能够移动
		// 前置++
		Self& operator++()
		{
			_node = _node->next;
			return *this;
		}

		// 后置++
		Self operator++(int)
		{
			Self temp(*this);
			_node = _node->next;
			return temp;
		}

		// 前置--
		Self& operator--()
		{
			_node = _node->prev;
			return *this;
		}

		// 后置++
		Self operator--(int)
		{
			Self temp(*this);
			_node = _node->prev;
			return temp;
		}

		//比较
		bool operator!=(const Self& s)const
		{
			return _node != s._node;
		}

		bool operator==(const Self& s)const
		{
			return _node == s._node;
		}
	
		Node* _node;
	};


	template<class T>
	class list
	{
		typedef ListNode<T> Node;
		// typedef T* iterator;   // list的迭代器能否给成原生态的指针？？？
		// 不行，对于list迭代器如果使用原生态的指针，当对迭代器进行++操作时，无法取到下一个节点
		// 链表取下一个节点只能通过next来进行获取

	public:
		typedef ListIterator<T, T&, T*> iterator;
		typedef ListIterator<T, const T&, const T*> const_iterator;
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
				push_back(*first++);
			}
		}

		list(list<T>& L)
		{
			CreateHead();
			auto it = L.begin();

			while (it != L.end())
			{
				push_back(*it++);
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
		iterator begin()
		{
			return iterator(head->next);
		}

		iterator end()
		{
			return iterator(head);
		}

		const_iterator cbegin()const
		{
			return const_iterator(head->next);
		}

		const_iterator cend()const
		{
			return const_iterator(head);
		}


		///////////////////////////////////////////////
		// 容量相关的操作
		size_t size()const
		{
			size_t count = 0;
			auto it = cbegin();
			while (it != cend()) ++it, ++count;
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
				for (size_t i = oldsize; i < newsize; ++i)
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
			insert(end(), data);
		}

		void pop_back()
		{
			auto it = end();
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

		
		// 在pos位置插入值为data的元素，返回新插入元素的位置
		iterator insert(iterator pos, const T& data)
		{
			Node* newNode = new Node(data);
			newNode->prev = pos._node->prev;
			newNode->next = pos._node;
			newNode->prev->next = newNode;
			pos._node->prev = newNode;
			return iterator(newNode);
		}

		iterator erase(iterator pos)
		{
			Node* ret = pos._node->next;

			Node* cur = pos._node;
			cur->prev->next = cur->next;
			cur->next->prev = cur->prev;
			delete cur;
			return iterator(ret);
		}

		iterator erase(iterator first, iterator last)
		{
			while (first != last)
			{
				first = erase(first);
			}

			return end();
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