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
    string s;
    cin >> s;
    set<int> se;
    map<int,int> m;
    for (int i = 0; i < s.size(); i++) {
        se.insert((int)s[i]-48);
        m[(int)s[i]-48]++;
    }
    for (auto e : se) {
        if (e==6) {
            for (auto f : se) {
                if (f>=5) {
                    if (e!=f) {
                        cout << char(e*10+f);
                    }
                    else if (e==f&&m[e]>=2) {
                        cout << char(e*10+f);
                    }
                }
            }
        }
        else if (e==9) {
            for (auto f : se) {
                if (f==0) {
                    cout << 'Z';
                    break;
                }
                else {
                    break;
                }
            }
        }
        else if  (e>6) {
            for (auto f : se) {
                if (e!=f) {
                    cout << char(e*10+f);
                }
                else if (e==f&&m[e]>=2) {
                    cout << char(e*10+f);
                }
            }
        }
    }
    cout << endl;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
   	ll t;
    	cin >> t;
    	while (t--)
    	{
        	solve();
    	}
    	return 0;
}
