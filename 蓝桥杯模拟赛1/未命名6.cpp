#include<bits/stdc++.h>

int main()
{
	int n=0,m=0,k=0,i=0,j=0,l=0;
	char arr[n][m];
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%s",arr[i]);		
	}
	scanf("%d",&k);
	
	for(l=0;l<k;l++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(arr[i][j]=='g')
				{
					if(i-1>=0)
					{
						arr[i-1][j]='g';
					}
					if(i+1<n)
					{
						arr[i+1][j]='g';
					}
					if(j-1>=0)
					{
						arr[i][j-1]='g';
					}
					if(j+1<m)
					{
						arr[i][j+1]='g';
					}
				}
			}
		}	
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%c",arr[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
