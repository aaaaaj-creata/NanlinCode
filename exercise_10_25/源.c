#include<stdio.h>
int main()
{
	int a = 1;
	printf("%d,%d\n", a++, ++a); //2,3
	printf("%d,%d,%d,%d\n", a++, ++a, a++, ++a);  //6,7,4,7
	printf("%d,%d,%d\n", a--, --a, a++); //7,6,7


	return 0;
}