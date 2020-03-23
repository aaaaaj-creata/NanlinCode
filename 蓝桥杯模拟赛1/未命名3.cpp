#include <bits/stdc++.h>

inline bool isy(char x)
{
	if(x=='a'||x=='e'||x=='i'||x=='o'||x=='u')
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	char str[233];
	int f[4],pos,len;
	scanf("%s",str),len=strlen(str);
    while (!isy(str[pos]) && pos<len) f[0]=true,pos++;
    while (isy(str[pos]) && pos<len) f[1]=true,pos++;
    while (!isy(str[pos]) && pos<len) f[2]=true,pos++;
    while (isy(str[pos]) && pos<len) f[3]=true,pos++;   
    puts(f[0]&&f[1]&&f[2]&&f[3]&&len==pos?"yes":"no");
    return 0;
	
}
