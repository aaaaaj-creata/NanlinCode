#include<iostream>
using namespace std;

void f(int)
{
	cout << "f(int)" << endl;
}

void f(int*)
{
	cout << "f(int*)" << endl;

}

int main()
{
	//f(0);
	//f(NULL);
	//f((int*)NULL);
	//f(nullptr);
	cout << typeid(nullptr).name() << endl;
	return 0;
}