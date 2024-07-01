#include <bits/stdc++.h>
#define int long long
using namespace std;

/*
   3
   4 5
   2 8 3 10
   5 12 15 13
   3 1
   1000000000 1000000000 1000000000
   1000000000 1000000000 1000000000
   1 100
   23
   76
*/

void solve(){
   int n ; cin >> n ;
   if( n == 1 ){
      cout << 1 <<"\n" ; return ;
   }
   if( n == 2 ){
      cout << 1 <<" "<< 2 <<"\n" ; return ;
   }
   if( n == 3 ) {
      cout << 1 <<" "<< 2 << " "<<  3 <<"\n"; return ;
   }
   
   if( (n&1) != 0 ){
      // n is odd ! 
      int j = n-1 ;
      int i = 1 ;
      int times = (n-1)/2;
       while( times-- ){
          cout << i <<" " << j <<" ";
          i++; 
          j--;
       }
       cout << n <<"\n" ;return ;
      
   }else{
      // n is even ! 
      int i = 1 , j = n ;
       int times = (n)/2;
       while( times-- ){
          cout << i <<" " << j <<" ";
          i++; 
          j--;
       }
       cout <<"\n" ;
       return;
   }
}
                
signed main(){
            ios::sync_with_stdio(0);
            cin.tie(0);
            cout.tie(0);
          int tc ; cin >> tc ;

          while( tc-- ){
             solve();
          }
}
