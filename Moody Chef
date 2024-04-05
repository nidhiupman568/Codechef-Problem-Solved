#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t; cin>> t; while(t--) {
        int n, l, r; cin>> n >> l  >> r; 
        int x, mx = 0, mn = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            cin>> x;
            if(x >= l && x <= r) ans++;
            else ans--;
            mx = max({mx, ans});
            mn = min({mn, ans});
        }
        cout << mx << " " << mn << endl;
    }
}
