#include <stdio.h>
 
int main()
{
   int a = 0,sum = 0;
 
    for (scanf ("%d",&a);a > 0;a--)
        sum += a;
    printf ("%d",sum);
    return 0;
}
