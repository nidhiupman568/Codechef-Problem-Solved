#pragma GCC optimize("O2,no-stack-protector,unroll-loops,fast-math")
#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define PB push_back
#define F first
#define S second
#define uset unordered_set
#define umap unordered_map
#define MP make_pair;
#define vt vector
#define all(x) begin(x), end(x)
#define sz(x) (int)x.size()
#define REP(i, a) for (int i = 0; i < a; i++)
#define pii pair<int, int>;
#define pll pair<ll, ll>;

using namespace std;

typedef vector<ll> vl;
typedef pair<ll,ll> pl;

void solve()
{
    ll n,m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        ll d;
        cin >> d;
        if (d<n+1||d>3*n) {
            cout << 0 << endl;
        }
        else {
            if (d>2*n+1) {
                cout << abs(d-3*n)+1 << endl;
            }
            else {
                cout << d-n-1 << endl;
            }
        }
    }
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
   	ll t;
    	t=1;
    	while (t--)
    	{
        	solve();
    	}
    	return 0;
}
