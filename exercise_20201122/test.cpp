//给定一个整数数组nums，其中恰好有两个元素只出现一次
//其余所有元素均出现两次。找出只出现一次的那两个元素
//#include<iostream>
//#include<vector>
//using namespace std;
//
//class Solution {
//public:
//	vector<int> singleNumber(vector<int>& nums) 
//	{
//		
//	}
//};

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	int n = 0;
	int sum = 0;
	long long num = 0;
	vector<int> s;
	cin >> n;
	s.reserve(3 * n);
	for (int i = 0; i < (3 * n); i++)
	{
		cin >> num;
		s.push_back(num);
	}
	sort(s.begin(), s.end());
	for (int j = n; j <= (3 * n) - 2; j += 2)
	{
		sum += s[j];
	}
	cout << sum << endl;
	return 0;
}

//int main()
//{
//	string s1,s2;
//	int index = 0;
//	getline(cin,s1);
//	getline(cin,s2);
//	for (int i = 0; i < s2.size(); i++)
//	{
//		while ((index = s1.find(s2[i])) != -1)
//		{
//			s1.erase(index, 1);
//		}
//	}
//
//	cout << s1 << endl;
//	return 0;
//}