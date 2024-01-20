#include <bits/stdc++.h>
using namespace std;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less<int>, rb_tree_tag,
// tree_order_statistics_node_update> ordered_set;
#define int long long int
#define ld long double
#define pb push_back
#define fi first
#define se second
#define rz resize
#define ii pair<int, int>
#define vii vector<pair<int,int>>
#define vv vector<vector<int>>
#define vv vector<vector<int>>
#define vi vector<int>
#define endl "\n"
#define pb push_back
#define be begin
#define up upper_bound
#define lo lower_bound
#define bi binary_search
#define si set<int>
#define msi multiset<int>
#define mii map<int, int>
#define all(v) v.begin(), v.end()
#define mems1(a) memset(a, -1, sizeof(a))
#define mems0(a) memset(a, 0, sizeof(a))
#define rep(i, s, e) for (int i = s; i < e; i++)
#define rrep(i, s, e) for (int i = s - 1; i >= e; i--)
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define pr cout<<"a"<<endl
int dp[1005][1005][2];
int n,m,k;
vv a;
vector<string>s;
int rec(int i,int j,int last){
    if(i==n-1&&j==m-1){
        return 0;
    }
    if(dp[i][j][last]!=-1)return dp[i][j][last];
    dp[i][j][last]=1e15;
    if(i+1<n){
        int ans=a[i+1][j]+rec(i+1,j,1);
        if(s[i+1][j]=='1')ans+=k;
        if(j+1<m&&s[i][j+1]=='1')ans+=k;
        if(j-1>=0&&last==1&&s[i+1][j-1]=='1')ans+=k;
        dp[i][j][last]=min(dp[i][j][last],ans);
    }
    if(j+1<m){
        int ans=a[i][j+1]+rec(i,j+1,0);
        if(last==0&&i-1>=0&&s[i-1][j+1]=='1')ans+=k;
        if(s[i][j+1]=='1')ans+=k;
        if(i+1<n&&s[i+1][j]=='1')ans+=k;
        dp[i][j][last]=min(dp[i][j][last],ans);
    }
    return dp[i][j][last];
}
void solve(){
    cin>>n>>m>>k;
    a.clear();
    s.clear();
    a.rz(n,vi(m));
    s.rz(n);
    rep(i,0,n){
        rep(j,0,m){
            cin>>a[i][j];
            dp[i][j][0]=-1;
            dp[i][j][1]=-1;
        }
    }
   // memset(dp,-1,sizeof(dp));
    rep(i,0,n)cin>>s[i];
    cout<<rec(0,0,0)<<endl;


    
    
}  
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solve();
    }
}
