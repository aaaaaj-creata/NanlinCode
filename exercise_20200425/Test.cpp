//#include<iostream>
//using namespace std;
//struct circle {
//	int x1, x2;
//	int y1, y2;
//};
//int main()
//{
//	int n, m;
//	int r, c;
//	cin >> n >> m;
//	cin >> r >> c;
//	int total = n * m;
//	int a = n / 2;
//	if (n % 2 != 0)
//	{
//		a++;
//	}
//	circle q[a];
//	int x1 = 1, x2 = n;
//	int y1 = 1, y2 = m;
//	for (int i = 0; i < a; i++)
//	{
//		q[i].x1 = x1;
//		q[i].x2 = x2;
//		q[i].y1 = y1;
//		q[i].y2 = y2;
//		x1++;
//		x2--;
//		y1++;
//		y2--;
//	}
//	int num = 0;
//	for (int i = a - 1; i >= 0; i--)
//	{
//		if (r >= q[i].x1 && r <= q[i].x2 && c >= q[i].y1 && c <= q[i].y2)
//		{
//			for (int j = 0; j < i; j++)
//			{
//				num = num + (q[j].y2 - q[j].y1 + 1) * 2 + (q[j].x2 - q[j].x1 - 1) * 2;
//
//			}
//			if (r == q[i].x1)
//			{
//				num = num + c - q[i].y1 + 1;
//			}
//			else if (c == q[i].y2)
//			{
//				num = num + (q[i].y2 - q[i].y1 + 1) + r - q[i].x1;
//			}
//			else if (r == q[i].x2)
//			{
//				num = num + (q[i].y2 - q[i].y1 + 1) + (q[i].x2 - q[i].x1 - 1) + q[i].y2 - c + 1;
//			}
//			else
//			{
//				num = num + (q[i].y2 - q[i].y1 + 1) * 2 + (q[i].x2 - q[i].x1 - 2) + q[i].x2 - r + 1;
//			}
//			cout << num << endl;
//			return 0;
//		}
//	}
//}

#include <iostream>
using namespace std;
int dp[1004][1004];
int main() {
	// m为长度，n为数的范围
	int m, n;
	cin >> m >> n;

	for (int i = 1; i <= n; i++)
		dp[1][i] = n - i + 1;

	for (int i = 2; i <= m; i++)
		if (i & 1)
			for (int j = n; j >= 1; j--)
				dp[i][j] = (dp[i - 1][j - 1] + dp[i][j + 1]) % 10000;
		else
			for (int j = 1; j <= n; j++)
				dp[i][j] = (dp[i - 1][j + 1] + dp[i][j - 1]) % 10000;

	int ans = m & 1 ? dp[m][1] : dp[m][n];

	cout << ans;

	return 0;
}
