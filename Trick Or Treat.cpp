
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
	    lil n,m;cin>>n>>m;
	    map<lil,lil> mp;
	    lil a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	        mp[(a[i]%m)]++;
	    }
	       
	    lil b;
	    lil c=0;
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>b;
	        lil rem=b%m;
	        lil x=(m-rem)%m;
	        if(mp.find(x)!=mp.end())
	        {
	            c+=mp[x];
	        }
	        
	    }
	     
	    cout<<c<<endl;
	    
	}

}
