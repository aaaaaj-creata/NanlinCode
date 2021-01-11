#include<iostream>
#include<string>
using namespace std;

#if 0
//最近公共祖先
class LCA {
public:
	int getLCA(int a, int b) {
		// write code here
		while (a != b)
		{
			if (a > b)
			{
				a = a / 2;
			}
			else b = b / 2;
		}
		return a;
	}
};
#endif


//求最大连续bit数
int bit(int byte)
{
	string s;
	int  temp = 0;
	while (byte != 0)
	{	
		temp = byte % 2;
		s.push_back(temp);
		byte = byte / 2;
	}
	reverse(s.begin(), s.end());
	int i = 0, num = 0, max = 0;
	while (i < s.size()) 
	{
		while (s[i] == 1)
		{
				num++;
				i++;
		}
		if (num > max)
		{
			max = num;
		}
		i++;
		num = 0;
	}
	return max;
}

