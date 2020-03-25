#include <bits/stdc++.h>
#define MAXN 1007
using namespace std;
struct Point { int x,y,c; };
int n,m,k,way[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
char dt[MAXN][MAXN]; bool f[MAXN][MAXN];
queue<Point> Q; 
int main() {
    memset(f,0,sizeof(f));
    scanf("%d %d",&n,&m);
    for (int i=0;i<n;i++) {
        scanf("%s",dt[i]);
        for (int j=0;j<m;j++)
            if (dt[i][j]=='g')
                f[i][j]=true,Q.push((Point){i,j,0});
    }
    scanf("%d",&k);
    while(!Q.empty()) {
        Point now=Q.front(); Q.pop();
        if (now.c==k) break;
        for (int i=0;i<4;i++) {
            int tx=now.x+way[i][0],ty=now.y+way[i][1];
            if (tx<0 || tx>n || ty<0 || ty>m) continue;
            dt[tx][ty]='g';
            if (!f[tx][ty]) Q.push((Point){tx,ty,now.c+1});
        }
    }
    for (int i=0;i<n;i++) printf("%s\n",dt[i]);
    return 0;
} 
