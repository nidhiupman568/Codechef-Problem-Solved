#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        bool poss=false;
        for(int i=0;i<n;i++){
            if(mp[arr[i]]>1){
                poss=true;
                cout<<1<<endl;
                cout<<arr[i]<<endl;
                break;
            }
        }
        
        if(poss==false)
        cout<<-1<<endl;
        
    }
}
