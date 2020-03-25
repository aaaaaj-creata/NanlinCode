#include <bits/stdc++.h>
#define MAXN 100007
using namespace std;
struct Seg { int val,id; }st[MAXN][20];
int n,m,k,v[MAXN];
inline void init() {
    for (int j=1;j<=log2(n);j++)
        for (int i=1;i<=n-(1<<j)+1;i++) {
            if (st[i][j-1].val<st[i+(1<<(j-1))][j-1].val)
                st[i][j]=st[i+(1<<(j-1))][j-1];
            else st[i][j]=st[i][j-1];
        }
}
inline Seg q(int l,int r) {
    int t=log2(r-l+1);
    if (st[l][t].val>=st[r-(1<<t)+1][t].val) return st[l][t];
    else return st[r-(1<<t)+1][t];
}
int main() {
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&st[i][0].val),st[i][0].id=i;
    init(),k=1;
    for (int i=m;i>=1;i--) {
        Seg now=q(k,n-i+1);
        k=now.id+1,printf("%d ",now.val);
    }
    return 0;
} 
