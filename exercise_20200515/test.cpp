class person
{
public:
	void show()//声明和定义全部放在类体中
	{
		cout << _name << "-" << _sex << "-" << _age << endl;
	}
public:
	char* _name;
	char* _sex;
	int _age;
};

//person.h文件
class person
{
public:
	void show()
public:
	char* _name;
	char* _sex;
	int _age;
};

//person.cpp
#include"person.h"
void person::show()
{
	cout << _name << "-" << _sex << "-" << _age << endl;
}
