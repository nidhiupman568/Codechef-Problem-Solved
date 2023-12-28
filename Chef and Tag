#include <bits/stdc++.h>
using namespace std;

int ans=0;

void dfs1(int node,vector<vector<int>>&adj,int *lev,int *vis,int d,int *leaf){
    vis[node]=1;
    lev[node]=d;
    for(int i=0;i<adj[node].size();i++)
    {
        int v=adj[node][i];
        if(vis[v]==0) 
        {
            dfs1(v,adj,lev,vis,d+1,leaf);
            leaf[node]=leaf[node]+leaf[v];
        }
    }
    if(adj[node].size()==1 && node!=1) leaf[node]=1;
}

int dfs2(int node,vector<vector<int>>&adj,int *lev,int *vis,int *leaf){
    vis[node]=1;
    int c=10000000;
    for(int i=0;i<adj[node].size();i++)
    {
        int v=adj[node][i];
        if(vis[v]==0) 
        {
            c=min(c,dfs2(v,adj,lev,vis,leaf));
        }
    }
    
    if( c<=lev[node] ) ans=max(ans,leaf[node]);
    if(c==10000000) return 1;
    return c+1;
}

int main() {
	
	int t;
	cin>>t;
	
	while(t--)
	{
	    ans=0;
	    int n;
	    cin>>n;
	    
	    vector<vector<int>> adj(n+2);
	    for(int i=0;i<n-1;i++)
	    {
	        int u,v;
	        cin>>u>>v;
	        adj[u].push_back(v);
	        adj[v].push_back(u);
	    }
	    
	    int vis[n+2];
	    int leaf[n+2];
	    int lev[n+2];
	    for(int i=1;i<=n;i++) leaf[i]=0,lev[i]=-1,vis[i]=0;
	    dfs1(1,adj,lev,vis,0,leaf);
	    
	    for(int i=1;i<=n;i++) vis[i]=0;
	    dfs2(1,adj,lev,vis,leaf);
	    
	    cout<<ans<<"\n";
	}
	
	
	return 0;
}
