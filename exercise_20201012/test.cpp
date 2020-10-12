class Date
{
public:
	// 成员函数在类内实现，编译器可能会将其当成内联函数来处理
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// 拷贝构造函数
	//Date(const Date& d)
	//{
	//	_year = d._year;
	//	_month = d._month;
	//	_day = d._day;

	//	cout << "Date(Date&):" << this << endl;
	//}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d0;
	Date d1(2020, 10, 12);
	Date d2(d1);

	int a;
	int b = 10;
	int c = b;
	int d(c);

	return 0;
}
#endif


#if 0
// 注意：如果类中涉及到资源管理时，该类必须要显式提供析构函数，
//      在析构函数中将对象的资源释放掉
//      否则：资源泄漏了

// 注意：编译器生成的默认拷贝构造函数是按照浅拷贝方式实现的
// 浅拷贝：将一个对象中的内容原封不动的拷贝到另一个对象中
// 后果：多个对象共享同一份资源，最终在对象销毁时该份资源被释放多次而引起代码崩溃

// Date类的拷贝构造函数是否实现没有任何影响
// 但是String的拷贝构造函数不实现不可以---因为编译器生成的默认拷贝构造函数是按照浅拷贝的方式实现的

// 注意：一个类中如果涉及到资源管理时，拷贝构造函数是必须要实现的
class String
{
public:
	String(const char* str = "")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}


	// String类没有实现自己的拷贝构造函数，则编译器会生成一份
	~String()
	{
		if (_str)
		{
			free(_str);
			_str = nullptr;
		}
	}
private:
	char* _str;
};


void TestString()
{
	String s1("hello world");
	String s2(s1);
}


int main()
{
	TestString();
	return 0;
}
#endif

#if 0
class Date
{
public:
	// 成员函数在类内实现，编译器可能会将其当成内联函数来处理
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// 拷贝构造函数
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		cout << "Date(Date&):" << this << endl;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d0;
	Date d1(2020, 10, 12);
	Date d2(d1);
	Date d3(2020, 10, 13);

	// 调用赋值运算符重载函数
	// 如果一个类没有显式实现赋值运算符重载函数，则编译器会生成一份默认的
	// 完成对象之间的赋值操作
	d1 = d3;

	int a = 10;
	int b = 20;
	a = b;

	return 0;
}
#endif

#if 0
// 如果类中涉及到资源管理时，赋值运算符重载函数必须要显式实现出来
class String
{
public:
	String(const char* str = "")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	String(const String & s)
	{
		cout << "String(const String& s):" << this << endl;
	}


	// String类没有实现自己的拷贝构造函数，则编译器会生成一份
	~String()
	{
		if (_str)
		{
			free(_str);
			_str = nullptr;
		}
	}
private:
	char* _str;
};


void TestString()
{
	String s1("hello");
	String s2("world");

	// 调用拷贝构造，构造一个新对象s3
	String s3(s2);

	// 拷贝构造构造
	String s4 = s3;

	// 编译器生成的赋值运算符重载是按照浅拷贝的方式实现的
	// 如果类中涉及到资源管理时，会导致以下两个后果：
	// 存在两个后果：
	// 1. 浅拷贝：造成后果一份资源释放多次引起代码崩溃
	// 2. s1原来的空间丢失了--内存泄漏
	s1 = s2;
}

int main()
{
	TestString();
	return 0;
}
#endif


class Date
{
public:
	// 成员函数在类内实现，编译器可能会将其当成内联函数来处理
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	// 拷贝构造函数
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;

		cout << "Date(Date&):" << this << endl;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	bool IsLess(const Date& d)
	{
		if ((_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day))
		{
			return true;
		}

		return false;
	}

	// 对于自定义类型，编译器不知道如何进行响应运算符的操作
	// 因此需要对该运算符进行重载，相当于告诉编译器针对该中类型的对象如何进行此运算符操作
	bool operator<(const Date& d)
	{
		if ((_year < d._year) ||
			(_year == d._year && _month < d._month) ||
			(_year == d._year && _month == d._month && _day < d._day))
		{
			return true;
		}

		return false;
	}

	// ==
	bool operator==(/*Date* const this, */const Date& d)
	{
		return _year == d._year &&
			_month == d._month &&
			_day == d._day;
	}

	bool operator!=(const Date& d)
	{
		return !(*this == d);
	}

	// 注意：不能臆造运算符来进行重载
	//void operator@()
	//{

	//}

	Date& operator+=(int days)
	{
		//Date temp(*this);
		//temp._day += days;
		//return temp;
		_day += days;
		return *this;
	}

	Date operator+(int days)
	{
		Date temp(*this);
		temp._day += days;
		return temp;
	}

private:
	int _year;
	int _month;
	int _day;
};

enum Data
{
	ONE, TWO, THREE
};

//int operator+(Data a, int b)
//{
//	return a + b;
//}

int main()
{
	Date d1(2020, 10, 12);
	Date d2(2020, 10, 13);

	int a = 10;
	int b = 20;
	if (a < b)
	{
		cout << "a < b" << endl;
	}
	else
	{
		cout << "a >= b" << endl;
	}

	if (d1 < d2)
	{
		cout << "d1 < d2" << endl;
	}
	else
	{
		cout << "d1 >= d2" << endl;
	}

	if (d1.IsLess(d2))
	{
		cout << "d1 < d2" << endl;
	}
	else
	{
		cout << "d1 >= d2" << endl;
	}

	if (d1 != d2)
	{
		cout << "d1 != d2" << endl;
	}
	else
	{
		cout << "d1 == d2" << endl;
	}

	a + 10;
	d1 += 10;

	d2 = d1 + 2;
	return 0;
}
