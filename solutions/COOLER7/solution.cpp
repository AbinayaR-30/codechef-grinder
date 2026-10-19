#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The air conditioner takes X minutes to drop the temperature from X to X-1.
 * To go from N to M, we need to drop the temperature by (N - M) degrees.
 * 
 * Let the current temperature be T.
 * To go from T to T-1, it takes T minutes.
 * To go from N to M, we sum the time for each step:
 * Step 1: N to N-1 takes N minutes.
 * Step 2: N-1 to N-2 takes N-1 minutes.
 * ...
 * Step (N-M): M+1 to M takes M+1 minutes.
 * 
 * Total time = N + (N-1) + (N-2) + ... + (M+1)
 * This is an arithmetic progression sum:
 * Sum = (Number of terms) * (First term + Last term) / 2
 * Number of terms = N - M
 * First term = N
 * Last term = M + 1
 * Total time = (N - M) * (N + M + 1) / 2
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;

        // Using the arithmetic series formula:
        // Sum = (n - m) * (n + m + 1) / 2
        // Since (n - m) and (n + m + 1) have different parity, 
        // their product is always even, so integer division by 2 is safe.
        long long total_time = (n - m) * (n + m + 1) / 2;
        
        cout << total_time << "\n";
    }

    return 0;
}