#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The array contains the first N positive odd numbers.
 * The first N positive odd numbers are: 1, 3, 5, ..., (2N - 1).
 * The sum of the first N positive odd numbers is N^2.
 * 
 * Let x be the number that appears K times.
 * The array consists of all N odd numbers (sum = N^2), but one of them (x) 
 * is replaced by x repeated K times instead of once.
 * 
 * Effectively, the sum S is:
 * S = (Sum of first N odd numbers) - x + (K * x)
 * S = N^2 - x + K * x
 * S = N^2 + x * (K - 1)
 * 
 * Rearranging to solve for x:
 * x * (K - 1) = S - N^2
 * x = (S - N^2) / (K - 1)
 * 
 * Constraints:
 * N <= 10^4, so N^2 <= 10^8.
 * S <= 10^9.
 * K <= 10^4.
 * All calculations fit within a standard 64-bit integer (long long).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, k, s;
        cin >> n >> k >> s;

        // Calculate N^2
        long long n_squared = n * n;

        // Calculate the repeated number x
        // x = (S - N^2) / (K - 1)
        long long x = (s - n_squared) / (k - 1);

        cout << x << "\n";
    }

    return 0;
}