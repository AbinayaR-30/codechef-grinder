#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * An array is pseudo-sorted if it is already sorted or can be sorted by 
 * swapping exactly one adjacent pair (A[i], A[i+1]).
 * 
 * Strategy:
 * 1. Find the first index 'i' where A[i] > A[i+1].
 * 2. If no such index exists, the array is already sorted -> YES.
 * 3. If such an index exists, perform the swap A[i] and A[i+1].
 * 4. After the swap, check if the entire array is sorted.
 * 5. If it is sorted, output YES, otherwise NO.
 */

bool isSorted(const vector<long long>& a, int n) {
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            return false;
        }
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Find the first inversion
    int first_inversion = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            first_inversion = i;
            break;
        }
    }

    // If no inversion, it's already sorted
    if (first_inversion == -1) {
        cout << "YES" << "\n";
        return;
    }

    // Perform the swap at the first inversion point
    swap(a[first_inversion], a[first_inversion + 1]);

    // Check if the array is now sorted
    if (isSorted(a, n)) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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