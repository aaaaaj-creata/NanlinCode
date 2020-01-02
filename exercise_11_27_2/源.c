#include<stdio.h>
#include<math.h>
int fib(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return fib(n - 1) + fib(n - 2);
	}
}
int main()
{
	int N = 0,a=0,b=0;
	scanf_s("%d", &N);
	for (int i = 0; i < 100; i++)
	{
		if (N > fib(i) && N < fib(i + 1))
		{
			a = N - fib(i);
			b = fib(i + 1) - N;
			if (a < b)
			{
				printf("%d", a);
				break;
			}
			else
			{
				printf("%d", b);
				break;
			}
		}
	}
	return 0;
}