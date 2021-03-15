#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

//int main()
//{
//	int n = 0;//行
//	int m = 0;//列
//	cin >> n >> m;
//	int max = 0;
//	if (n > m)
//	{
//		max = n;
//	}
//	else
//	{
//		max = m;
//	}
//	vector<vector<int>> arr(max);
//	for (int i = 0; i < arr.size(); i++)
//	{
//		arr[i].resize(max,0);
//	}
//	for (int i = 0; i <n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			int tmp = 0;
//			cin >> tmp;
//			arr[i][j] = tmp;
//		}
//	}
//	//翻转
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			int temp = 0;
//			temp = arr[i][j];
//			arr[i][j] = arr[j][i];
//			arr[j][i] = temp;
//		}
//	}
//	//打印
//	for (int i = 0; i < m; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			cout << arr[i][j] << " ";
//			if (j == m - 1)
//			{
//				cout << endl;
//			}
//		}
//	}
//	return 0;
//}

//int main()
//{
//	string s;
//	string res;
//	vector<int> v;
//	cin >> s;
//	int i = 0;
//	int sum = 0;
//	while (i < s.size())
//	{
//		res = "";
//		while (isdigit(s[i]))
//		{
//			res += s[i];
//			i++;
//		}
//		if (res.size() > 0)
//		{
//			sum = 0;
//			for (int x = 0; x < res.size(); x++)
//			{
//				sum = sum * 10 + (res[x] - '0');
//			}
//			v.push_back(sum);
//		}
//		i++;
//	}
//	sort(v.begin(), v.end());
//	for (auto e : v)
//	{
//		cout << e << endl;
//	}
//	return 0;
//}

//int main()
//{
//	int n = 0, K = 0;
//	vector<int> arr(n,0);
//	cin >> n >> K;
//	int len = n - K + 1;
//	for (int i = 0; i < n; i++)
//	{
//		int tmp = 0;
//		cin >> tmp;
//		arr.push_back(tmp);
//	}
//	vector<int> temp(arr);
//	sort(temp.begin(), temp.end());
//	int max = temp[n - 1];
//	int MAX = 0;
//	vector<int> hash(max,0);
//	for (int i = 0; i < len; i++)
//	{
//		for (int j = 0; j < len; j++)
//		{
//			int dex = arr[j];
//			hash[dex]++;
//		}
//	}
//}
int main()
{
	int n = 0, K = 0;
	vector<int> arr(n, 0);
	cin >> n >> K;
	int len = n - K + 1;
	for (int i = 0; i < n; i++)
	{
		int tmp = 0;
		cin >> tmp;
		arr.push_back(tmp);
	}
	vector<int> tmp(arr);
	sort(tmp.begin(), tmp.end());
	int max = tmp[n - 1];
	//vector<int> hash(max,0);
	vector<int> temp;
	int dex = 0;
	int MAX = 0;
	for (int i = 0; i < len; i++)
	{
		vector<int> hash(max, 0);
		for (int j = i; j < len+i; j++)
		{
			hash[arr[j]]++;		
		}
		for (int x = 0; x < hash.size(); x++)
		{
			MAX = 0;
			if (hash[x] > MAX)
			{
				MAX = hash[x];
				dex = x;
			}
			if (hash[x] = MAX)
			{
				if (dex > x)
				{
					dex = x;
				}
			}
		}
		cout << dex << endl;
		dex = 0;
	}
	return 0;
}