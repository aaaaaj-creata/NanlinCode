#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, c, m, e, t, a[100], j;
    scanf("%d",&n);
    for(i = 0 ; i < n ; i++)
    {
        scanf("%d %d %d",&c, &m, &e);
        a[i] = c+m+e;
    }
    for(i = 0 ; i < n ; i++)
    {
        for(j = i+1 ; j < n ; j++)
        {
         if(a[i]<a[j])
         {
             t = a[i];
             a[i] = a[j];
             a[j] = t;
         }
        }
    }
    for(i = 0 ; i < n ; i++)
    {
        if(i==n-1)
        {
            printf("%d\n",a[i]);
        }
        else
        {
            printf("%d\n",a[i]);
        }
    }
    return 0;
}


