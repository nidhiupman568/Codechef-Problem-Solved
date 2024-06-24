#include <bits/stdc++.h>
#define lil long long int
const int MOD = 1e9 + 7;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int test;cin>>test;
	while(test--)
	{
	    lil n,m;cin>>n>>m;
	    int x=m%n;
	    int y=n-x;
	    int ans=min(x,y);
	    if(m<n) cout<<n-m<<endl;
	    else
	    cout<<ans<<endl;
	    
	}

}
