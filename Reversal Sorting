#include <iostream>
#include <limits>
using namespace std;

constexpr auto max_size = std::numeric_limits<std::streamsize>::max();

int main() {
    // Speed up input and output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
	    int N, X;
	    cin >> N >> X;
	    
	    int mx=0; // the max element
	    bool res = true;
	    
	    while (N--) {
	        int i;
	        cin >> i;
	        if (i >= mx)
	            // store the highest element so far
	            mx = i;
	        else if (i+mx > X) {
	            // we will never be able to swap i and mx
	            res = false;        
	            break;
	        }
	    }
	    cout << (res ? "YES" : "NO") << endl;
	    if (N>0) cin.ignore(max_size, '\n');
	}
	return 0;
}
