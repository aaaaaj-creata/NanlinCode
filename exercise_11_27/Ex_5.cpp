#include<stdio.h>

int main()
{
	int I=1,V=5,X=10,L=50,C=100,D=500,M=1000;
	int sum=0;
	char arr[100];
	scanf(" \"%s\" ",arr);
	if(arr=="IV") sum=4;
	if(arr=="IX") sum=9;
	if(arr=="XL") sum=40;
	if(arr=="XC") sum=90;
	if(arr=="CD") sum=400;
	if(arr=="CM") sum=900;
	printf("%d\n",sum);
	for(int i=0;i<100;i++)
	{
		if(arr[i])=='I')
		{
			sum=sum+1;
		}
		if(arr[i])=='V')
		{
			sum=sum+5;
		}
	} 
	return 0;
}
