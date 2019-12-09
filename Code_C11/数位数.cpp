#include <stdio.h>
int main()
{ 
    int n,num=0;
    scanf("%d",&n);
    while( n )
	{
        num++;
        n=n/10;
    }
    printf("%d\n",num);
    return 0;
}
