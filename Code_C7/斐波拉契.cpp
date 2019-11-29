#include<stdio.h>
#include<math.h>
int fib(int n)
{
	if(n<3)
	{
		return 1;
	}
	else
	{
	return fib(n-1) + fib(n-2);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",fib(n));
	return 0;
}

