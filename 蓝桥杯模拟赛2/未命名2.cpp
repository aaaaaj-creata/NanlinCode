#include<bits/stdc++.h>

int main()
{
	int n,m,r,c,num=0;
	scanf("%d %d",&n,&m);
	scanf("%d %d",&r,&c);
	if(r==1)
	{
		num=c;
	}
	if(c==m)
	{
		num=m+r-1;
	}
	if(r==n)
	{
		num=m+2*n-1-c;
	}
	
 } 
