#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have R red, B blue, and G green gems.
 * Each gem sells for 3 coins individually.
 * A bundle of (1R, 1B, 1G) sells for 10 coins.
 * 
 * Let k be the number of bundles we make.
 * k can range from 0 to min(R, B, G).
 * If we make k bundles, we use k of each gem.
 * Remaining gems: (R-k) red, (B-k) blue, (G-k) green.
 * Total coins = (k * 10) + ((R-k) + (B-k) + (G-k)) * 3
 *             = 10k + 3(R + B + G - 3k)
 *             = 10k + 3(R + B + G) - 9k
 *             = k + 3(R + B + G)
 * 
 * To maximize this, we need to maximize k.
 * Since k is the number of bundles, the maximum k is min(R, B, G).
 * 
 * Time Complexity: O(T)
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long r, b, g;
        cin >> r >> b >> g;

        // Maximum number of bundles possible
        long long k = min({r, b, g});

        // Calculate max coins
        // Formula: k * 10 + (remaining gems) * 3
        // remaining gems = (r - k) + (b - k) + (g - k)
        long long total_gems = r + b + g;
        long long ans = (k * 10) + (total_gems - 3 * k) * 3;

        cout << ans << "\n";
    }

    return 0;
}