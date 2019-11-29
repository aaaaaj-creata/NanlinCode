#include<stdio.h>
#include<math.h>

int sum(int x, int n)
{
	if(n==1,x==0)
	{
		return 1;
	}
	else
	{
	return sqrt(n+sqrt(n-1));
	}
}
int main()
{
	int x,n;
	scanf("%d %d",&n,&x);
	printf("%d.00",sum(x,n));
	return 0;
}

