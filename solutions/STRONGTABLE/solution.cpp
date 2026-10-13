#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Suppose we choose a subset of k legs with strengths W_{i_1}, W_{i_2}, ..., W_{i_k}.
 * Let the minimum strength in this subset be W_min.
 * If we place a weight X on this table, each leg bears X/k.
 * To prevent any leg from breaking, we must have X/k <= W_min, which means X <= k * W_min.
 * To maximize X for a fixed subset, we should choose the subset such that k * W_min is maximized.
 * 
 * Strategy:
 * 1. Sort the array of leg strengths in non-decreasing order: W_1 <= W_2 <= ... <= W_N.
 * 2. If we decide that the minimum strength in our subset is W_i, then to maximize the 
 *    total weight, we should include all legs with strength >= W_i.
 * 3. If we pick all legs from index i to N-1 (0-indexed), there are (N - i) such legs.
 * 4. The minimum strength in this subset is W_i.
 * 5. The maximum weight for this specific subset is (N - i) * W_i.
 * 6. We iterate through all possible i from 0 to N-1 and keep track of the maximum value.
 * 
 * Complexity:
 * Sorting takes O(N log N).
 * The iteration takes O(N).
 * Total time complexity: O(N log N) per test case.
 * Space complexity: O(N) to store the weights.
 */

void solve() {
    int n;
    cin >> n;
    vector<long long> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    
    // Sort the weights in non-decreasing order
    sort(w.begin(), w.end());
    
    long long max_weight = 0;
    
    // For each leg i, consider it as the minimum strength leg in a subset
    // containing all legs from i to n-1.
    for (int i = 0; i < n; ++i) {
        long long count = (long long)(n - i);
        long long current_weight = count * w[i];
        if (current_weight > max_weight) {
            max_weight = current_weight;
        }
    }
    
    cout << max_weight << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}