#include <iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    string s[n];
	    
	    int no_A=0;
	    int no_B=0;
	    int no_O=0;
	    int no_AB=0;
	    
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>s[i];
	        
	        if(s[i]=="A")
	        {
	            no_A++;
	        }
	        else if(s[i]=="B")
	        {
	            no_B++;
	        }
	        else if(s[i]=="O")
	        {
	            no_O++;
	        }
	        else  if(s[i]=="AB")
	        {
	            no_AB++;
	        }
	   }
	   
	   int chain =no_O;
	   if(no_A>no_B)
	   {
	       chain=chain+no_A+no_AB;
	   }
	   else
	   {
	       chain+=no_B+no_AB;
	   }
	   
	   cout<<chain<<endl;
	}
	   
	   
	    
	    
}
