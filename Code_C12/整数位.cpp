#include<stdio.h>
#include<string.h>
int main()
{
	char s[6];
	int i,a;
	scanf("%s",&s);
	printf("%d\n",strlen(s));
	a=strlen(s)-1;
	for (i=0;i<strlen(s)-1;i++)
	printf("%c ",s[i]);
	printf("%c",s[a]);
	printf("\n");
	for (i=0;i<strlen(s);i++)
	printf("%c ",s[strlen(s)-i-1]);
	return 0;

}

