//公共子串计算
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