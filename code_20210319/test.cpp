#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//奖品争夺
//int ticketsum(int num)//一个数需要多少张修改卷就赢
//{
//	int res = 0;
//	int prev = 0;//记录num上一次的值
//	int now = 0;
//	for (int i = 1; num > 0; i += 2)
//	{
//		prev = num;
//		num -= i;
//	}
//	now = (-1) * num;
//	if (now > prev)
//	{
//		res = prev;
//	}
//	else
//	{
//		res = now;
//	}
//	return res;
//}
//
//int main()
//{
//	int n = 0;
//	cin >> n;
//	vector<int> a;
//	for (int i = 0; i < n; i++)
//	{
//		int tmp = 0;
//		cin >> tmp;
//		a.push_back(tmp);
//	}
//	int count = 0;//累加最少的修改卷
//	vector<int> ticket;//记录每个人需要多少张修改卷
//	for (int i =0 ; i < n; i++)
//	{
//		ticket.push_back(ticketsum(a[i]));
//	}
//	sort(ticket.begin(), ticket.end());
//	for (int i = 0; i < n / 2; i++)
//	{
//		count += ticket[i];
//	}
//	cout << count << endl;
//	return 0;
//}

//卡牌游戏
int main()
{
	int n = 0;
	cin >> n;
	vector<vector<int>> arr(n);
	for (int i = 0; i < n; i++)
	{
		arr[i].resize(2, 0);
	}
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;
		arr[i][0] = temp; //a[i]
	}
	for (int i = 0; i < n; i++)
	{
		int temp = 0;
		cin >> temp;
		arr[i][1] = temp; //b[i]
	}
	int min = INT_MAX;//记录最小b[i] + b[j] + b[k]
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if (arr[i][0] <= arr[j][0] && arr[j][0] <= arr[k][0] && arr[i][0] <= arr[k][0])
				{
					int tmp = 0;
					tmp = arr[i][1] + arr[j][1] + arr[k][1];
					if (tmp < min)
					{
						min = tmp;
					}
				}
			}
		}
	}

	cout << min << endl;
	return 0;
}