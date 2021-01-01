#include<iostream>
#include<vector>
#include<string>

using namespace std;

#if 0
int main()
{
	int m = 0123;
	printf("%o", m);

	return 0;
}
#endif

#if 0
//不要二
int a[1000][1000] = { 0 };
int main()
{

	int sum = 0;
	int w, h;
	cin >> w >> h;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (a[i][j] == 0)
			{
				sum++;
				if (i + 2 < h)
				{
					a[i + 2][j] = -1;
				}
				if (j + 2 < w)
				{
					a[i][j+2] = -1;
				}
			}
		}
	}

	cout << sum << endl;
	return 0;
}
#endif

//把字符串转换为整数
class Solution {
public:
	int StrToInt(string str) {
		int len = str.size();
		if (len == 0) return 0;
		int i = 0;
		while (i<len && str[i] == ' ')
		{
			i++;
		}
		if (str[i] != '+' && str[i] != '-' && !isdigit(str[i]))
		{
			return 0;
		}
		bool flag = str[i] == '-' ? true : false;//正数flag为0，负数为非0

		if (!isdigit(str[i]))
		{
			i++;
		}
		long long sum = 0;
		while (i < str.size() && isdigit(str[i]))
		{
			sum =  sum * 10 + (str[i] - '0');
			i++;
			if (flag==0 && sum > INT_MAX)
			{
				sum = INT_MAX;
				break;
			}
			if (flag != 0 && sum - 1 > INT_MAX)
			{
				sum = INT_MAX + 1;
				break;
			}
		}

		if (i != len) return 0;

		if (flag != 0)
		{
			cout << -sum << endl;
		}
		else cout << sum << endl;

	}
};

int main()
{
	Solution a;
	string s("-123");
	a.StrToInt(s);
	return 0;
}