#include<iostream>
#include<iomanip>//设置宽度的头文件
#include"Date.h"
using namespace std;
Date::Date()
{

}
Date::Date(int y, int m, int d)
{
	setDate(y, m, d);
}
void Date::setDate(int y, int m, int d)
{
	if (y >= 0)
		year = y;
	else
		year = -y;
	if (m >= 1 && m <= 12)
		month = m;
	else
	{
		cout << "请重新输入月！" << endl;
		cin >> m;
		while (!m)
		{
			cout << "请重新输入月！" << endl;
			cin >> m;
		}
		month = m;
	}

	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
	{
		if (d >= 1 && d <= 31)
			day = d;
		else
		{
			cout << "请重新输入日！" << endl;
			cin >> d;
			while (!d)
			{
				cout << "请重新输入日！" << endl;
				cin >> d;
			}
			day = d;
		}
	}
	if (m == 4 || m == 6 || m == 9 || m == 11)
	{
		if (d >= 1 && d <= 30)
			day = d;
		else
		{
			cout << "请重新输入日！" << endl;
			cin >> d;
			while (!d)
			{
				cout << "请重新输入日！" << endl;
				cin >> d;
			}
			day = d;
		}
	}
	if (m == 2)
	{
		if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
		{
			if (d >= 1 && d <= 29)
				day = d;
			else
			{
				cout << "请重新输入日";
				cin >> d;
				while (!d)
				{
					cout << "请重新输入日！";
					cin >> d;
				}
				day = d;
			}
		}
		else
		{
			if (d >= 1 && d <= 28)
				day = d;
			else
			{
				cout << "请重新输入日";
				cin >> d;
				while (!d)
				{
					cout << "请重新输入日！";
					cin >> d;
				}
				day = d;
			}
		}

	}
}


ostream& operator<<(ostream& output, Date& d)
{
	output << d.year << " " << d.month << " " << d.day;
	return output;
}

istream& operator>>(istream& input, Date& d)
{
	input >> d.year >> d.month >> d.day;
	d.setDate(d.year, d.month, d.day);
	return input;
}

void Date::print()
{
	cout << year << " " << month << " " << day << " ";
}
Staff类：
	Staff.h
#ifndef STAFF_H
#define STAFF_H

#include<iostream>
#include<string>
#include"Date.h"//用到了Date的对象

using namespace std;
class Staff
{
	friend std::ostream& operator<<(std::ostream&, Staff&);
	friend std::istream& operator>>(std::istream&, Staff&);
public:
	Staff();
	Staff(string, string, string, string, Date&);
	void setSNB(string);//Set函数
	string getSNB();
	void setSex(string);
	string getSex();
	void setName(string);
	string getName();
	void setPo(string);
	string getPo();
	void setBD(Date&);
	void setAge(Date& bd)
	{
		age = 2018 - (bd.getyear());
	}
	int getAge()
	{
		return age;
	}
	virtual void display();
protected:
	string sNumber;//编号
	string sex;//性别
	string name;//姓名
	string position;//岗位
	int age;//年龄
	Date bird;//出生日期


};
#endif
	Staff.cpp
#include<iostream>
#include<string>
#include"Staff.h"
#include <fstream>//文件的头文件
#include<string>
#include<vector>
#include<iterator> //初始化迭代器要用到
#include<functional>
#include<algorithm>
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

Staff::Staff()
{
}
Staff::Staff(string snb, string x, string nm, string gw, Date& bd)
	:bird(bd)
{
	setSNB(snb);
	setSex(x);
	setName(nm);
	setPo(gw);
	setBD(bd);
}
ostream& operator<<(ostream& output, Staff& s)
{
	output << "职工号:" << s.sNumber << endl << "姓名:" << s.name << endl << "性别:" << s.sex << endl
		<< "岗位:" << s.position << endl << "出生日期:" << s.bird << endl
		<< "年龄:" << s.age << endl;
	return output;
}
istream& operator>>(istream& input, Staff& s)
{
	cout << "职工号:"; input >> s.sNumber;
	cout << "姓名:"; input >> s.name;
	cout << "性别:"; input >> s.sex; s.setSex(s.sex);
	cout << "岗位:"; input >> s.position;
	cout << "出生日期:"; input >> s.bird; s.setAge(s.bird);
	return input;
}
void Staff::setSNB(string snb)
{
	sNumber = snb;
}
void Staff::setSex(string x)
{
	while (x != "man" && x != "woman" && x != "男" && x != "女")
	{
		cout << "性别输入有误！请重新输入:";
		cin >> x;
	}
	sex = x;
}
void Staff::setName(string nm)
{
	name = nm;
}
void Staff::setPo(string gw)
{
	position = gw;
}
void Staff::setBD(Date& bd)
{
	bird = bd;
}
string Staff::getSNB()
{
	return sNumber;
}
string Staff::getSex()
{
	return sex;
}
string Staff::getName()
{
	return name;
}
string Staff::getPo()
{
	return position;
}

void Staff::display()
{
	cout << "职工号:" << sNumber << endl << "姓名:" << name << endl << "性别:" << sex << endl
		<< "岗位:" << position << endl << "出生日期:" << bird << endl
		<< "年龄:" << age << endl;
}
Teacher类：
Teacher.H
#ifndef TEACHER_H
#define TEACHER_H

#include<iostream>
#include<string>
#include"Staff.h"

using namespace std;

class Teacher :public Staff
{
	friend std::ostream& operator<<(std::ostream&, Teacher&);
	friend std::istream& operator>>(std::istream&, Teacher&);
public:
	Teacher();
	Teacher(string, string, string, string, Date&, string, string);
	void setZhiWu(string);
	string getZhiWu();
	void setsa(string);
	int getsa()
	{
		return salary;
	}
	void display();
private:
	string zhicheng;
	string system;
	int salary;
};
#endif  
	Teacher.cpp
#include<iostream>
#include<string>
#include"Teacher.h"

using namespace std;
Teacher::Teacher()
{
}
Teacher::Teacher(string snb, string x, string nm, string gw, Date& bd, string zw, string syst)
	:Staff(snb, x, nm, gw, bd)
{
	setZhiWu(zw);
	system = syst;
	setsa(zw);

}
ostream& operator<<(ostream& output, Teacher& m)
{
	output << "职工号:" << m.sNumber << endl << "姓名:" << m.name << endl << "性别:" << m.sex << endl
		<< endl << "岗位:" << m.position << endl << "出生日期:" << m.bird << endl << "年龄:" << m.age << endl
		<< "职称:" << m.zhicheng << endl << "所在系:" << m.system << endl << "工资:" << m.salary << endl << endl << endl;
	return output;
}
istream& operator>>(istream& input, Teacher& m)
{
	cout << "职工号:"; input >> m.sNumber;
	cout << "姓名:"; input >> m.name;
	cout << "性别:"; input >> m.sex; m.setSex(m.sex);
	cout << "岗位:"; input >> m.position;
	cout << "所在系:"; input >> m.system;
	cout << "职称:"; input >> m.zhicheng; m.setsa(m.zhicheng);
	cout << "出生日期:"; input >> m.bird; m.setAge(m.bird);
	return input;
}
void Teacher::setZhiWu(string zw)
{
	zhicheng = zw;
}
void Teacher::setsa(string zhicheng)
{
	if (zhicheng == "正高级教师")
		salary = 100000;
	if (zhicheng == "高级教师")
		salary = 10000;
	if (zhicheng == "一级教师")
		salary = 8000;
	if (zhicheng == "二级教师")
		salary = 6000;
	if (zhicheng == "三级教师")
		salary = 4000;
}
string Teacher::getZhiWu()
{
	return zhicheng;
}
void Teacher::display()
{
	Staff::display();
	cout << "职务:" << zhicheng << endl;
	cout << "所在系:" << system << endl;
	cout << "工资:" << salary << endl;
}
Worker类：
	Worker.h
#ifndef WORKER_H
#define WORKER_H

#include<iostream>
#include<string>
#include"Staff.h"

using namespace std;

class Worker :public Staff
{
	friend std::ostream& operator<<(std::ostream&, Worker&);
	friend std::istream& operator>>(std::istream&, Worker&);
public:
	Worker();
	Worker(string, string, string, string, Date&, string, string);
	void setTech(string);
	string getTech();
	void display();
private:
	string Tech;
	string bumen;
	int salary;
};

#endif  
	Worker.cpp
#include<iostream>
#include<string>
#include"Worker.h"

using namespace std;
Worker::Worker()
{
}
Worker::Worker(string snb, string x, string nm, string gw, Date & bd, string b, string Tec)
	:Staff(snb, x, nm, gw, bd)
{
	setTech(Tec);
	bumen = b;
}
ostream& operator<<(ostream & output, Worker & e)
{
	output << "职工号:" << e.sNumber << endl << "姓名:" << e.name << endl << "性别:" << e.sex << endl
		<< "部门:" << e.bumen << endl << "岗位:" << e.position << endl << "出生日期:" << e.bird << endl
		<< "年龄:" << e.age << endl << "部门:" << e.bumen << endl << "技术等级:" << e.Tech << endl
		<< "工资:" << e.salary << endl << endl << endl;
	return output;
}
istream& operator>>(istream & input, Worker & e)
{
	cout << "职工号:"; input >> e.sNumber;
	cout << "姓名:"; input >> e.name;
	cout << "性别:"; input >> e.sex; e.setSex(e.sex);
	cout << "部门:"; input >> e.bumen;
	cout << "岗位:"; input >> e.position;
	cout << "出生日期:"; input >> e.bird; e.setAge(e.bird);
	cout << "技术等级:"; input >> e.Tech; e.setTech(e.Tech);
	return input;
}
void Worker::setTech(string de)
{
	Tech = de;
	if (Tech == "高级技师")
		salary = 100000;
	if (Tech == "2级技师")
		salary = 10000;
	if (Tech == "3级高级工")
		salary = 8000;
	if (Tech == "4级中级工")
		salary = 6000;
	if (Tech == "5级初级工")
		salary = 4000;
}
string Worker::getTech()
{
	return Tech;
}
void Worker::display()
{
	Staff::display();
	cout << "部门:" << bumen << endl;
	cout << "技术等级:" << Tech << endl;
	cout << "工资:" << salary << endl;
}


Manager类和主函数：
	main.cpp
#include <iostream>
#include <fstream>
#include<string>
#include<vector>
#include<iterator> 
#include<functional>
#include<algorithm>
#include <iostream>
#include <cstdlib>
#include <iomanip>
# include <conio.h>
using namespace std;

#include"Staff.h"
#include"Worker.h"
#include"Teacher.h"
void menu()
{
	cout << "        ---------欢迎来到西安财经大学教职工系统-------" << endl << endl
		<< "			0-初始化员工文本信息" << endl
		<< "			1-增加一名职工" << endl
		<< "			2-显示全部职工" << endl
		<< "			3-修改员工信息" << endl
		<< "			4-计算平均年龄" << endl
		<< "			5-删除一名职工" << endl
		<< "			6-按员工姓名检索职工" << endl
		<< "			7-结束程序运行" << endl << endl
		<< "        ---------欢迎来到西安财经大学教职工系统-------" << endl << endl << endl;
	cout << "**************************************************************" << endl
		<< "温馨提示:您可以输入0来初始化文件信息并查看" << endl
		<< "         但您如果想要测试1-6的功能程序，必须先添加一定数量的员工信息，所以建议您先选择1" << endl
		<< "*************************************************************" << endl << endl;
}
void staffType()
{
	cout << "			1-Worker" << endl;
	cout << "			2-Teacher" << endl;
}
void change()
{
	cout << "选择你要修改的员工类型" << endl;
	cout << "			1-Worker" << endl;
	cout << "			2-Teacher" << endl;
}
void insert()
{
	cout << "		        1-增加一名Worker" << endl
		<< "			    2-增加一名Teacher:" << endl << endl << endl;
}
void delete1()
{
	cout << "		1-删除一名Worker" << endl
		<< "			2-删除一名Teacher" << endl << endl << endl;
}
//查找
//返回值为下标，形参为一个迭代器对象引用，一个字符串
int search(vector<Worker> & a, string n)
{
	int i = 0;
	vector<Worker>::iterator ptr;//迭代器的初始化
	for (ptr = a.begin(); ptr != a.end(); ++ptr)//从迭代器的开始到结尾遍历
	{
		++i;
		if ((*ptr).getName() == n)
			return i;//找到了则返回下标
	}
	cout << "所查找的职工不存在！" << endl;
	return -1;
}
int search(vector<Teacher> & a, string n)//类似于Worker
{
	int i = 0;
	vector<Teacher>::iterator ptr;
	for (ptr = a.begin(); ptr != a.end(); ++ptr)
	{
		++i;
		if ((*ptr).getName() == n)
			return i;
	}
	cout << "所查找的职工不存在！" << endl;
	return -1;
}
//遍历迭代器函数模板
template<typename T>//声明
void print(vector<T> & a)//为一个返回值为void，形参为迭代器对象引用
{
	typename vector<T>::iterator ptr;//初始化
	for (ptr = a.begin(); ptr != a.end(); ++ptr)
		cout << *ptr;//循环输出
}
//输出一个迭代器对象模板
template<typename T>//模板声明
void printOne(vector<T> & a, int n)//返回值为无类型，形参为一个迭代器对象引用，一个为指定位置输出
{
	typename vector<T>::iterator ptr;
	cout << *ptr;//输出指定位置的值
}
//文件的打开，写入和读取
void wrea()
{
	cout << "-----------------往文本里录入员工的信息----------------" << endl;
	int number;//定义对象的个数
	fstream outDate;//定义一个文件对象
	outDate.open("Staff.txt", ios::out | ios::binary | ios::in);//指定了文件的打开方式
	if (!outDate)//判断是否打开失败
	{
		cerr << "File could not open." << endl;
		exit(EXIT_FAILURE);
	}
	cout << "请输入要存放的职工人数" << endl;//打开成功，则输入你要存放的数据个数
	Staff d1;
	cin >> number;
	vector<Staff> vec1;//定义两个迭代器对象这个用来存放数据
	vector<Staff> vec2;//这个用来输出数据
	for (int i = 0; i < number; i++)//先将数据存放入迭代器中，使用尾插法
	{
		cout << "请输入职工的相关信息" << endl;
		cin >> d1;//重载过后的>>
		vec1.push_back(d1);//尾插法
	}
	for (int i = 0; i < vec1.size(); i++)//在把迭代器里的数据写进文件里面去
	{
		d1 = vec1[i];
		outDate.write((char*)(&d1), sizeof(Staff));//每次写一个Staff对象	
	}
	outDate.close();//关闭文件
	cout << "---------------------录入完毕-------------------------" << endl << endl;
	cout << "---------------------文本信息显示-------------------------" << endl << endl;
	ifstream inDate;
	inDate.open("Staff.txt", ios::in | ios::binary);//定义了打开方式
	if (!inDate)//判断
	{
		cerr << "File could not open." << endl;
		exit(EXIT_FAILURE);
	}
	cout << "职工文本信息显示:" << endl;
	inDate.read((char*)(&d1), sizeof(Staff));//从文件里面把数据读出来
	while (inDate && !inDate.eof())//读出来放到迭代器里面
	{

		vec2.push_back(d1);
		inDate.read((char*)(&d1), sizeof(Staff));

	}
	inDate.close();//关闭文件

	for (int i = 0; i < vec2.size(); i++)//输出迭代器的每个数据
	{
		cout << vec2[i] << endl;
	}
}
int main()
{
	cout << endl;
	system("color 0f");
	int nl = 0, n2 = 0; string str;//n1表示保存工人的平均年龄，n2表示教师的平均年龄，str用来存放要查找的姓名
	vector<Staff>::iterator ptr1;//对于Staff迭代器的初始化
	vector<Worker>employees;//定义一个迭代器,存放Worker的信息
	vector<Worker>::iterator ptr2;//对于Worker迭代器的初始化
	vector<Teacher>managers;//定义一个迭代器。存放Teacher的信息
	vector<Teacher>::iterator ptr3;//对于Teacher迭代器的初始化 
	Staff s; Worker e; Teacher m;//定义了三个对象
	while (1)
	{
		menu();
		int q;
		cout << "请选择您要执行的操作:" << endl;
		cin >> q;
		switch (q)
		{
		case 0:
			wrea();
			break;
		case 1://添加职工信息
			system("color 1f");
			insert();
			cout << "请选择您要添加的职工类型:" << endl;
			cin >> q;
			switch (q)//选择添加教师信息或者工人信息
			{
			case 1:
				cin >> e;//输入相关信息
				employees.push_back(e);//给工人的迭代器employees里面尾插对象
				break;
			case 2:
				cin >> m;
				managers.push_back(m);//给教师的迭代器employees里面尾插对象
				break;
			default:
				cout << "输入有误！请重新输入选项：";
				cin >> q;
				break;
			}
			break;
		case 2:
			system("color 2f");
			cout << "Worker:" << endl << endl << endl;
			print(employees);//调用打印函数，打印出所有的信息，上面已经对此函数进行的解释
			cout << "Teacher:" << endl << endl << endl;
			print(managers);
			break;
		case 3:
			system("color 3f");
			change();
			cin >> str;
			if (str == "1")
			{
				cout << "请输入所要修改的工人的姓名:" << endl;
				cin >> str;
				if (search(employees, str) != -1)//先查找到这个员工
				{
					employees.erase(employees.begin() + search(employees, str) - 1);//再将它删除
					cout << "请输入此工人更改过后的信息" << endl;
					cin >> e;
					employees.push_back(e);//在重新输入员工的所有信息
					cout << "修改成功!" << endl;
				}
			}
			else if (str == "2")
			{
				cout << "请输入所要修改老师的姓名:" << endl;
				cin >> str;
				if (search(managers, str) != -1)//同理，一样的步骤
				{
					managers.erase(managers.begin() + search(managers, str) - 1);
					cin >> m;
					managers.push_back(m);
					cout << "修改成功!" << endl;
				}
			}
			else
				cout << "没有此员工类型!" << endl;
			break;
		case 4:
			system("color 4f");
			cout << setw(40) << "1-求老师的平均年龄" << endl;//选择选项
			cout << setw(40) << "2-求工人的平均年龄" << endl;
			int i;
			cin >> i;
			if (i == 2)
			{
				for (ptr2 = employees.begin(); ptr2 != employees.end(); ++ptr2)//遍历整个迭代器
					nl += (*ptr2).getAge();//将全部的年龄累加
				cout << setw(40) << "工人的平均年龄:" << nl / (employees.size()) << endl;//累加的总数除以对象的个数
			}
			if (i == 1)
			{
				for (ptr3 = managers.begin(); ptr3 != managers.end(); ++ptr3)//遍历整个迭代器
					n2 += (*ptr3).getAge();//将全部的年龄累加
				cout << setw(40) << "老师的平均年龄:" << n2 / (managers.size()) << endl;//累加的总数除以对象的个数
			}
			break;
		case 5:
			system("color 5f");
			delete1();
			cout << "请输入所要删除员工的员工类型:" << endl;
			cin >> str;
			if (str == "1")
			{
				cout << "请输入所要删除员工的姓名:" << endl;
				cin >> str;
				if (search(employees, str) != -1)
				{
					employees.erase(employees.begin() + search(employees, str) - 1);
					cout << "删除成功!" << endl;
				}
			}
			else if (str == "2")
			{
				cout << "请输入所要删除老师的姓名:" << endl;
				cin >> str;
				if (search(managers, str) != -1)
				{
					managers.erase(managers.begin() + search(managers, str) - 1);
					cout << "删除成功!" << endl;
				}
			}
			else
				cout << "没有此员工类型!" << endl;
			break;
		case 6:
			system("color 6f");
			cout << "请输入所要查找的员工类型:" << endl;
			staffType();//输出职工的类型
			cin >> str;
			if (str == "1")
			{
				cout << "请输入所查找员工姓名:" << endl;
				cin >> str;
				if (search(employees, str) != -1)//找到这个元素
				{
					cout << "查找成功！" << endl;
					printOne(employees, search(employees, str));//将这个元素的所对应的对象信息输出
				}
			}
			else if (str == "2")
			{
				cout << "请输入所查找员工姓名:" << endl;
				cin >> str;
				if (search(managers, str) != -1)//找到这个元素
				{
					cout << "查找成功！" << endl;
					printOne(managers, search(managers, str));//将这个元素的所对应的对象信息输出
				}
			}
			else
				cout << "没有此员工类型!" << endl;
			break;
		case 7:
			system("color Df");
			cout << "**************************************************************" << endl;
			cout << "                    欢迎下次使用                              " << endl;
			cout << "                  ^^__^^再见^^__^^                             " << endl;
			cout << "*************************************************************" << endl << endl;
			return 0;
		default:
			cout << "输入有误！请重新输入选项：";
			cin >> q;
			break;

		}
	}
	return 0;
}
