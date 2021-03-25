#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//int foodsum(vector<int>& foods, int m, vector<int>& sum)
//{
//	vector<int> res(m + 1);
//	res[0] = 0;
//	for (int i = 0; i <= m; i++)
//	{
//		res[i] = INT_MAX;
//		for (int j = 0; j < foods.size(); j++)
//		{
//			if (i >= foods[j] && res[i - foods[j]] != INT_MAX)
//			{
//				res[i] = min(res[i - foods[j]] + 1, res[i]);
//			}
//		}
//	}
//	if (res[m] == INT_MAX)
//	{
//		res[m] = -1;
//	}
//	return res[m];
//}
//
//int main()
//{
//	int T = 0;
//	cin >> T;
//	int n = 0, m = 0;
//	while (cin >> n >> m)
//	{
//		vector<int> foods(n);
//		for (int i = 0; i < n; i++)
//		{
//			cin >> foods[i];
//		}
//		vector<int> sum;//记录方案
//		int res = foodsum(foods, m, sum);
//		cout << res << endl;
//		if (res != -1)
//		{
//			//打印sum
//		}
//	}
//
//	return 0;
//}

static int res = 0;
static void climb(int dex, int n, int  m, int last, int lastlast)
{
	if (dex == n)
	{
		res++;
		res = res % 1000000007;
		return;
	}
	if (dex > n)
	{
		return;
	}
	for (int x = 1; x <= m; x++)
	{
		if (x != lastlast && x != last)
		{
			climb(dex + x, n, m, x, last);
		}
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	climb(0, n, m, 0, 0);
	cout << res << endl;
	return 0;
}