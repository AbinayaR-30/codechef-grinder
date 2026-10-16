#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to satisfy: A[0] <= A[1] >= A[2] <= A[3] >= A[4] ...
 * 
 * Strategy:
 * 1. Sort the array in non-decreasing order.
 * 2. If we have a sorted array A[0] <= A[1] <= A[2] <= A[3] <= A[4]...
 * 3. We can swap adjacent pairs (A[i], A[i+1]) for all odd i.
 *    Specifically, if we swap (A[1], A[2]), (A[3], A[4]), etc.,
 *    the condition A[i] <= A[i+1] for even i and A[i] >= A[i+1] for odd i
 *    will be satisfied because:
 *    - A[0] <= A[1] (original sorted)
 *    - After swapping (A[1], A[2]), we have A[1] >= A[2]
 *    - Since A[2] <= A[3] (original sorted), the sequence becomes:
 *      A[0] <= A[1] >= A[2] <= A[3] >= A[4] ...
 * 
 * Complexity:
 * Time: O(N log N) due to sorting.
 * Space: O(N) to store the array.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    // Swap adjacent elements starting from index 1
    // i=1: swap(a[1], a[2])
    // i=3: swap(a[3], a[4])
    for (int i = 1; i + 1 < n; i += 2) {
        swap(a[i], a[i + 1]);
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
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