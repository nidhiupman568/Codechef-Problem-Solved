#include<bits/stdc++.h>
using namespace std;

#define md                  1000000007
#define pb                  push_back
#define endl                " \n"
#define F                   first
#define S                   second
#define sz(x)               (int)(x).size()   
#define inp(v)              for(auto &x: v) cin>>x  
#define all(x)              (x).begin(), (x).end()
#define rep(i, a, b)        for (int i = a; i < (b); ++i)
#define fast_io             cin.tie(0)->sync_with_stdio(0);cin.exceptions(cin.failbit);

using ll  = long long;
using ull = unsigned long long;
using lld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vl  = vector<ll>;
using vi  = vector<int>;


void dk(){
     ll n;
     cin>>n;
     vl v(n);
     inp(v);
     char cur='1';
     ll freq=0;
     stack<pair<char,ll>>st;
     for(auto i:v){
          if(i==cur){
               freq++;
          }else{
               if(freq>0){
                    st.push({cur,freq});
               }
               cur=i;
               freq=1;
          }
     }
     if(freq>0){
          st.push({cur,freq});
     }
     ll ind=0;
     while(!st.empty()){
          stack<pair<char,ll>>temp;
          while(!st.empty()){
               auto top=st.top();
               top.S--;
               st.pop();
               if(top.S>0){
                    if(!temp.empty() and temp.top().F==top.F){
                         temp.top().S+=top.S;
                    }else{
                         temp.push(top);
                    }
               }
          }
          swap(st,temp);
          ind++;
     }
     cout<<(ind%2?"Alice":"Bob")<<endl;    
}



int main()
{ 
    fast_io;
    
    int _=1;
    cin>>_;
    for(int i=0;i<_;i++){
    dk();
   }
  return 0;
}   
