#include<iostream>
#include<string>
#include<vector>
using namespace std;

#if 0
//统计回文
bool isPalindrome(string s)
{
	if (s.size() == 1)
		return true;
	int start = 0;
	int end = s.size() - 1;
	while (start < end)
	{
		if (s[start++] != s[end--])
			return false;
	}
	return true;
}

int main()
{
	string A,B,C,temp;
	cin >> A;
	cin >> B;
	int len = A.size();
	int num = 0;
	for (int i = 0; i < len+1; i++)//A串尾部也能插，len+1
	{
			temp = A;
			C = temp.insert(i,B);
			if (isPalindrome(C))
			{
				num++;
			}
	}
	cout << num << endl;
	return 0;
}
#endif

//连续最大和
int main()
{
	int n, max;
	cin >> n;
	vector<int> list(n, 0), dp(list);
	for (int i = 0; i < n; i++)   //创建数组
		cin >> list[i];
	max = dp[0] = list[0];
	for (int i = 1; i < n; i++)   //由于是连续的，因此只需要更新对
	{                                     //角线即可，之前部分遇上一行相同
		if (list[i] + dp[i - 1] > list[i])      //如果上一对角线上的数和更大
			dp[i] = list[i] + dp[i - 1];       //填入对应位置
		else
			dp[i] = list[i];                       //否则，即为这个数本身
		if (max < dp[i]) max = dp[i];     //寻找数组中最大的

	}
	cout << max << endl;
	return 0;
}