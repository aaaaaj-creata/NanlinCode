#include<stdio.h>
int main()
{
	double r,h,c,s,S,v;
	double t=3.1415926;
	scanf("%lf %lf",&r,&h);
	c = 2*t*r;
	s = t*r*r;
	S = h*2*t*r;
	v = h*t*r*r;
	printf("%.2f %.2f %.2f %.2f",c,s,S,v);
	
	
	
	return 0;
}
