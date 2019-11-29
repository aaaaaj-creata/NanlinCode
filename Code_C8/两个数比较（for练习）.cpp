#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int t,a,b;
    scanf("%d",&t);
    for( ; t>0 ; t--)
    {
        scanf("%d %d",&a,&b);
        if(a > b)
		printf("%d\n",a);
        else 
		printf("%d\n",b);
    }
    return 0;
}

