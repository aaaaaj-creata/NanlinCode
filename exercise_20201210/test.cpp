#include<iostream>
using namespace std;

//查找输入整数二进制中1的个数 
int main()
{
	int num = 0, count = 0, temp = 0;
	while (cin >> num)
	{
		count = 0;
		while (num != 0)
		{
			temp = num % 2;
			if (temp == 1)
			{
				count++;
			}
			num = num / 2;
		}
		cout << count << endl;	
	}
	return 0;
}

class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		int sum = 0;
		int left_sum = 0, left_min = 26;//左边的手套总数，和左边数量最少的一个颜色的手套数
		int right_sum = 0, right_min = 26;//右边
		for (int i = 0; i < n; i++)
		{
			if (left[i] * right[i] == 0)//如果某种颜色的手套有一边数量为0就要全部带上
			{
				sum = sum + left[i] + right[i];
			}
			else
			{
				left_sum += left[i];
				right_sum += right[i];
				left_min = min(left[i], left_min);//找左边的最小手套数
				right_min = min(right[i], right_min);//找右边的最小手套数
			}
		}
		sum = sum + min(left_sum - left_min + 1 , right_sum - right_min + 1) + 1;
		return sum;
	}
};