#include <bits/stdc++.h>
int n,ans=0;
using namespace std;
void dfs(int num) 
{
    for (int i=num%10?num%10:1;i<=9;i++)
        if (num*10+i<=n) ans++,dfs(num*10+i);
}

int main() 
{
    scanf("%d",&n),dfs(0);
    printf("%d",ans); 
    return 0;
}
