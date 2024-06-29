#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t,n;
	int flag;
	int help;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    flag=0;
	    help=0;
	    vector<int>vec(n,0);
	    vector<int>store(n,0);
	    for(auto &it:vec)
	    {
	        cin>>it;
	    }
	    for(int i=0;i<n;i++)
	    {
	        if(store[vec[i]-1]==0)
	           flag++;
	        store[vec[i]-1]++;  //I'll get the count
	    }
	    if(flag==vec.size())
	       cout<<"Yes\n";
	    else
	    {
	        for(int i=0;i<n;i++)
	        {
	            if(store[i]>1)
	            help+=store[i]-1;
	            if(store[i]==0&&help>=1)
	            {
	                help--;
	                flag++;
	            }
	        }
	        if(flag==vec.size())
	           cout<<"Yes\n";
	        else
	           cout<<"No\n";
	    }
	}
	return 0;
}	
	
