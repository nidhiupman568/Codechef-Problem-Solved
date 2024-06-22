#include<bits/stdc++.h>
using namespace std;
int T,n;
vector<int> G[200005];
long long dp[200005][2];
void dfs(int v,int p){
    dp[v][0]=0;
    dp[v][1]=n+(G[v].size()==1?-1:0);
    for(auto u: G[v]) if(u!=p){
        dfs(u,v);
        dp[v][0]+=dp[u][1];
        dp[v][1]+=dp[u][0];
    }
    dp[v][1]=max(dp[v][1],dp[v][0]);
}
void solve(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) G[i].clear();
    for(int i=1,u,v;i<n;i++){
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,-1);
    for(int i=1;i<=n;i++) if(G[i].size()==1) dp[1][1]++;
    printf("%lld\n",dp[1][1]/n+(dp[1][1]%n!=0));
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}
