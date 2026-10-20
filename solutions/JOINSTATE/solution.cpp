#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of size N. We want to partition the array into the 
 * maximum number of contiguous subarrays such that the sum of each subarray 
 * is at least M.
 * 
 * Greedy Strategy:
 * Iterate through the array and maintain a running sum of the current segment.
 * As soon as the running sum reaches or exceeds M, we count this as a valid 
 * state and reset the running sum to 0 to start forming the next state.
 * Since we want to maximize the number of states, we should "close" a state 
 * as soon as the condition (sum >= M) is met. Any remaining elements that 
 * cannot form a sum >= M at the end are effectively merged into the last 
 * valid state (or if no state was formed, they are part of the only state).
 * 
 * Complexity:
 * Time: O(N) per test case, O(Sum of N) total.
 * Space: O(N) to store the array, or O(1) if processed on the fly.
 */

void solve() {
    int N;
    long long M;
    cin >> N >> M;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    int state_count = 0;
    long long current_sum = 0;
    
    for (int i = 0; i < N; ++i) {
        current_sum += A[i];
        if (current_sum >= M) {
            state_count++;
            current_sum = 0;
        }
    }
    
    cout << state_count << "\n";
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