#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    int a[n];
	    int sum = 0;
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	        sum += a[i];
	    }
	    
	    if(sum%2 == 0){
	        cout << n << endl;
	        continue;
	    }
	    
	    int i = 0;
	    int j = n-1;
	    
	    while(a[i]%2 == 0){
	        i++;
	    }
	    while(a[j]%2 == 0){
	        j--;
	    }
	    
	    int leftsize = i+1;
	    int rightsize = n - j;
	    
	    cout << max(n-leftsize, n-rightsize) << endl;
	}

}
