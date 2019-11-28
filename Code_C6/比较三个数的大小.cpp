#include <stdio.h>
int main()
{
    int a,b,c;
    int max;
    scanf("%d,%d,%d",&a,&b,&c);
    max=a;
    if( max< b )
        max = b;
    else
    	max = a;
    if( max < c)
    	max = c;
	else
        max = a;

    printf("max=%d",max);
    return 0;
}

