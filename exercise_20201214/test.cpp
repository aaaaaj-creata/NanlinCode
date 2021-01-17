#include<iostream>
using namespace std;

#if 0
class Solution
{
public:
	int getTotalCount(int n)
	{
		if (n == 1 || n == 2)
		{
			return 1;
		}
		if (n > 2)
		{
			return getTotalCount(n - 1) + getTotalCount(n - 2);
		}
		else return 0;
	}
};

int main()
{
	int month = 0, sum = 0;
	Solution a;
	while (cin >> month)
	{
		sum = a.getTotalCount(month);
		cout << sum << endl;
	}

	return 0;
}
#endif

//×Ö·û´®Í¨Åä·û60%
class Solution
{
public:
	bool match(string s1,string s2)
	{
		int len1 = s1.size();
		int len2 = s2.size();
		int i = 0, j = 0;
		while (i < len1 && j<len2)
		{
			if (s1[i] == '?')
			{
				i++;
				j++;
			}
			if (s1[i] == '*')
			{
				if (i == len1 - 1)
				{
					return true;
				}
				while (j < len2)
				{
					if (s1[i + 1] == s2[j])
					{
						i++;
						break;
					}
					j++;
				}
			}
			if (s1[i] != s2[j])
			{
				return false;
			}
			i++, j++;
		}
		if (i == len1)
		{
			return true;
		}
		else return false;
	}
};

int main()
{
	string s1("te?1*.*");
	string s2("tet123.xls");
	Solution a;
	int flag = 0;
	flag = a.match(s1, s2);
	if (flag > 0)
	{
		cout << "true" << endl;
	}
	else cout << "false" << endl;

	return 0;
}