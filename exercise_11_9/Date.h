#include<iostream>//头文件的声明
using namespace std; //c++作用域声明
class Date
{
	friend std::ostream& operator<<(std::ostream&, Date&);//重载输出
	friend std::istream& operator>>(std::istream&, Date&); //重载输入
public:
	Date();//空的构造函数
	Date(int y, int m, int d);
	void setDate(int y, int m, int d);
	int getyear()
	{
		return year;
	}
	void addDay();
	void subtractDay();
	void print();
private:
	int year;
	int day;
	int month;

};

