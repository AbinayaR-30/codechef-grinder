#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs 10 packets.
 * Options:
 * - 2 packets for X
 * - 4 packets for Y
 * 
 * We need to form 10 using combinations of 2 and 4.
 * Possible combinations (number of 4-packs, number of 2-packs):
 * 1. (0, 5): 0 * Y + 5 * X = 5X
 * 2. (1, 3): 1 * Y + 3 * X = Y + 3X
 * 3. (2, 1): 2 * Y + 1 * X = 2Y + X
 * 
 * Since Y <= 2X, the cost of 4 packets (Y) is always less than or equal to 
 * the cost of two 2-packs (2X). Therefore, we should prioritize using 
 * the 4-pack as much as possible to minimize the cost.
 * 
 * Comparing the combinations:
 * - 5X vs Y + 3X: 
 *   Since Y <= 2X, Y + 3X <= 2X + 3X = 5X. So (1, 3) is always <= (0, 5).
 * - Y + 3X vs 2Y + X:
 *   Since Y <= 2X, 2Y + X <= Y + 2X + X = Y + 3X. So (2, 1) is always <= (1, 3).
 * 
 * Thus, the minimum cost is always 2Y + X.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long x, y;
        cin >> x >> y;
        
        // Based on the logic derived, the optimal strategy is to buy 
        // two 4-packs and one 2-pack to reach 10 packets.
        long long min_cost = 2 * y + x;
        
        cout << min_cost << "\n";
    }

    return 0;
}