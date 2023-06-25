#include <bits/stdc++.h>
using namespace std;
bool is(int n){
    while(n>0){
        
        int c=n%2;
        if(c!=0 && n!=1){
            return false;
        }
        n=n/2;
        
    }
    return true;
}
int main() {
    int t;
    cin>>t;
    while(t--){
       int a,b;
       cin>>a>>b;
       int counter=0;
       while(!is(a)){
           if(a==1) break;
          if(a%2!=0){ a=(a-1)/2;
              counter++;
          }
          else {a=a/2;
           
           counter++;}
       }
       
       if(b>a){
           while(b>a){
           
               a=a*2;
               counter++;
               if(b==a) break;
           }
       }else if(b<a){
           while(a>b){
               
               a=a/2;
               counter++;
               if(b==a)  break;
           }
       }
       cout<<counter<<endl;
        
        
    }
	return 0;
}
