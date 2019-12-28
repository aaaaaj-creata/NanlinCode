#include<stdio.h>

int main()
{
	int a=0;
	int nums[4]={2,7,11,15};
	int sum=0;
	scanf("%d",&sum);
	for(int i=0;i<4;i++)
	{
		for(int j=1;j<4-i;j++)
		{
			a=nums[i]+nums[j];
			if(sum==a)
			{
				printf("[%d,%d]",i,j);
				continue; 
			}
		}
	}
	
	return 0;
 } 
