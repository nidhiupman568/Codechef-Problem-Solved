#include<bits/stdc++.h>
#define int long long
const int mod = 1e9+7;
#define endl "\n"
using namespace std;

bool prime[100001];

void SieveOfEratosthenes()
{
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= 1e5; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= 1e5; i += p)
                prime[i] = false;
        }
    }
}
 
bool isPerfectSquare(int x)
{
    if (x >= 0) {
        int sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}


int32_t main() {
    SieveOfEratosthenes();
    int t;
    cin>>t;
    for(int i = 0;i<t;i++){
       int n;
       cin>>n;
       n -= 4;
       if(n < 34){
           cout << "NO" << endl;
           continue;
       }
       vector<int> primes;
       for(int j = 3;j<100001;j++){
           if(prime[j]) primes.push_back(j);
       }
       int flag = 0;
       for(int j = 0;j<primes.size();j++){
           int val = primes[j] * primes[j];
           val = n - val;
           if(val < 0){
               break;
           }
           if(isPerfectSquare(val)){
               int c = sqrt(val);
               if(prime[c]){
                   flag = 1; break;
               }
           }
       }
       flag ? cout << "YES" << endl : cout << "NO" << endl;
    }
}
