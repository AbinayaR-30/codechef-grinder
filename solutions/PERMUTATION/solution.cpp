#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given an array A of size N. We can only increase elements.
 * We want to reach a permutation of {1, 2, ..., N}.
 * 
 * Strategy:
 * 1. Sort the array A in non-decreasing order.
 * 2. To minimize operations, we should map the smallest elements of A to the 
 *    smallest elements of the target permutation {1, 2, ..., N}.
 * 3. After sorting, if A[i] > (i + 1), it is impossible to reach the target 
 *    permutation because we can only increase elements. Thus, return -1.
 * 4. Otherwise, the cost to transform A[i] to (i + 1) is (i + 1) - A[i].
 * 5. Sum these costs for all i from 0 to N-1.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // Sort the array to greedily match smallest available values
    sort(A.begin(), A.end());

    long long total_ops = 0;
    for (int i = 0; i < N; ++i) {
        // The target value for the i-th smallest element is (i + 1)
        long long target = i + 1;
        
        // If the current element is already greater than the target,
        // we cannot decrease it, so it's impossible.
        if (A[i] > target) {
            cout << -1 << "\n";
            return;
        }
        
        // Add the difference to total operations
        total_ops += (target - A[i]);
    }

    cout << total_ops << "\n";
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