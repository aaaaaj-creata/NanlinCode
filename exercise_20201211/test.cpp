#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#if 0
//完全数计算
int count(int n)
{
	int count = 0, sum = 0;
	int i = 1, j = 1;
	for (; i <= n; i++)
	{
		sum = 0,j = 1;
		while (j < i)
		{
			if (i % j == 0)
			{
				sum += j;
			}
			j++;

		}
		if (sum == i)
		{
			count++;
		}
	}
	return count;
}




void test1()
{
	int n = 0;
	cin >> n;
	cout << count(n) << endl;

}


int main()
{
	//test1();

	return 0;
}

#endif

#if 0
//扑克牌大小过40%
vector<string> num = { "3","4","5","6","7","8","9","10","J","Q","K","A","2","joker","JOKER" };

int judgepoker(vector<string> LEFT,vector<string> RIGHT)
{
	int llen = LEFT.size();
	int rlen = RIGHT.size();
	//个子、对子、三个
	if ((llen == 1 && rlen == 1) || (llen == 2 && rlen == 2) || (llen == 3 && rlen == 3))
	{
		auto index1 = find(num.begin(), num.end(), LEFT[0]);
		auto index2 = find(num.begin(), num.end(), RIGHT[0]);
		if (index1 > index2)
		{
			return 1;
		}
		else return 0;
	}
	//炸弹
	if ((llen == 4 && rlen == 4) || (llen == 2 && rlen == 4) || (llen == 4 && rlen == 2))
	{
		auto index1 = find(num.begin(), num.end(), LEFT[0]);
		auto index2 = find(num.begin(), num.end(), RIGHT[0]);
		if (index1 > index2)
		{
			return 1;
		}
		else return 0;
	}
	//顺子
	else
	{
		auto index1 = find(num.begin(), num.end(), LEFT[0]);
		auto index2 = find(num.begin(), num.end(), RIGHT[0]);
		if (index1 > index2)
		{
			return 1;
		}
		else return 0;
	}
}


int main()
{
	string res;
	getline(cin, res);
	string left, right, temp;
	vector<string> LEFT, RIGHT;
	int i = 0, j = 0;
	while (res[i] != '-')
	{
		i++;
	}

	left = res.substr(0, i);
	while (j < left.length())//将左边的牌放入LEFT一个牌为一个元素
	{
		if (isdigit(left[j]))
		{
			temp = left[j];
			LEFT.push_back(temp);
		}
		if (left[j] == 'J' || left[j] == 'j')
		{
			temp = left.substr(j, 5);
			LEFT.push_back(temp);
			j += 5;
		}
		j++;
	}

	right = res.substr(i + 1, res.size() - i);
	j = 0;
	while (j < right.length())//将右边的牌放入RIGHT
	{
		if (isdigit(right[j]))
		{
			temp = right[j];
			RIGHT.push_back(temp);
		}
		if (right[j] == 'J' || right[j] == 'j')
		{
			temp = right.substr(j, 5);
			RIGHT.push_back(temp);
			j += 5;
		}
		j++;
	}

	int win = 0;
	win = judgepoker(LEFT,RIGHT);
	if (win == 1)
	{
		cout << left << endl;
	}
	else cout << right << endl;

	return 0;
}
#endif
