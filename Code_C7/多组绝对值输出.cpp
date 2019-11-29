#include<stdio.h> 
double y(double n)
{ 
	return n >= 0? n:-n; 
}

int main() 
{ 
	double n,s; 
	while(scanf("%lf",&n)!=EOF) 
	{ 
		s = y(n); 	
		printf("%.2lf\n",s); 
	} 
	return 0; 
} 


