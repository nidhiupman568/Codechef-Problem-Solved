#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;cin>>tc;
    while(tc--){
        int n,w;
        cin>>n>>w;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        
        
            int sum=0,res=0;
            for(int i=n-1;i>=0;i--){
                if(sum<w){
	               sum+=arr[i];
	            }
	             else{
	                res++;
	            }
            }
            cout<<res<<endl;
        
    }
	return 0;
}
