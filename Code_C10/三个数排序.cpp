#include <stdio.h>
int main()
{
    int a,b,c,d;
    scanf("%d,%d,%d",&a,&b,&c);
    if(b>a)
    {
        d=a;
        a=b;
        b=d;
    }
    if(c>a)
    printf("%d %d %d\n",b,a,c);
    else
    {
        if(b<c) printf("%d %d %d\n",b,c,a);
        else printf("%d %d %d\n",c,b,a);
    }
    return 0;
}
