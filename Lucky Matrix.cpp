#include <bits/stdc++.h>
using namespace std;

// Macros
#define pb          push_back
#define pf          push_front
#define ff          first
#define ss          second
#define all(v)      v.begin(), v.end()
#define rall(v)     v.rbegin(), v.rend()

#define rep(i, x, n)   for(ll i = x; i < n; ++i)
#define rrep(i, x, n)  for(ll i = x; i >= n; --i)

// Read and Print
#define read(a, i, n) for(ll i = 0; i < n; ++i) cin >> a[i];
#define print(a, i, n) for(ll i = 0; i < n; ++i){ cout << a[i] << " ";} cout << "\n";

// Typedefs
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pii;

typedef vector <ll> vi;
typedef vector <vector <ll>> vvi;

// Constants
const ll mxn = 1e5 + 5;
const ll mod = 1e9 + 7;

// Fast IO
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}

// Solve
vector <ll> f(mxn);

// LogN method for Calculating Power
ll fastPower(ll b, ll e){
	ll ans = 1ll;
	while(e){
		if(e & 1ll){
			ans *= b;
			ans %= mod;
			--e;
		}
		else{
			b *= b;
			b %= mod;
			e >>= 1ll;
		}
	}

	return ans % mod;
}

// Calculate Multipliclative Inverse
ll mmi(ll b){
	return fastPower(b, mod - 2) % mod;
}

// Preprocess factorials from 1 to Max Limit [1e5]
void factorial(){
	f[0] = 1ll;
	for(ll i = 1ll; i < mxn; ++i){
		f[i] = (f[i - 1] * i) % mod;
	}	
}

// Calculate nCr for a given value of n and r
ll ncr(ll n, ll r){
	if(r > n) return 0;
	ll ans = (f[n] * mmi(f[r])) % mod;
	ans *= mmi(f[n - r]); ans %= mod;
	return ans;
}

// Main solution function
void solve() {
    ll n, m, k, x, y;
    cin >> n >> m >> k >> x >> y;

// Store the probability as a product of x * y^-1 [x * inverse(y)]
    ll p = (x * mmi(y)) % mod;

// Set ans to 0
    ll ans = 0ll;

    for(ll s = 1ll; s <= min(k, n); ++s){

// Answer given sum required = s is : (nCs) * ((1 + (1 - 2p)^s) / 2)^m
// Calculate the same

    	ll v1 = ncr(n, s);

    	ll v2 = (1ll - ((2 * p) % mod) + mod) % mod; // ***Keep in mind to handle overflows and underflows
    	v2 = fastPower(v2, s);
    	v2 += 1ll; v2 %= mod;
    	v2 *= mmi(2ll); v2 %= mod;
    	v2 = fastPower(v2, m);

    	ll cans = v1 * v2; cans %= mod;

// Add the result to ans    	
    	ans += cans; ans %= mod;
    }

    cout << ans << "\n";
}

int main(){
    
    fast();

    factorial();

    ll t;
    cin >> t;

    while(t--){
        solve();
    }

    return 0;
}
