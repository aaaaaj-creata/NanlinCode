#include <iostream>
#include <string>
using namespace std;

//反转字符串
//int main()
//{
//    string s;
//    while (getline(cin, s))
//    {
//        reverse(s.begin(), s.end());
//        cout << s << endl;
//    }
//    return 0;
//}

//公共子串计算
int main()
{
    string s1, s2;
    int sum, max;
    while (cin >> s1 >> s2)
    {
        sum = 0, max = 0;
        if (s1 == "" && s2 == "")
        {
            return 0;
        }
        if (s1.size() > s2.size())
        {
            swap(s1, s2);//保持s1为短,s2为长
        }
        for (int i = 0; i < s1.size(); i++)
        {
            for (int j = 0; j < s2.size(); j++)
            {
                if (s2[j] == s1[i])
                {
                    while (i< s1.size() && j < s2.size() && s2[j] == s1[i])
                    {
                        sum++;
                        i++, j++;
                    }
                }
            }
            if (sum > max)
            {
                max = sum;
                sum = 0;
            }
        }
        cout << max << endl;
    }
    return 0;
}

#include<iostream>
#include<vector>
using namespace std;
int main() {
    string str1, str2;
    while (cin >> str1 >> str2) {
        int len1 = str1.size();
        int len2 = str2.size();
        int max = 0;
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        for (int i = 1; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                if (dp[i][j] > max)
                    max = dp[i][j];
            }
        }
        cout << max << endl;
    }
    return 0;
}