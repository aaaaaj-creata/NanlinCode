#include <iostream>
using namespace std;


#if 0

int main()
{
	int* p = (int*)malloc(sizeof(int) * 10);

	realloc(p, 100);
	return 0;
}
#endif


#if 0
#include <iostream>
using namespace std;
int main()
{
	void* p = new char[0xfffffffful];
	cout << "new:" << p << endl;
	return 0;
}
#endif

#if 0
//注意：函数模板并不是真正的函数
// 而是用户告诉给编译器生成代码的规则
template<class T>
T Add(T left, T right)
{
	cout << typeid(T).name() << endl;
	return left + right;
}


/*
函数模板原理：
1. 隐式实例化：没有明确指定模板参数列表T的实际类型
   在编译器阶段，编译器需要对传递的实参类型进行推演，根据
   推演的结果来确定模板参数列表中T的实际类型，
   如果T的类型可以确定，则生成处理具体类型的函数
   如果T的类型无法确定则报错。

2. 显式实例化：明确指定了模板参数列表中T的实际类型
	编译器就会直接根据用户所提供的T的类型来生成
	处理具体类型的函数
	将函数生成之后，如果发现类型匹配，则调用
	如果发现类型不匹配，则会进行隐式类型转化
	如果转化成功，则编译通过
	如果转化失败，则报错
*/
int main()
{
	// 隐式实例化
	Add(1, 2);   // Add<int>
	Add(1.0, 2.0); // Add<double>
	Add('1', '2'); // Add<char>
	Add(1, (int)2.0); //Add<int> // 1-->int  2.0-->double

	// 显式实例化
	Add<int>(1, 2.0);
	// Add<int>(1, "123"); 编译失败
	return 0;
}
#endif


#if 0
template<class T1, typename T2>
T2 Add(T1 left, T2 right)
{
	return left + right;
}

int main()
{
	Add(1, 2.0);
	Add(1, 2);
	return 0;
}
#endif

#if 0
template<class T>
T Add(T left, T right)
{
	return left + right;
}

int Add(int left, int right)
{
	return left + right;
}

int main()
{
	Add(1, 2);

	Add<int>(1, 2);
	Add<>(1, 2);  //隐式实例化
	return 0;
}
#endif


int Add(int left, int right)
{
	return left + right;
}


template<class T1, typename T2>
T2 Add(T1 left, T2 right)
{
	return left + right;
}

int main()
{
	Add(1, 2);
	Add(1, 2.0);
	return 0;
}
