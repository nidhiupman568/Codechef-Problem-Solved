#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    long long n;
	    cin>>n;
	    vector<int>v(n);
	    for(auto&it:v)
	        cin>>it;
	    bool flag=0;
	    for (int i = 0; i < n - 2; i++) {
			if (v[i] > v[i + 1] && v[i + 1] > v[i + 2]) flag = 1;
		}
		if (flag)
		{
		    cout<<"0\n";
		    continue;
		}
	    if (is_sorted(v.begin(),v.end()))
	    {
	        cout<<n*(n+1)/2<<'\n';
	        continue;
	    }
	    int mx=0;
	    for(int i=1;i<n;i++)
	    {
	        if (v[i]<v[i-1])
	            mx=max(mx,v[i-1]-v[i]);
	    }
	    auto can=[&](int mid)->bool{
	        vector<int>tmp=v;
	        for(int i=1;i<n;i++)
	        {
	            if (v[i]<v[i-1])
	                v[i]+=mid;
	        }
	        if (is_sorted(v.begin(),v.end()))
	        {
	            v=tmp;
	            return 1;
	        }
	        v=tmp;
	        return 0;
	    };
	    if (!can(mx))
	    {
	        cout<<0<<'\n';
	        continue;
	    }
	    ll l=mx,r=n,mid,ans=-1;
	    while(l<=r)
	    {
	        mid=l+r>>1;
	        if (can(mid))
	            ans=mid,l=mid+1;
	        else
	            r=mid-1;
	    }
	    auto f=[&](ll x)->ll{
	        return x*(x+1)/2;
	    };
	    cout<<f(ans)-f(mx-1)<<'\n';
	}

}
