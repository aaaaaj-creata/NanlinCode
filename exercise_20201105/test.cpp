//给出年分m和一年中的第n天，算出第n天是几月几号。
//#include<iostream>
//using namespace std;
//
//static int monthdays[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//
//class Date
//{
//public:
//	//Date(int year, int month, int day)
//	//	:_year(year)
//	//	, _month(month)
//	//	, _day(day)
//	//{
//	//	_year = year;
//	//	_month = month;
//	//	_day = day;
//	//}
//
//	void Getmonth(int year,int days)
//	{
//		int i = 1;
//
//		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
//			monthdays[2] = 29;
//		}
//		else {
//			monthdays[2] = 28;
//		}
//		while (days>monthdays[i])
//		{
//			days = days - monthdays[i];
//			i++;
//		}
//		_month = i;
//		_day = days;
//		_year = year;
//	}
//
//	void Display() {
//
//		printf("%d-%d-%d\n", _year, _month, _day);
//
//	}
//
//private:
//	int _year ;
//	int _month ;
//	int _day ;
//};
//
//int main()
//{
//	int year, days;
//	while (cin >> year >> days)
//	{
//		Date d;
//		d.Getmonth(year, days);
//		d.Display();
//	}
//}
//

//日期差值
//#include<iostream>
//using namespace std;
//
//class Date
//{
//public:
//	Date(int year, int month, int day) 
//	{
//		if (month > 0 && month <= 12 && day > 0 && day < Getmonthday(year, month)) {
//			_year = year;
//			_month = month;
//			_day = day;
//		}
//		else
//		{
//			cout << "非法日期" << endl;
//		}
//	}
//	int Getmonthday(int year, int  month) {
//
//		int monthday[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
//			monthday[2] = 29;
//		}
//		return monthday[month];
//	}
//
//	int getdays(int year, int month, int day)
//	{
//		int days;
//		days = year * 365 + year / 4 - year / 100 + year / 400;
//		for (int i = 1; i < month; i++)
//		{
//			days += Getmonthday(year, i);
//		}
//		days = days + day;
//
//		return days;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	int date1,year1, month1, day1,days1;
//	int date2, year2, month2, day2,days2;
//	int num,temp;
//	while (cin >> date1>> date2)
//	{
//		if (date2 >= date1)
//		{
//			temp = date1;
//			date1 = date2;
//			date2 = temp;
//		}
//		year1 = date1 / 10000, month1 = date1 % 10000 / 100, day1 = date1 % 100;
//		year2 = date2 / 10000, month2 = date2 % 10000 / 100, day2 = date2 % 100;
//		Date d1(year1, month1, day1);
//		Date d2(year2, month2, day2);
//		num = d1.getdays(year1, month1, day1) - d2.getdays(year2, month2, day2)+1;
//		cout << num <<endl;
//	}
//	return 0;
//}

//计算一年的第几天
#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year, int month, int day) 
		:_year(year)
		,_month(month)
		,_day(day)
	{
		if (month > 0 && month <= 12 && day > 0 && day < Getmonthday(year, month)) {
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "非法日期" << endl;
		}
	}
	int Getmonthday(int year, int  month) {

		int monthday[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
			monthday[2] = 29;
		}
		return monthday[month];
	}

	int getdays(int year, int month, int day)
	{
		int days=0;
		for (int i = 1; i < month; i++)
		{
			days += Getmonthday(year, i);
		}
		days = days + day;

		return days;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	int year, month, day;
	while (cin >> year>> month>> day)
	{
		Date d(year, month, day);

		cout << d.getdays(year, month, day) <<endl;
	}
	return 0;
}

