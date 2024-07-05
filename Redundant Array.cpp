#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int arr[n];
	    
	    map<int, int> mp;
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	        mp[arr[i]]++;
	    }
	    
	    long long int minval = INT_MAX;
	    
	    for(auto it : mp){
	        minval = min(minval, (long long int)(n-it.second)*it.first);
	    }
	    
	    cout << min(minval, (long long int)n) << endl;
	}

}
