#include<stdio.h>

int main()
{
	int i=1,sum=0;
	int a=0,b=0,c=0,d=0;
	for(i=1;i<2020;i++)
	{
		if(i<10)
		{
			a=i;
		}
		if(i>=10 && i<100)
		{
			a=i%10;
			b=i/10;
		}
		if(i>=100 && i<1000)
		{
			a=i%10;
			b=i/10;
			c=i/100;
		}
		if(i>=1000)
		{
			a=i%10;
			b=i/10;
			c=i/100;
			d=i/1000;
		}
		if(a==9||b==9||c==9||d==9)
		{
			sum++;
		}
	}
	printf("%d",sum);
	return 0;
}
