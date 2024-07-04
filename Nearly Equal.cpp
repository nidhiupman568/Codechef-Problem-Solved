#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
    int n, m; cin >> n >> m;
    string a,b; cin >> a >> b;

    int ans=INT_MAX;
    for(int i=0; i<=n-m; i++){
        int cnt=0;
        for(int j=0; j<m; j++){
            if(a[i+j] != b[j]) cnt++;
        }
        ans = min(ans, cnt);
    }

    cout<<ans<<endl;
}	


int main() {
    int t=1; 
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
