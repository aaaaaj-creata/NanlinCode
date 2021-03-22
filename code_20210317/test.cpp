//找出一个字符串的最大重复子串 
#include <iostream>
#include <string>
using namespace std;

string maxlist(string arr)
{
	int max = 0;
	string res;
	string temp;//临时保存重复子串
	//找重复子串
	for (int i = 0; i < arr.size(); i++)
	{
		for (int j = 0; j < arr.size(); j++)
		{
			
		}
	}
	//用一个max来保存子串的长度
	if (temp.size() > max)
	{
		max = temp.size();
		res = temp;
	}
	temp = "";

	return res;
}

int main()
{
	string arr;
	cin >> arr;
	string res = maxlist(arr);
	cout << res << endl;
	return 0;
}