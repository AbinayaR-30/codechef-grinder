#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The array A is defined as A[i] = i for 1 <= i <= N.
 * The sum of all elements in the array is TotalSum = N * (N + 1) / 2.
 * The condition given is:
 * (A[1] + ... + A[x-1]) + (A[x+1] + ... + A[N]) = S
 * This is equivalent to:
 * (TotalSum - A[x]) = S
 * Since A[x] = x, the equation becomes:
 * TotalSum - x = S
 * x = TotalSum - S
 * 
 * We need to check if the calculated x satisfies 1 <= x <= N.
 * 
 * Constraints:
 * N <= 10^9, so TotalSum can be up to ~5 * 10^17, which fits in a 64-bit integer (long long).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, s;
        cin >> n >> s;

        // Calculate the sum of the first N natural numbers
        // Use __int128_t or careful multiplication to avoid overflow if N was larger,
        // but with N=10^9, N*(N+1)/2 fits in long long (max ~5e17).
        long long total_sum = n * (n + 1) / 2;

        // Derived formula: x = TotalSum - S
        long long x = total_sum - s;

        // Check if x is within the valid range [1, N]
        if (x >= 1 && x <= n) {
            cout << x << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}