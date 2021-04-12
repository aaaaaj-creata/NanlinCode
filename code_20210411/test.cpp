#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string duplicate(string str)
{
	if (str.size() < 2)
		return str;
	string tmp_str("\0");
	tmp_str += str[0];
	string::size_type j;
	for (string::size_type i = 1; i < str.size(); i++)
	{
		for (j = 0; j < tmp_str.size(); j++)
		{
			if (tmp_str[j] == str[i])
				break;
		}
		if (j == tmp_str.size())
			tmp_str += str[i];
	}
	return tmp_str;
}


void func(string str1)
{
	string str;
	str = duplicate(str1);
	vector<char> Astr ;
	vector<char> astr ;
	vector<char> num ;
	for(int i = 0; i < str.size(); i++)
	{
		if (isdigit(str[i]))
		{
			num.push_back(str[i]);
		}
		if ('A' <= str[i] && str[i] <= 'Z')
		{
			Astr.push_back(str[i]);
		}
		if ('a' <= str[i] && str[i] <= 'z')
		{
			astr.push_back(str[i]);
		}
	}
	sort(num.begin(), num.end());
	sort(Astr.begin(), Astr.end());
	sort(astr.begin(), astr.end());
	for (auto e : astr)
	{
		cout << e;
	}
	cout << ',';
	for (auto e : Astr)
	{
		cout << e;
	}
	cout << ',';
	for (auto e : num)
	{
		cout << e;
	}
}

int main()
{
	string str;
	getline(cin, str);
	func(str);
	return 0;
}