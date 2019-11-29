#include<stdio.h>
int main()
{
	int a,b;
	char op;
	scanf ("%d\n%d",&a,&b);
	fflush(stdin);
	scanf ("%c",&op);
	switch (op)
	{
		case '+':
			printf("%d\n",a+b);
			break;
		case '-':
			printf("%d\n",a-b);
			break;
		case '*':
			printf("%d\n",a*b);
			break;
		case '/':
			if (b==0)
				printf("Divided by zero\n");
			else
				printf("%d\n",a/b);
			default:
				printf("input error\n")	;	
	}
	
	return 0;
}
