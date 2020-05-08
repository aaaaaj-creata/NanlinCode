#include<iostream>
using namespace std;

class Test {
public:    
	Test() 
		: _data(0) 
	{ 
		cout << "Test():" << this << endl; 
	}

	~Test() 
	{ 
		cout << "~Test():" << this << endl; 
	}

private:    
	int _data;
};

void Test2() {    
	// 申请单个Test类型的空间    
	Test* p1 = (Test*)malloc(sizeof(Test));    
	free(p1);        
	// 申请10个Test类型的空间    
	Test* p2 = (Test*)malloc(sizoef(Test) * 10);    
	free(p2); 
}

void Test2() {    
	// 申请单个Test类型的对象    
	Test* p1 = new Test;    
	delete p1;        
	// 申请10个Test类型的对象    
	Test* p2 = new Test[10];    
	delete[] p2; 
}
