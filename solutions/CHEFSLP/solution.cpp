#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total slippers = N
 * Left slippers = L
 * Right slippers = R = N - L
 * A pair consists of one left and one right slipper.
 * The number of pairs that can be formed is limited by the minimum of the 
 * number of left slippers and the number of right slippers.
 * Pairs = min(L, N - L)
 * Total revenue = Pairs * X
 * 
 * Constraints:
 * N, L, X <= 1000. 
 * Max revenue = 1000 * 1000 = 1,000,000.
 * This fits within a standard 32-bit integer, but using long long is safer 
 * for competitive programming practices.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, l, x;
        cin >> n >> l >> x;

        // Calculate number of right slippers
        long long r = n - l;

        // Number of pairs is the minimum of left and right slippers
        long long pairs = min(l, r);

        // Total earnings
        long long result = pairs * x;

        cout << result << "\n";
    }

    return 0;
}