#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if ((a-b)*(a-c)<0)
	printf("%d",a);
	if ((b-a)*(b-c)<0)
	printf("%d",b);
	if ((c-b)*(c-a)<0)
	printf("%d",c);
	
	
	
	
	return 0;
}
