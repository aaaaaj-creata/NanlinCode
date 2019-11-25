#include <stdio.h>
int main()
{
	int n,b,c=0 ;
	scanf("%d",&n) ;
	while( n != 0 )
	{
		b = n % 10 ;
		if( b % 2 == 0)
		c = c + b ; 
		n = n / 10 ;
	}
	printf("%d",c) ;
	
	return 0;
}
