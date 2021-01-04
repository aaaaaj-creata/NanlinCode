#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

#if 0
//两种排序方法
//通过80%
int main()
{
	int n = 0;
	cin >> n;
	string s,temp("a");
	int i = 0,j=0,len;
	int lengths = 0;
	int lex = 0;

	while (j<n)
	{
		cin >> s;
		if (temp.size() <= s.size())
		{
			lengths++;
		}
		i = 0;
		len = min(temp.size(), s.size());
		while (i < len)
		{
			if ((temp[i] - '0') > (s[i] - '0'))
			{
				break;
			}
			i++;
		}
		if (i == len)
		{
			lex++;
		}
		temp = s;
		j++;
	}

	if (lengths == n && lex==n)
	{
		cout << "both" << endl;
	}
	else if (lengths == n && lex!=n)
	{
		cout << "lengths" << endl;
	}
	else if (lengths != n && lex == n)
	{
		cout << "lexicographically" << endl;
	}
	else
	{
		cout << "none" << endl;
	}

	return 0;
}

#endif

/*
字典序排序，字符串大小排序
*/

vector<string>vec;

//按照字典序排序
bool  lexicographically() {

	int i = 0;
	string s;

	while ((i + 1) < vec.size()) {
		if (vec[i].compare(vec[i + 1]) > 0)
			return 0;
		i++;
	}
	return 1;
}

//按照字符串大小排序
bool Lenths() {

	int i = 0;
	while ((i + 1) < vec.size()) {
		if (vec[i + 1].size() < vec[i].size())
			return 0;
		i++;
	}
	return 1;
}

int main() {

	string s;
	int n, i = 0;
	bool b1, b2;

	cin >> n;
	while (i < n) {
		cin >> s;
		vec.push_back(s);
		i++;
	}

	b1 = lexicographically();
	b2 = Lenths();

	if (b1 && b2)
		cout << "both";
	else if (b1 && !b2)
		cout << "lexicographically";
	else if (!b1 && b2)
		cout << "lengths";
	else
		cout << "none";


	return 0;
}



#if 0
//两求最小公倍数
int main()
{
	int A = 0, B = 0;
	cin >> A >> B;
	if(A<B)
	{
		swap(A, B);
	}
	int tmp1 = A;
	int tmp2 = B;
	int sum = 1;//余数
	while (sum!=0)
	{
		sum = A % B;
		A = B;
		B = sum;
	}
	cout << (tmp1 / A) * (tmp2 / A) * A << endl;
	return 0;
}
#endif

#if 0
bool Len(vector<string> s, int n)
{

	for (int i = 0; i < n; i++)
	{
			if ( i+1<n && s[i].size() > s[i + 1].size())
			{
				return 0;
			}

	}
	return 1;
}

bool Lex(vector<string> s, int n)
{
	int j = 0;
	int min = 0;
		
	for (int i = 0;  i<n; i++)
	{
		if (i+1<n && s[i].size() > s[i + 1].size())
		{
			min = s[i + 1].size();
		}
		else
		{
			min = s[i].size();
		}
		for (j = 0; j < min; j++)
		{
			
			if (i+1<n && s[i][j] - '0' > s[i + 1][j] - '0')
			{
				return 0;
			}

		}
		j = 0;
	}
	return 1;
}

int main()
{
	int n;
	cin >> n;
	string temp;
	vector<string> s;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		s.push_back(temp);
	}

	int a = Len(s, n);
	int b = Lex(s, n);

	if (a == 1 && b == 1)
	{
		cout << "both" << endl;
	}
	if (a == 0 && b == 1)
	{
		cout << "lexicographically" << endl;
	}
	if (a == 1 && b == 0)
	{
		cout << "lengths" << endl;
	}
	if (a == 0 && b == 0)
	{
		cout << "none" << endl;
	}

	system("pause");
	return 0;
}

#endif