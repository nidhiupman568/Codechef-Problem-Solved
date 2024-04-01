#include "bits/stdc++.h"
using namespace std;
using ll = long long int;
mt19937_64 RNG(chrono::high_resolution_clock::now().time_since_epoch().count());

template<class T, T unit = T()>
struct SegTree {
    T f(T a, T b) { return a+b; }
    vector<T> s; int n;
    SegTree(int _n = 0, T def = unit) : s(2*_n, def), n(_n) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) {
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2) ra = f(ra, s[b++]);
            if (e % 2) rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    const int N = 3e5 + 10;
    int t; cin >> t;
    vector<vector<array<int, 2>>> queries(N);
    for (int i = 0; i < t; ++i) {
        int L, R; cin >> L >> R;
        queries[L].push_back({R, i});
    }

    SegTree<ll> seg(N);
    vector<ll> ans(t);

    vector<vector<int>> facs(N);
    for (int i = 1; i < N; ++i)
        for (int j = i; j < N; j += i)
            facs[j].push_back(i);
    vector<int> pos(N);
    for (int i = 1; i < N; ++i) pos[i] = facs[i].size();
    
    for (int L = N-1; L >= 1; --L) {
        for (int x = L; x < N; x += L) {
            int l = 1;
            --pos[x];
            for (int i = pos[x]; ; ++i) {
                l = lcm(l, facs[x][i]);
                if (l == x) {
                    seg.update(x, facs[x][i]);
                    break;
                }
            }
        }
        for (auto [R, id] : queries[L]) {
            ans[id] = seg.query(0, R+1);
        }
    }
    for (auto x : ans) cout << x << '\n';
}
