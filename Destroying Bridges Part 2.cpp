// designed by Choco
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
#define hurryupchoco iosbase::syncwith_stdio(false);cin.tie();cout.tie()
#define endl '\n'
#define fori for(ll i=0; i<n; i++)
#define forj for(ll j=0; j<n; j++)
#define form for(ll i=0; i<m; i++)
#define fors for(ll i=0; i<s.size(); i++)
#define forv for(ll i=0; i<v.size(); i++)
#define forst for(auto i=st.begin(); i!=st.end(); i++)
#define formst for(auto i=mst.begin(); i!=mst.end(); i++)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define f first
#define s second
#define sorta sort(a,a+n)
#define sortv sort(v.begin(), v.end())
#define sorts sort(s.begin(), s.end())
#define mod 9929
#define INF 1000000001
#define reverses reverse(s.begin(),s.end())
int main(){
    ll t;
    cin>>t;
    while(t--){
        //cout<<"HAI THIS IS"<<t<<endl;
        ll n,c;
        cin>>n>>c;
        ll a[n+1];
        ll sum=0;
        fori{
            cin>>a[i];
            sum+=a[i];
        }
        if(a[0]*(sum-a[0])<=c){
        cout<<1<<endl;
        continue;
        }
        sorta;
        ll csum=0;
        ll maximumsum=0,index=0;
        for(ll i=0;i<n;i++){
            csum+=a[i];
            ll aha=csum*(sum-csum);
            //cout<<i<<' '<<aha<<endl;
            if(aha<=c){
            maximumsum=aha;
            index=i+1;
            }
            else
            break;
        }
        if(index==0)
        cout<<n<<endl;
        else if(n-(index)>0){
        cout<<n-(index)<<endl;
        }
    }
}
