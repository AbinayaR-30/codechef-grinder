#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an array of size 2N.
 * We can swap A[i] with A[2N + 1 - i] (1-indexed).
 * This means for each pair (A[i], A[2N + 1 - i]), we can choose which 
 * element goes into the first half (indices 1 to N) and which goes into 
 * the second half (indices N+1 to 2N).
 * 
 * To maximize the sum of the first N elements, for each pair (A[i], A[2N + 1 - i])
 * where 1 <= i <= N, we should pick the larger of the two values to be in the 
 * first half.
 * 
 * Complexity:
 * Time: O(N) per test case.
 * Space: O(N) to store the array.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(2 * N);
    for (int i = 0; i < 2 * N; ++i) {
        cin >> A[i];
    }

    long long max_sum = 0;
    // We iterate through the first N elements and compare them with their mirror counterparts.
    // The mirror of A[i] (0-indexed) is A[2N - 1 - i].
    for (int i = 0; i < N; ++i) {
        max_sum += max(A[i], A[2 * N - 1 - i]);
    }

    cout << max_sum << "\n";
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