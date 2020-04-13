#include <iostream>
using namespace std;

// 只能在堆上
class HeapOnly
{
public:
	static HeapOnly* GetHeapObj()
	{
		HeapOnly* p = new HeapOnly;
		return p;
	}

private:
	HeapOnly()
	{
		cout << "HeapOnly()" << endl;
	}

	// C++98 只声明不实现+声明成私有
	//HeapOnly(const HeapOnly& hp);

	// C++11
	HeapOnly(const HeapOnly& hp) = delete;
};

//class StackOnly
//{
//public:
//	static StackOnly CreateObject()
//	{
//		return StackOnly();
//	}
//private:
//	StackOnly()
//	{}
//};

class StackOnly
{
public:
	StackOnly() {}
private:
	// 定制专属的operator new和delete，但是我不实现，你就没办法new了
	void* operator new(size_t size);
	void operator delete(void* p);
};

// C++98 不能被继承。私有在子类不可见 + 子类的构造函数必须调用父类的构造函数
class NonInherit
{
public:
	static NonInherit GetInstance()
	{
		return NonInherit();
	}
private:
	NonInherit()
	{}
};

class Inherit : public NonInherit  // 借助子类构造函数来设定
{};

//class A  final   // 最终类，不能被继承
//{
//	// ....
//};

//class InheritA : public A
//{
//};


//int main()
//{
//	//HeapOnly hp1;				// 栈
//	//static HeapOnly hp2;		// 数据段
//	//HeapOnly* p = new HeapOnly; // 堆
//
//	HeapOnly* p1 = HeapOnly::GetHeapObj();
//	//HeapOnly copy1(*p1);
//	//static HeapOnly copy2(*p1);
//
//	//StackOnly so = StackOnly::CreateObject();
//	StackOnly so1;
//	//StackOnly* p2 = new StackOnly; // operator new + 构造函数
//
//	//Inherit ih;
//
//
//	return 0;
//}

// 单例（唯一的实例对象）
// 饿汉 -》 一上来就要吃，也就是一开始(main函数之前)就创建对象
//class Singleton
//{
//public:
//	static Singleton& GetInstance()
//	{
//		return _sInst;
//	}
//
//private:
//	// 构造函数私有化
//	Singleton()
//	{}
//
//	Singleton(const Singleton&) = delete;
//
//	static Singleton _sInst;
//};
//
//// 对象在静态区
//Singleton Singleton::_sInst; // main函数之前就创建初始化这个实例对象
//
//int main()
//{
//	cout << &Singleton::GetInstance() << endl;
//	cout << &Singleton::GetInstance() << endl;
//	cout << &Singleton::GetInstance() << endl;
//	cout << &Singleton::GetInstance() << endl;
//
//	// 多线程来调用Singleton::GetInstance()，有没有线程安全的问题？
//	// 没有线程安全的问题，因为实例对象的创建在main函数之前
//
//	return 0;
//}

// 懒汉 -》 拖延症，最后一刻（第一次调用GetInstance时）才去创建对象
#include <vector>
#include <thread>
#include <mutex>

class Singleton
{
public:
	static Singleton& GetInstance()
	{
		// 双检查解锁的效率问题
		if (_spInst == nullptr)
		{
			_smtx.lock();
			if (_spInst == nullptr)
			{
				_spInst = new Singleton;
			}
			_smtx.unlock();
		}

		return *_spInst;
	}

	// 一般没必要释放对象，进程结束以后会释放
	// 但是可以提供主动释放的接口
	static void DelInstace()
	{
		_smtx.lock();
		if (_spInst == nullptr)
		{
			delete _spInst;
			_spInst = nullptr;
		}
		_smtx.unlock();
	}

private:
	// 构造函数私有化
	Singleton()
	{}

	Singleton(const Singleton&) = delete;

	static Singleton* _spInst;
	static mutex _smtx;
};

//class CGarbo
//{
//public:
//	~CGarbo()
//	{
//		Singleton::DelInstace();
//	}
//};
//
//static CGarbo gc;

Singleton* Singleton::_spInst = nullptr; // main函数之前就创建初始化指针
mutex Singleton::_smtx;

// 饿汉
// 优点：实现简洁
// 缺点：在main函数之前初始化实例，如果程序中单例较多，程序启动慢。其次如果两个单例类有依赖关系，无法保证创建初始化实例的顺序。

// 懒汉
// 优点：是在第一次调用初始化创建实例，不影响程序的启动。其次他调用时创建初始化，顺序可以控制
// 缺点：实现相对复杂

//int main()
//{
//	/*cout << &Singleton::GetInstance() << endl;
//	cout << &Singleton::GetInstance() << endl;
//	cout << &Singleton::GetInstance() << endl;
//	cout << &Singleton::GetInstance() << endl;*/
//
//	// 多线程来调用Singleton::GetInstance()，有没有线程安全的问题？
//	// 
//	/*vector<thread> vthreads;
//	for (size_t i = 0; i < 4; ++i)
//	{
//	vthreads.push_back(thread([]()
//	{
//	this_thread::sleep_for(std::chrono::seconds(1));
//	for (size_t i = 0; i < 10; ++i)
//	{
//	cout << &Singleton::GetInstance() << endl;
//	}
//	}));
//	}
//
//	for (auto& e : vthreads)
//	{
//	e.join();
//	}*/
//
//	//volatile const int a = 10;
//	/*const int a = 10;
//	int* p = (int*)&a;
//	*p = 20;
//	cout << a << endl;*/
//
//	//char* p = new char[1024 * 1024 * 1024];
//
//	int i = 1;
//	// 隐式类型转换 
//	double d = static_cast<double>(i); // 相近类型，相关类型-》意义类似的类型之间的转换
//	printf("%d, %.2f\n", i, d);
//
//	int* p = &i;
//	// 显示的强制类型转换
//	int address = reinterpret_cast<int>(p); // 不想关类型的转换
//
//	volatile const int a = 2;
//	int* p1 = const_cast<int*>(&a);  // 去掉const属性的转换
//	*p1 = 3;
//	cout << a << endl;
//
//	return 0;
//}

class A
{
public:
	virtual void f() {}

	int _a;
};

class B : public A
{
	int _b;
};

void fun(A* pa)
{
	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回
	B* pb1 = static_cast<B*>(pa);
	B* pb2 = dynamic_cast<B*>(pa);

	cout << "pb1:" << pb1 << endl;
	cout << "pb2:" << pb2 << endl;
}

int main()
{
	//A* pa = new A;
	//B* pb = new B;
	// 父指针 = 子指针  这个直接就支持的切片，可以不算转换
	//pa = pb;

	// 子指针 = 父指针 这里是需要转换，且一般这样的转换时不合适的，特殊情况下才需要
	// B* p = (B*)pa;  // 这样的转换时不安全

	// dynamic_cast可以用来识别父类指针是指向父类对象还是子类对象
	//A* pa = new A;
	A* pa = new B;
	B* p = dynamic_cast<B*>(pa); // 这样转才是安全，如果pa是指针B类型(子类)的对象的，就可以成功
	cout << p << endl;           //                 如果pa是指针A类型(子类)的对象的，失败，返回NULL

	return 0;
}