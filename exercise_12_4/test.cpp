#include<iostream>
#include<map>
using namespace std;

//int TestAuto()
//{
//	return 10;
//}

int main()
{
	//std::map<std::string, std::string> dict;
	//std::map<std::string, std::string>::iterator it = dict.begin();
	//auto it = dict.begin();
	//cout << typeid(it).name() << endl;
	//int a = 10;
	//auto b = a; //推导出b为int
	//auto c = 'a'; //推导出c为char
	//auto d = TestAuto(); //和TestAuto返回的类型一样，即int
	//cout << typeid(b).name() << endl;
	//cout << typeid(c).name() << endl;
	//cout << typeid(d).name() << endl;

	//auto e; 无法通过编译，使用auto定义变量时必须对其进行初始化
	//int x = 10;
	//auto a = &x;
	//auto* b = &x;
	//auto& c = x;
	//cout << typeid(a).name() << endl;
	//cout << typeid(b).name() << endl;
	//cout << typeid(c).name() << endl;
	//auto a = 1, b = 2;
	//auto c = 3, d = 4.0; // 该行代码会编译失败，因为c和d的初始化表达式类型不同
	//cout << typeid(a).name() << endl;
	//cout << typeid(b).name() << endl;

		//int array[] = { 1, 2, 3, 4, 5 };

		//for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)//普通循环
		//	array[i] *= 2;

		//for (int* p = array; p < array + sizeof(array) / sizeof(array[0]); ++p)//指针遍历

		//	cout << *p << endl;

		int array[] = { 1, 2, 3, 4, 5 };
		for (auto e : array)//auto& e表示引用，此时e是array的别名，可以进行修改
			e *= 2;
		for (auto e : array)//auto e表示e是a的范围内迭代，不能修改其内容
			cout << e << endl;

	return 0;
}