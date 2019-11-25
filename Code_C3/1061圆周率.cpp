#include<stdio.h>
int main()
{
double sum=0;
int n,i;
scanf("%d",&n);
for(i=1;i<=n;i++)
{
sum=sum+1/(double)(4*i-3)-1/(double)(4*i-1);
}
printf("%.5lf\n",sum*4);
return 0;
}

