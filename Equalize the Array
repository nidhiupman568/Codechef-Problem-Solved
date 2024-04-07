#include <bits/stdc++.h>

using namespace std;
const int N_ = 5001;

int dp[N_][N_][4];

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    int mn = 1e9, mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mn = min(mn, a[i]);
        mx = max(mx, a[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int val = mn; val <= mx; val++) {
            // dp[_][_][0] = even_len_[-1]
            // dp[_][_][1] = odd_len_[-1]
            // dp[_][_][2] = even_len_[1]
            // dp[_][_][3] = odd_len_[1]
            int a_i = a[i];
            if (a[i] > val) {
                // even length
                int op = min(a[i] - val, dp[i][val][2]);
                dp[i + 1][val][2] = dp[i][val][2] - op;
                dp[i + 1][val][1] = dp[i][val][1] + op;
                a[i] -= op;

                // odd length
                op = min(a[i] - val, dp[i][val][3]);
                dp[i + 1][val][3] = dp[i][val][3] - op;
                dp[i + 1][val][0] = dp[i][val][0] + op;
                a[i] -= op;

                dp[i + 1][val][1] += a[i] - val;

            } else {
                // even length
                int op = min(val - a[i], dp[i][val][0]);
                dp[i + 1][val][0] = dp[i][val][0] - op;
                dp[i + 1][val][3] = dp[i][val][3] + op;
                a[i] += op;

                // odd length
                op = min(val - a[i], dp[i][val][1]);
                dp[i + 1][val][1] = dp[i][val][1] - op;
                dp[i + 1][val][2] = dp[i][val][2] + op;
                a[i] += op;

                dp[i + 1][val][3] += val - a[i];
            }
            a[i] = a_i;
        }
    }

    long long int ans = 0;
    for (int i = 1; i <= n; i++) {
        int f_i = 1e9;
        for (int val = mn; val <= mx; val++) {
            // dp[_][_][0] = even_len_[-1]
            // dp[_][_][1] = odd_len_[-1]
            // dp[_][_][2] = even_len_[1]
            // dp[_][_][3] = odd_len_[1]
            f_i = min(f_i, dp[i][val][1] + dp[i][val][3] + 2 * (dp[i][val][0] + dp[i][val][2]));
        }
        ans += f_i;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
        cout << "\n";
    }

    return 0;
}
