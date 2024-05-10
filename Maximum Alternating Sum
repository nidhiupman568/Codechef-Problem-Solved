#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        long long int sum =0;
        for(int i=0;i<n/2;i++)
        {
            sum = sum - a[i];
        }
        for(int i=n/2;i<n;i++)
        {
            sum = sum + a[i];
        }
        
        cout<<sum<<endl;
        
    }
	// your code goes here

}
