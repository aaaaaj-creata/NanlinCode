#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(void)
{
 char str[100];
 int i, n, s[125], max, m, ans;
 while(gets(str) != NULL)
 {
max = 0;
 memset(s, 0, sizeof(s));
n = strlen(str);
 for(i = 0; i < n; i++)
 {
 if(str[i] != ' ')
 {
 s[str[i]]++;
}


}
 for(m = 65; m <= 122; m++)
 {
 if(max < s[m])
 {
 max = s[m];
 ans = m;
 }
 }


 printf("%c %d\n", ans, max);
 }
 return 0;
}

