#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an array of N distinct integers.
 * Operation: Select adjacent pair (A[i], A[i+1]), remove the larger one, cost = smaller one.
 * We need to reduce the array to a single element.
 * 
 * Let the minimum element in the array be 'min_val'.
 * To minimize the total cost, we want to use 'min_val' as the cost for as many operations as possible.
 * Since we can pick any adjacent pair, we can always choose to keep the minimum element 
 * and use it to eliminate all other elements one by one.
 * 
 * Specifically, if we have the minimum element at some position, we can eliminate its 
 * immediate neighbor (cost = min_val), then the new neighbor (cost = min_val), and so on, 
 * until only the minimum element remains.
 * 
 * Total cost = min_val * (N - 1).
 * 
 * Constraints:
 * N <= 50,000
 * Ai <= 10^5
 * Total cost can be up to 50,000 * 10^5 = 5 * 10^9, which exceeds the range of a 32-bit integer.
 * We must use 'long long' for the cost calculation.
 */

void solve() {
    int n;
    cin >> n;
    
    long long min_val = 200000; // Larger than max possible Ai
    for (int i = 0; i < n; ++i) {
        long long val;
        cin >> val;
        if (val < min_val) {
            min_val = val;
        }
    }
    
    // The minimum element will be the cost for all N-1 operations
    long long total_cost = min_val * (long long)(n - 1);
    cout << total_cost << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}