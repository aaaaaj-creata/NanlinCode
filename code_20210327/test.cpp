#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*
输入一个长度为n的字符串，字符串的每一个元素都是0~9之间的,如果子序列中数字顺序为1807就是“好的”，输出最长的“好的”子序列的长度
例如输入 18800007777000007
最长“好的”子序列长度为 ： 13（1880000000007）
*/
//1
//int len(string s)
//{
//	int res = 0;
//	if (s[0] != '1')
//	{
//		return 0;
//	}
//	int i = 0;
//	int start = 0;
//	while(i < s.size() && s[i] == '1')
//	{
//		res++;
//		i++;
//	}
//	return res;
//}


//int main()
//{
//	string s;
//	int res = len(s);
//	cout << res << endl;
//	return 0;
//}

/*2荣耀积分
在i时刻完成游戏得到该游戏的分数，i时刻没完成的游戏减去该游戏的分数，输出最大得分
第一行输入T组数据
第二行输入n个游戏
第三行n个游戏分别开始的时刻
第四行n个游戏各个的分数
例子
输入
1
3
3 1 1
3 6 9
输出
6
解释：
时刻1时完成9分的游戏，得分记为9；由于无法完成6分的游戏，扣6分，得分记为3；时刻3完成3分的游戏，得分记为6
最大总得分6
*/
int main()
{
	int T = 0;
	cin >> T;
	while (T--)
	{
		int n = 0;
		cin >> n;
		multimap<int, int> m;
		vector<int> time(n);
		for (int i = 0; i < n; i++)
		{
			cin >> time[i];
		}
		vector<int> score(n);
		for (int i = 0; i < n; i++)
		{
			cin >> score[i];
		}
		for (int i = 0; i < n; i++)
		{
			m.insert(pair<int,int>(time[i], score[i]));
		}
		//计分
		int sum = 0;
		multimap<int, int>::iterator it;
		sort(time.begin(), time.end());
		vector<int>::iterator new_end = unique(time.begin(), time.end());
		time.erase(new_end, time.end());
		for (int i = 0; i <time.size() ; i++)
		{
			int temp = 0,max = 0;
			vector<int> tmp;
			for (it = m.lower_bound(time[i]); it != m.upper_bound(time[i]); it++)
			{
				temp = it->second;
				tmp.push_back(temp);
			}
			sort(tmp.begin(), tmp.end());
			max = tmp[tmp.size() - 1];
			for (int i = tmp.size() - 2; i >= 0; i--)
			{
				max = max - tmp[i];
			}
			sum = sum + max;
		}
		cout << sum << endl;
	}
	return 0;
}




/*
判断一个闭区间[L, R]之间平衡数的数量
平衡数指这个数奇数位相加的和 与 偶数位相加的和 相等
例如132就是一个平衡数 1+2 == 3
*/
//3
//int judge(string s)
//{
//	int suma = 0;//奇数位和
//	int sumb = 0;//偶数位和
//	for (int i = 1; i < s.size(); i += 2)
//	{
//		if (i < s.size())
//		{
//			suma += s[i] - '0';
//		}
//	}
//	for (int i = 0; i < s.size(); i += 2)
//	{
//		if (i < s.size())
//		{
//			sumb += s[i] - '0';
//		}
//	}
//	if (suma == sumb)
//	{
//		return 1;
//	}
//	return 0;
//}
//
//
//int judge2(string s)
//{
//	
//}
////10 11 12 13 14 15 n=6 
//int banlancesum(int start, int end)
//{
//	int sum = 0;
//	int n = end - start + 1;
//	vector<string> s(n);
//	for (int i = 0, j = start; i < n; i++, j++)
//	{
//		string temp;
//		temp = to_string(j);
//		s[i] = temp;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		int res = judge(s[i]);
//		if (res == 1)
//		{
//			sum++;
//		}
//	}
//	return sum;
//}
//
//int main()
//{
//	int start, end;
//	cin >> start >> end;
//	int res = banlancesum(start, end);
//	cout << res << endl;
//	return 0;
//}