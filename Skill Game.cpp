#include "bits/stdc++.h"



using namespace std;


using ll = long long;
using vi = vector<int>;

#define endl '\n'
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()

const int MX = 300005;

char str[MX];
int M;

struct BIT {
	int v[MX];
	int n, pw;
	void init(int m) {
		n = m;
		fill_n(v, n + 1, 0);
		for (pw = 1; pw * 2 <= n; pw *= 2);
	}
	void add(int k, int d) {
		k = M - k + 1;
		for (; k <= n; k += k & -k){
			v[k] = max(v[k], d);
		}
	}
	int get(int k) {
		k = M - k + 1;
		int s = 0;
		for (; k > 0; k -= k & -k) s = max(s, v[k]);
		return s;
	}
}bt;

int s[MX];
int mx[MX], x[MX];
int sum[MX], t[MX], mn[MX];

void solve() {
	int n;
	cin >> n;
	M = n;
	cin >> str;
	for (int i = 1; i <= n; i ++) sum[i] = 0, t[i] = 0;
	
	for (int i = 0; i < n; i ++) {
		cin >> s[i];
		if (str[i] == 'B') sum[s[i]] ++;
		t[s[i]] ++;
	}
	
	for (int i = 1; i <= n; i ++) {
		sum[i ] = sum[i - 1] + sum[i];
		t[i] = t[i - 1] + t[i];
	}
	
	for (int i = 0; i < n; i ++) {
		if (str[i] == 'B') mn[i] = min(i + 1, t[s[i] - 1]);
		else mn[i] = 0;
	}
	
	int cnt = 0;
	for (int i = 0; i < n; i ++) {
		if (str[i] == 'A') cnt ++;
	}
	
	mn[n] = 0;
	mx[n] = 0;
	for (int i = n - 1; i >= 0; i --) {
		if (str[i] == 'B') mx[i] = max(mx[i + 1], s[i]);
		else mx[i] = mx[i + 1];
		mn[i] = max(mn[i + 1], mn[i]);
	}
	
	bt.init(n + 1);
	
	for (int i = 0; i < n; i ++){
		if (str[i] == 'A') {
			if (s[i] < mx[i+1] || i + 1 < mn[i + 1]) continue;
			
			x[i] = sum[s[i] - 1];
			
			int id = bt.get(s[i] + 1);
			if (id == 0) {
				cout << 0 << endl;
				return;
			}
			
//			if (s[i] != 1) 
			x[i] += (cnt - 1);
			
			if (x[i] >= id && x[i] >= mn[i + 1]) {
				
//				if (s[i] == 1) {
//					cout << 0 << endl;
//					return;
//				}
				int tot = 0;
				for (int j = 0; j < n; j ++) {
					if (j == i) continue;
					if(str[j] == 'B') continue;
					
					if (s[j] > 1 && s[i] < s[j]) tot ++;
				}
				cout << tot << endl;
				for (int j = 0; j < n; j ++) {
					if (j == i) continue;
					if (str[j] == 'B') continue;
					if (s[j] > 1 && s[i] < s[j]) {
						cout << j + 1 << " " << s[i] << endl;
					}
				}
				return;
			}
		}
		else {
			bt.add(s[i], i+1);
		}
	}
	cout << -1 << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif

	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int tc = 1;
	cin >> tc;
	while (tc --) solve();

	return 0;
}
