#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    int a[n];
	    for(int i=0; i<n; i++)
	    {
	        cin>>a[i];
	    }
	    sort(a, a+n);// ascending order.
	    double sum  =0;
	    double avg = 0.000000;   //ans should be in 6 digit after decimal point.
	    for(int i=k; i<n-k; i++) // first ans last k value will not be considered.
	    {
	        sum = sum+a[i];  // taking the sum.
	    }
	    avg = sum/(n-(2*k));//total (1st k + last k = 2*k) elements are not considered.
	    cout<<fixed<<avg<<endl;//make sure to use fixed so that the ans will be 
                                //printed till 6 decimal point.
	}
	return 0;
}
