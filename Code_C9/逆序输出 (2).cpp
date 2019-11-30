#include<stdio.h>  
#include<math.h>  
int main()  
{     
    int a,b1,b2,b3 ;
	scanf("%d",&a);
	if(a<100||a>1000) return 0;
    b1=a/100;
	b2=a%100/10;
	b3=a%10;
    if(b3==0&&b2==0)printf("%d",b1);
	else if(b3==0)printf("%d%d",b2,b1);
    else printf("%d%d%d",b3,b2,b1);
    return 0;  
}  

