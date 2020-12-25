#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

#if 0
int main()
{
	string s;
	string num;
	getline(cin, s);
	int i = 0, temp = 0, sum = 0;
	for (i = 0; i < s.size(); i++)
	{
		if (isdigit(s[i]) != 0)
		{
		
			while (isdigit(s[i]) != 0)
			{
				i++, temp++;
			}
		}
		if (temp > sum)
		{
			sum = temp;
			num = s.substr(i - temp, temp);
		}

		temp = 0;

	}
	cout << num << endl;

	return 0;
}
#endif

//找出数组中出现超过一半的数字
class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		sort(numbers.begin(), numbers.end());
		int key = numbers[numbers.size() / 2];
		int count = 0;
		for (int i = 0; i < numbers.size(); ++i) {
			if (key == numbers[i])
				++count;
		}
		if (count > numbers.size() / 2)
			return key;
		return 0;
	}
};
