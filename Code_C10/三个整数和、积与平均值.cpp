#include<stdio.h>
int main()
{
	int a,b,c,s,d;
	double e;
	scanf("%d %d %d",&a,&b,&c);
	s = a+b+c;
	d = a*b*c;
	e = s/3.0;
	printf("%d %d %.2lf",s,d,e);
	
	
	return 0;
 } 
