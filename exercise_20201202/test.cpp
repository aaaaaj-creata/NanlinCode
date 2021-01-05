#include<iostream>
#include<vector>
using namespace std;
//另类加法
#if 0
class UnusualAdd {
public:
	int addAB(int A, int B) {
		int sum = 0, num = 0;
		while (B != 0)
		{
			sum = A ^ B;
			num = (A & B) << 1;
			A = sum;
			B = num;
		}
		return A;
	}
};
#endif

#if 0
//设m行n列的网格，延网格线，求从左上角走到右下角的不同路线条数，只能向右走或向下走，每次走一步
int main()
{
	
	int m, n;
	int i = 0, j = 0;
	cin >> n >> m;//m行，n列
	vector<vector<int>> v(m+1);
	for (i = 0; i < m+1; i++)
	{
		v[i].resize(n+1);
	}
	i = 0;
	while (i <= m)
	{
		v[i][0] = 1;
		i++;
	}
	while (j <= n)
	{
		v[0][j] = 1;
		j++;
	}
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			v[i][j] = v[i - 1][j] + v[i][j - 1];
		}
	}
	cout << v[m][n] << endl;
	return 0;
}
#endif
