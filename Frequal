#include <bits/stdc++.h>
#define ll long long int
#define double long double
#define inf (int)1e16
using namespace std;

const int MOD = 1000000007;
const int MOD2 = 998244353;

vector<ll> primes;
vector<bool> isPrime;
void sieve() {
    isPrime = vector<bool>(200001, true);
    isPrime[0] = isPrime[1] = false;
    for(ll i = 2; i * i < 200001; i++) {
        if(isPrime[i]) {
            for(int j = i * i; j < isPrime.size(); j += i) {
                isPrime[j] = false;
            }
        }
    }
    for(int i = 2; i < 200001; i++) {
        if(isPrime[i]) primes.push_back(i);
    }
}

long long fibonacci(int N) {
    long long A = 1, B = 1;
    for(int i = 3; i <= N; i++) {
        long long temp = (A + B) % MOD;
        A = B;
        B = temp;
    }
    return B;
}

int countZeroes(ll N) {
    int count = 0;
    while(N) {
        count += (N % 2 == 0);
        N /= 2;
    }
    return count;
}

int countSetBits(ll N) {
    int count = 0;
    while(N) {
        count += (N % 2 == 1);
        N /= 2;
    }
    return count;
}

ll pow(ll x, ll y) {
    if(y == 0) return 1;
    if(y % 2 == 0) return pow(x * x, y / 2);
    return x * pow(x * x, y / 2);
}

ll powMOD(ll x, ll y) {
    x %= MOD;
    if(y == 0) return 1;
    if(y % 2 == 0) return powMOD(x * x, y / 2) % MOD;
    return (x * powMOD(x * x, y / 2)) % MOD;
}

ll powMOD2(ll x, ll y) {
    x %= MOD2;
    if(y == 0) return 1;
    if(y%2 == 0) return powMOD2(x*x, y/2) % MOD2;
    return (x * powMOD2(x*x, y/2)) % MOD2;
}

void solve(ll N) {
    vector<ll> numDivisors(N + 1, 0);

    for(ll i = 1; i <= N; i++) {
        for(ll j = i; j <= N; j += i) {
            numDivisors[j]++;
        }
    }

    ll count = 0;
    for(ll i = 1; count < N; i++) {
        for(ll j = 0; (j < numDivisors[i]) && (count < N); j++) {
            count++;
            cout << i << " ";
        }
    }
}

int main() {
    // your code goes here
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    sieve();
    ll T, N;
    cin >> T;
    while(T--) {
        cin >> N;
        if(N % 2 == 1) cout << 1 << " ";
        if(N > 1)
        for(int i = 0; i < N / 2; i++) {
            cout << primes[i] << " " << primes[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
