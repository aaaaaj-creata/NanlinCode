#include<stdio.h>  
int main()  
{  
	int N,a,b,c=0;  
	scanf("%d",&N);  
	a=N*N*N;  
	while(a)  
		{	  
			b=a%10;  
			c=c+b*b*b;  
			a=a/10;  
		}  
	printf("%d",c); 

	return 0; 
}

