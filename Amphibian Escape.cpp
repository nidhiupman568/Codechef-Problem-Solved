#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long N, K, H;
        cin >> N >> K >> H;

        long long count = 0;

        // Iterate over possible values of A
        for (long long A = 1; A <= N; ++A) {
            if (A >= H) {
                // If A itself is greater than or equal to H, any B will work
                count += N;
            } else {
                // Calculate maximum B such that the frog escapes
                long long maxB = ((K * A) - H) / (K - 1);

                // Include all valid Bs that meet the condition
                // maxB should be greater than or equal to 1 and within the range [1, N]
                if (maxB > 0) {
                    count += min(maxB, N);
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}
