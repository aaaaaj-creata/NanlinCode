//0-1背包问题动态规划解法
#include<iostream>
#include<time.h>
#include<map>
using namespace std;
int main()
{
	//（5，12），（4，3），（7，10），（2，3），（6，6）背包容量15
	int f[6][16] = { 0 };
	int application[6][16];
	int weight[5] = { 5,4,7,2,6 };
	int value[5] = { 12,3,10,3,6 };
	clock_t start, end;
	int n = 10000;
	start = clock();
	while (n--)
	{
		for (int i = 1; i < 6; i++)
		{
			for (int j = 1; j < 16; j++)
			{
				if (j - weight[i - 1] >= 0)
				{
					if (f[i - 1][j] > f[i - 1][(j - weight[i - 1])] + value[i - 1])
					{
						f[i][j] = f[i - 1][j];//不放
						application[i][j] = 0;
					}
					else
					{
						f[i][j] = f[i - 1][(j - weight[i - 1])] + value[i - 1];
						application[i][j] = 1;
					}
					//f[i][j] = f[i - 1][j] > f[i - 1][(j - weight[i - 1])] + value[i - 1] ? f[i - 1][j] : f[i - 1][(j - weight[i - 1])] + value[i - 1];
				}
				else
				{
					f[i][j] = f[i - 1][j];//不放
					application[i][j] = 1;
				}

			}
		}
	}

	cout << "动态规划表：" << endl;
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 16; j++)
		{
			cout << f[i][j] << " ";
		}
		cout << endl;
	}
	cout << "放入背包的物品有：" << endl;
	int j = 15;
	//第一种得到具体方案的方法：
	for (int i = 5; i > 0; i--)
	{
		if (f[i][j] != f[i - 1][j])
		{
			cout << "物品" << i << "加入背包" << endl;
			j = j - weight[i - 1];
		}
	}

	return 0;
}