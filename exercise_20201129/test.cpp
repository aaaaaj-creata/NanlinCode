#include<iostream>
#include<stack>
using namespace std;

#if 0
int main()
{
	int b = 3,c = 3;
	if (b != 2 || c-- != 3)
	{
		printf("%d %d", b, c);
	}
	return 0;
}
#endif

#if 0
int main()
{
	int n = 0;
	char ch;
	for (ch=getchar(); ch != '\n'; n++)
	{

	}
	//while (ch=getchar() != '\n')
	//{
	//	n++;
	//}
	cout << n << endl;
	return 0;
}
#endif

//#if 0
int Fib(int i)
{
	if (i == 0)
	{
		return 0;
	}
	if (i == 1)
	{
		return 1;
	}
	else
	{
		return Fib(i - 1) + Fib(i - 2);
	}
}

int main()
{
	int i = 0,step=0,N;
	cin >> N;
	while (Fib(i) < N)
	{		
		if (Fib(i) <= N && N <= Fib(i + 1))
		{
			if (N - Fib(i) > Fib(i + 1) - N)
			{
				step = Fib(i + 1) - N;
			}
			else  step = N - Fib(i);

			break;
		}
		i++;
	}
	cout << step << endl;

	return 0;
}
//#endif

#if 0
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		// write code here
		stack<char> s;
		int i = 0;
		while (i < n)
		{
			if (A[i] != '(' && A[i] != ')')
			{
				return false;
			}
			if (A[i] == '(')
			{
				s.push(A[i]);
				i++;
			}
			else if (A[i] == ')')
			{
				if (!s.empty() && s.top() == '(')
				{
					s.pop();
					i++;
				}
				else
					return false;
			}
			else
			{
				i++;
			}
		}
		if (s.empty())
		{
			return true;
		}
		else return false;
	}
};

int main()
{
	string a("(()()())()");
	Parenthesis s;
	if (s.chkParenthesis(a, 10))
	{
		cout << "ok" << endl;
	}
	else
		cout << "no" << endl;

	return 0;
}
#endif