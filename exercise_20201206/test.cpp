#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//二进制插入
class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		string N, M;
		N = binary(n);
		M = binary(m);
		for (int z = 0; z<M.size(); z++, j++)
		{
			N[j] = M[z];
		}
		reverse(N.begin(), N.end());
		long long sum = 0;
		sum = binarynum(N);
		return sum;
	}

	string binary(int n)
	{
		string s;
		int temp = 0;
		while (n != 0)
		{
			temp = n % 2;
			s.push_back(temp);
			n = n / 2;
		}
		//reverse(s.begin(),s.end())//不要这句就是将一个整数转换为二进制
		return s;
	}
	long long binarynum(string s)
	{
		int i = 0;
		long long sum = 0;
		while (i < s.size())
		{
			sum = sum * 2 + s[i];
			i++;
		}
		return sum;
	}
};

int main()
{
	BinInsert b;
	string s("1001");
	int sum = 0;
	sum = b.binInsert(1024, 19, 2, 6);
	cout << sum << endl;
	return 0;
}

//查找组成一个偶数最接近的两个素数 

int isprime(int x) {   //判断是否为素数
	int flag = 1;
	for (int i = 2; i < x; i++) {
		if (x % i == 0) {
			flag = 0;
			break;
		}
	}
	return flag;
}

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = n / 2; i >= 2; i--) {    //从中间开始寻找
			if (isprime(i) && isprime(n - i)) {
				printf("%d\n", i);
				printf("%d\n", n - i);
				break;
			}
		}
	}
	return 0;
}