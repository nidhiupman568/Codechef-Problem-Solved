#include <bits/stdc++.h>
using namespace std;

// Function to calculate the maximum streak length in a given array
int getStreakLength(const vector<int>& arr) {
    int maxStreak = 1;
    int currentStreak = 1;
    
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i] >= arr[i - 1]) {
            currentStreak++;
        } else {
            maxStreak = max(maxStreak, currentStreak);
            currentStreak = 1;
        }
    }
    maxStreak = max(maxStreak, currentStreak); // Update for the last streak
    return maxStreak;
}
int main() {
	// your code goes here
  int T;
    cin >> T;
    
    while (T--) {
        int N, X;
        cin >> N >> X;
        
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        
        // First, find the streak length without any operation
        int maxStreak = getStreakLength(A);
        
        // Try modifying each element and check the new streak value
        for (int i = 0; i < N; ++i) {
            // Create a modified copy of the array with A[i] * X
            vector<int> modifiedA = A;
            modifiedA[i] *= X;
            
            // Check the streak value for the modified array
            maxStreak = max(maxStreak, getStreakLength(modifiedA));
        }
        
        // Output the maximum streak value found
        cout << maxStreak << endl;
    }
    
    return 0;
}
