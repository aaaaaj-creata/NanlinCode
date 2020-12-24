#include <iostream>
#include <vector>
#include <string>
using namespace std;

#if 0
int main()
{
	int n = 0,i = 0,j=0;
	cin >> n;
	vector<vector<int>> res(n,vector<int>(0));
	for ( i = 0; i < n; i++) 
	{
		res[i].resize(2 * n - 1);
	}

	res[0][0] = 1;
	for (i = 1 ; i < n; i++)
	{
		for ( j = 0; j < 2 * n - 1; j++)
		{
			if (j == 0)
			{
				res[i][j] = 1;
			}
			if (j == 1)
			{
				res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
			}
			if(j >= 2)
			{
				res[i][j] = res[i - 1][j - 2] + res[i - 1][j-1] + res[i-1][j];
			}
		}
	}
	int index = 0;
	j = 0;
	while (j < 2*n -1)
	{
		if (res[n - 1][j] % 2 == 0)
		{
			index = j + 1;
			break;
		}
		j++;
	}
	cout << index << endl;

	return 0;
}
#endif

class Solution
{
public:
	string AddLongInteger(string add, string aug)
	{
		string sum;
		int tmplen = 0;
		int step = 0, num = 0;//进位
		int addlen = add.size();
		int auglen = aug.size();
		if (addlen < auglen)//保证add是长的
		{
			tmplen = addlen;
			addlen = auglen;
			auglen = tmplen;
			swap(add, aug);
		}
		
		reverse(add.begin(), add.end());
		reverse(aug.begin(), aug.end());
		int i = 0;
		for ( i = 0; i < auglen; i++)
		{
			num = (add[i]-'0') + (aug[i]-'0') + step;
			step = 0;
			if (num >= 10)
			{
				num -= 10;
				step++;
			}
			sum.push_back((num+'0'));
		}
		while (i < addlen)
		{
			num = (add[i] - '0') + step;
			step = 0;
			if (num >= 10)
			{
				num -= 10;
				step++;
			}
			sum.push_back((num + '0'));
			i++;
		}
		if (step != 0)
		{
			sum.push_back((step + '0'));
		}
		reverse(sum.begin(), sum.end());
		return sum;
	}
	
};

int main()
{
	Solution a;
	string add("999999999999999999");
	string aug("1");
	string b = a.AddLongInteger(add, aug);
	cout << b << endl;

	return 0;
}