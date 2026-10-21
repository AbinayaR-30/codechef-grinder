#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to determine if a permutation of length N can have exactly K fixed points.
 * 
 * 1. If we choose K indices to be fixed points (P[i] = i), we are left with (N - K) 
 *    elements that must be deranged (no element i is at position i).
 * 2. A derangement of size M exists if and only if M != 1.
 *    - If M = 0, there is 1 derangement (the empty set).
 *    - If M = 1, there are 0 derangements (impossible to have 0 fixed points in a set of 1).
 *    - If M >= 2, there is always at least one derangement.
 * 
 * Therefore, the condition is:
 * - We can always pick K fixed points.
 * - The remaining (N - K) elements must be able to form a derangement.
 * - This is possible if (N - K) != 1.
 * - So, if N - K == 1, it is impossible. Otherwise, it is possible.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;

        // If N - K == 1, we are left with exactly one element that cannot be 
        // a fixed point, which is impossible.
        if (n - k == 1) {
            cout << "No" << "\n";
        } else {
            // For all other cases (N-K == 0 or N-K >= 2), a valid permutation exists.
            // N-K == 0: All elements are fixed points (Identity permutation).
            // N-K >= 2: We can swap elements to ensure no fixed points in the remaining set.
            cout << "Yes" << "\n";
        }
    }

    return 0;
}