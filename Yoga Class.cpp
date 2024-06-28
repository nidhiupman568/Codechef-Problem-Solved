#include <bits/stdc++.h>
#define lil long long int
// #define sort(xyz) sort(xyz.begin(),xyz.end())
const int MOD = 1e9 + 7;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	int test;cin>>test;
	while(test--)
	{
	    int n,x,y;
	    cin>>n>>x>>y;
	    int ans1=(n/2)*y + (n%2)*x;
	    int ans2=n*x;
	    cout<<max(ans1,ans2)<<endl;
	}

}
