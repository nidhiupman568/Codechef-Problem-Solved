#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

#define UNSYNC ios::sync_with_stdio(false); cin.tie(nullptr);
#define sci(x) static_cast<int>(x)
#define all(x) x.begin(), x.end()
#define rep(i, ini, x) for (int i = ini; i < x; ++i)
#define per(i, fin, x) for (int i = fin; i >= x; --i)
#define VI vector<i64>
#define VVI vector<vector<i64>>

void solve()
{
    int N; cin >> N;
    VI A (2*N); 
    rep(i, 0, 2*N){
        int x; cin >> x; --x;
        A[i] = x;
    } 

    VI dist (N, -1);
    rep(i, 0, 2*N){
        if (dist[A[i]] == -1){
            dist[A[i]] = i;
        } else {
            dist[A[i]] = i - dist[A[i]] - 1;
        }
    }
    VI io (N); iota(all(io), 0);
    sort(all(io), [&] (int i, int j) {
        return dist[i] > dist[j];
    });
    rep(i, 0, N){
        cout << io[i] + 1 << " \n"[i == N - 1];
    }
}

int main()
{
    UNSYNC
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}
