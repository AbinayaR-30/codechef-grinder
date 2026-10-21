#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef chooses a day 'k' (1-indexed) to close the shop.
 * Total sales = (Sum of A[1] to A[k-1]) + (2 * A[k])
 * This can be rewritten as: (Sum of all A[1] to A[k]) + A[k]
 * 
 * Let S[k] be the prefix sum of the array A up to index k.
 * Total sales = S[k] + A[k]
 * 
 * We need to find max(S[k] + A[k]) for all 1 <= k <= N.
 * 
 * Constraints:
 * N up to 3*10^5, A_i up to 10^9.
 * The sum can exceed 2^31-1, so we must use long long.
 * Time complexity: O(N) per test case, total O(sum of N).
 * Space complexity: O(N) to store the array.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long current_prefix_sum = 0;
    long long max_sales = -1; // Sales are positive, so -1 is safe

    for (int i = 0; i < n; ++i) {
        current_prefix_sum += a[i];
        // Total sales if we close on day i+1 is (prefix_sum_up_to_i) + a[i]
        long long current_total = current_prefix_sum + a[i];
        if (current_total > max_sales) {
            max_sales = current_total;
        }
    }

    cout << max_sales << "\n";
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