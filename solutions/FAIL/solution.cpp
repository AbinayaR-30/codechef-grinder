#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs his average to be >= 40 after EACH test.
 * Let S_k be the sum of marks after k tests.
 * The condition is: (S_k / k) >= 40 for all 1 <= k <= N.
 * This is equivalent to: S_k >= 40 * k.
 * 
 * Constraints:
 * N <= 100, A_i <= 100.
 * The maximum sum S_k is 100 * 100 = 10,000.
 * This fits comfortably within a standard integer, but we use long long 
 * as per the instructions for safety.
 */

void solve() {
    int N;
    cin >> N;
    
    long long current_sum = 0;
    bool possible = true;
    
    for (int i = 1; i <= N; ++i) {
        long long marks;
        cin >> marks;
        current_sum += marks;
        
        // Check if average >= 40 after the i-th test
        // Average = current_sum / i
        // Condition: current_sum / i >= 40  =>  current_sum >= 40 * i
        if (current_sum < 40LL * i) {
            possible = false;
        }
    }
    
    if (possible) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}