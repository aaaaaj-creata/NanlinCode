#include <stdio.h>
int main (void)
{
	int a,b,c;
	scanf("%d,%d,%d",&a,&b,&c);
	
	if(a<b)
	{
		if(b<c)
		{
			printf("max=%d",c);
		}
		else
		{
			printf("max=%d",b);
		}
	}
    else
	{
	 	if(a<c)
		{
		   printf("max=%d",c);
	   	}
		else
		{
			printf("max=%d",a);
		}
	}
	return 0;
}
