#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;

ll binpow(ll a, ll b) 
{
    a%=mod;
    ll res=1;
    while (b > 0) 
    {
        if (b & 1) res = res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}

bool prime(int n)
{
    if(n<2) return false;
    if(n<4) return true;
    if(n%2==0 || n%3==0) return false;
    int i=5;
    while(i*i<=n)
    {
        if(n%i==0 || n%(i+2)==0) return false;
        i+=6;
    }
    return true;
}

int gcd(int a, int b)
{
    if (a==0) return b;
    if (b==0) return a;
    int k;
    for (k=0;((a|b)&1)==0;++k) 
    {
        a>>=1;
        b>>=1;
    }
    while((a&1)==0) a>>=1;
    do
    {
        while((b&1)==0) b>>=1;
        if(a>b) swap(a, b);
        b=(b-a);
    }while(b!=0);
    return a<<k;
}

int lcm(int a, int b)
{
    return (a/gcd(a,b))*b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    do
    {
        ll n;
        cin>>n;
        if(n==2) cout<<2*n<<" "<<8<<"\n";
        else cout<<2*n<<" "<<n*n<< endl;
    }while(--t);
    return 0;
}
