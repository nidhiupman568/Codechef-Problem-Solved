#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        map<int,int>m;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            m[arr[i]]++;
        }
        int A=0;
        for(auto i: m){
            if(i.second>A){
                A=i.second;
            }
        }
        cout<<n-A<<endl;
        
    }
}
