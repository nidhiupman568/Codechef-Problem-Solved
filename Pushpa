#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int x;
	    cin>>x;
	    int arr[x];
	    map<int,int>mp;
	   for(int i=0;i<x;i++){
	       cin>>arr[i];
	       mp[arr[i]]++;
	   }
	   int sum=0;
	   for(auto i : mp){
	       sum =max(sum,(i.first+i.second-1));
	   }
	   cout<<sum<<endl;
	   
	}
	return 0;
}
