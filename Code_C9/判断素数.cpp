#include <stdio.h>
int main()
{
	int a = 0,i = 0; 
	scanf ("%d",&a);
	for (i = a - 1;i >1;i--)
	{
   		if (a % i == 0)
   		{
       		printf ("This is not a prime.");
       		break ;
   		}
	} 
	if (i == 1)
    printf ("This is a prime.");
 
    return 0;
}

