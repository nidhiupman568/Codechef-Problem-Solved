#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod=1e9+7;
ll fact[1000005],inv_fact[1000005];
ll modpow(ll a,ll n){
    ll res=1;
    while(n>0){
        if(n%2){
            res=(res*a)%mod;
        }
        n/=2;
        a=(a*a)%mod;
    }
    return res;
}

void pre_cum(){
    fact[0]=1;
    inv_fact[0]=1;
    
    for(ll i=1;i<=1000000;i++){
        fact[i]=(fact[i-1]*i)%mod;
        inv_fact[i]=modpow(fact[i],mod-2);
    }
    
}

ll get_ncr(ll n,ll r){
    if(r>n){
        return 0;
    }
    
    if(r<0){
        return 0;
    }
    
    ll ans=fact[n];
    ans=(ans * inv_fact[r])%mod;
    ans=(ans * inv_fact[n-r])%mod;
    
    return ans;
}
int main() {
	// your code goes here
    ll t;
    cin>>t;
    pre_cum();
    
    while(t--){
        ll n,m;
        cin>>n>>m;
        
        vector<ll> prefix_sum(m+2,0);
        for(ll i=1;i<=m;i++){
            prefix_sum[i]=(prefix_sum[i-1]+get_ncr(i,n-2))%mod;
            
        }
        
        ll ans=0;
        
        for(ll x1=1;x1<=m;x1++){
            
            // if x1 is the smallest element;
            // let x2 be second smallest elememt
            // then number of combs possible is==>
            // min(m+1,x1+x2)-x2-1 C (n-2)
            // for computation :
            // where x1+x2<=M+1 expression is (x1-1) C (n-2).
            
            ll exp1=get_ncr(x1-1,n-2);
            ll cnt_exp1=max(0ll,(m-x1+1)-(x1+1)+1);
            ans=ans+(exp1*cnt_exp1)%mod;
            ans%=mod;
            
            //where x1+x2>=M+1 expression is (M-x2) C (n-2).
            ll en=max(0ll,min(x1-2,m-x1-1));
            
            ans=ans+(prefix_sum[en]+mod)%mod;
            ans%=mod;
            
            
            
            
            
            
        }
        
        cout<<ans<<endl;
        
        
    }
}
