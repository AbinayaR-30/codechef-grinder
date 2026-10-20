#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a sorted list A of size N.
 * For each A[i], we need to find the count of elements strictly greater than A[i].
 * Since the array is sorted, for any element A[i], all elements strictly greater 
 * than A[i] will appear after the last occurrence of A[i] in the array.
 * 
 * Approach:
 * 1. Since N is small (up to 100), an O(N^2) approach is perfectly acceptable.
 * 2. For each element A[i], iterate through the array and count elements > A[i].
 * 3. Alternatively, since the array is sorted, we can use upper_bound to find 
 *    the first element strictly greater than A[i] and subtract its index from N.
 *    This would be O(N log N).
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    for (int i = 0; i < N; ++i) {
        // Find the first element strictly greater than A[i]
        // Since A is sorted, we can use upper_bound
        auto it = upper_bound(A.begin(), A.end(), A[i]);
        
        // The number of elements strictly greater is the distance from 
        // the iterator to the end of the vector
        long long count = distance(it, A.end());
        
        cout << count << (i == N - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}