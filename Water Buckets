#include <bits/stdc++.h>
using namespace std;

#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int def = 1e6;
long long st[def];

void update(int l, int r, int crr, int i, int v){
	if (i < l || i > r)
		return;
	else if (l == r){
		st[crr] = v;
		return;
	}
	int mid = (l + r) / 2;
	update(l, mid, crr * 2 + 1, i, v);
	update(mid + 1, r, crr * 2 + 2, i, v);
	st[crr] = st[crr * 2 + 1] + st[crr * 2 + 2];
}

long long get(int l, int r, int crr, int ql, int qr){
	if (qr < l || ql > r)
		return 0;
	if (l >= ql && r <= qr)
		return st[crr];
	int mid = (l + r) / 2;
	return get(l, mid, crr * 2 + 1, ql, qr) + get(mid + 1, r, crr * 2 + 2, ql, qr);
}

int walk(int l, int r, int crr, long long x, long long k){
	int mid = (l + r) / 2;
	if (l == r){
		if ((x + st[crr]) > k) return l - 1;
		else return l;
	}
	if (x + st[crr * 2 + 1] <= k)
		return walk(mid + 1, r, crr * 2 + 2, x + st[crr * 2 + 1], k);
	else	
		return walk(l, mid, crr * 2 + 1, x, k);
}

int n, m;
int walk_from(int u, long long k){
	long long pref; 
	if (u == 0) pref = 0;
	else pref = get(0, n - 1, 0, 0, u - 1);
	return walk(0, n - 1, 0, -pref, k);
}

int next_block(int u, int block){
	return min((u / block + 1) * block, n);
}

int prev_block(int u, int block){
	return (u / block) * block;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie();
	cin >> n >> m;

	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i], update(0, n - 1, 0, i, a[i]);

	int q;
	cin >> q;

	int block = max((int)sqrt(n) - 50, 1);
	//Minimum bucket to escape block, ammount of water left
	pair<int, int> dp[n];
	
	for (int i = n - 1; i >= 0; i--){
		int pos = next_block(i, block);
		int nxt = walk_from(i, m);

		if ((nxt + 1) < pos)
			dp[i] = {dp[nxt + 1].first + 1, dp[nxt + 1].second};
		else
			dp[i] = {1, m - get(0, n - 1, 0, i, pos - 1)};
	}

	while (q--){
		int t;
		cin >> t;

		if (t == 1){
			int l, r;
			cin >> l >> r;

			l--; r--;
			int water = 0, res = 0;

			int u = l;
			while ((r - u) > block){
				int nxt = walk_from(u, water) + 1;
				u = nxt; water = 0;
				if ((r - u) <= block) break;

				int pos = next_block(u, block);
				res += dp[u].first; water = dp[u].second;
				u = pos;
			}
			
			for (int i = u; i <= r; i++){
				if ((water - a[i]) < 0){
					res++; water = m - a[i];
				}
				else
					water -= a[i];
			}

			cout << res << endl;
		}

		else
		{
			int u, x;
			cin >> u >> x;

			u--;
			update(0, n - 1, 0, u, x);
			a[u] = x;

			for (int i = u; i >= prev_block(u, block); i--){
				int pos = next_block(i, block);
				int nxt = walk_from(i, m);

				if ((nxt + 1) < pos)
					dp[i] = {dp[nxt + 1].first + 1, dp[nxt + 1].second};
				else
					dp[i] = {1, m - get(0, n - 1, 0, i, pos - 1)};
			}
		}
	}
}
