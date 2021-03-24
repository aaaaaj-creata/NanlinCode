#include <iostream>
#include <string>
#include <vector>
using namespace std;
//给定一组词组，每个词组包含id和字符串的映射，现输入另一组词组，要求找出新的词组与老的词组的diff关系，diff要求如下：
//1、id相同且字符串相同的两个词组视为相同
//2、id相同，且字符串不同的输出modify+id
//3、新的词组id在老的词组id中不存在的，视为新增，输出add+id
//4、老的词组id在新的词组id中不存在的，视为删除，输出delete+id
//输入描述
//第一行代表老的词组，第二行代表新的词组
//每一行是id - 字符串的组合，多个词组以逗号分隔
//如：1 - a, 2 - b, 3 - c
//输出描述
//一个字符串，多个结果按字符串排序后（直接使用string的compareTo方法比较大小即可）以逗号分隔，如：add - 2, delete - 22
/*
int func2(string a1, string a2)//比较两个字符串是否相等
{
	int i = 0;
	if (a1.size() != a2.size())
	{
		return 1;
	}
	while (i < a1.size())
	{
		if (a1[i] != a2[i])
		{
			return 1;
		}
		i++;
	}
	return 0;
}

void func(vector<string> arr1, vector<string> arr2)
{
	int len1 = arr1.size(), len2 = arr2.size();
	int min = 0;
	if (len1 > len2)
	{
		min = len2;
	}
	else
	{
		min = len1;
	}
	vector<string> res;
	for (int i = 0; i < min; i++)
	{
		int flag = 0;
		string tmp = "modify-";
		flag = func2(arr1[i], arr2[i]);
		if (flag == 1)
		{
			tmp += (i + 1) + '0';
			res.push_back(tmp);
		}
	}
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i];
		if (i != res.size() - 1 || len1 != len2)
		{
			cout << ",";
		}
	}
	if (len1 > len2)
	{
		for (int i = len2 + 1; i <= len1; i++)
		{
			cout << "delete-" << i;
			if (i != len1)
			{
				cout << ",";
			}
		}
	}
	else
	{
		for (int i = len1 + 1; i <= len2; i++)
		{
			cout << "add-" << i;
			if (i != len2 )
			{
				cout << ",";
			}
		}
	}
}



int main()
{
	string s1;
	cin >> s1;
	string s2;
	cin >> s2;
	vector<string> arr1;
	for (int i = 0; i < s1.size(); i++)
	{
		int start = i;
		string tmp = "";
		while (i < s1.size() && s1[i] != ',' )
		{
			i++;
		}
		tmp = s1.substr(start, i - start);
		arr1.push_back(tmp);
	}
	vector<string> arr2;
	for (int i = 0; i < s2.size(); i++)
	{
		int start = i;
		string tmp = "";
		while (i < s2.size() && s2[i] != ',')
		{
			i++;
		}
		tmp = s2.substr(start, i - start);
		arr2.push_back(tmp);
	}
	func(arr1, arr2);
	return 0;
}

*/

int main()
{
	int n = 0;
	cin >> n;
	vector<vector<int>> arr(n);
	for (int i = 0; i < n; i++)
	{
		arr[i].resize(2);
		scanf_s("%d,%d", &arr[i][0], &arr[i][1]);
	}
	int time = 0;
	int in = 0;//开始
	int out = 0;//结束
	for (int i = 0; i < n; i++)
	{
		if (arr[i][0] >= out)
		{
			in = arr[i][0];
			out = in + arr[i][1];
			time += (out - in);
		}
		else
		{
			in = out;
			out = in + arr[i][1];
			time += (out - arr[i][0]);
		}
	}
	cout << time << endl;
	return 0;
}