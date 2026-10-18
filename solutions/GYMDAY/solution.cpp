#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has budget Y and membership cost X.
 * Each trial session costs 1 coin.
 * After n trial sessions:
 * - Remaining budget: Y - n
 * - Discount: n * D %
 * - Membership cost: X * (100 - n * D) / 100
 * 
 * We need to find the minimum n >= 0 such that:
 * (Y - n) >= X * (100 - n * D) / 100
 * 
 * Constraints are very small (X <= 50).
 * Since n cannot exceed Y (because he needs at least 0 coins left),
 * we can iterate n from 0 to Y and check the condition.
 * 
 * Condition: (Y - n) * 100 >= X * (100 - n * D)
 */

void solve() {
    int D, X, Y;
    cin >> D >> X >> Y;

    // If he can already afford it without any sessions
    if (Y >= X) {
        cout << 0 << "\n";
        return;
    }

    // Iterate through possible number of sessions
    // He can take at most Y sessions because each costs 1 coin
    for (int n = 1; n <= Y; ++n) {
        // Remaining budget after n sessions: Y - n
        // Discounted price: X * (100 - n * D) / 100
        // Use cross-multiplication to avoid floating point issues:
        // (Y - n) * 100 >= X * (100 - n * D)
        
        long long remaining_budget = (long long)(Y - n) * 100;
        long long discounted_price = (long long)X * (100 - n * D);
        
        if (remaining_budget >= discounted_price) {
            cout << n << "\n";
            return;
        }
    }

    // If no n works
    cout << -1 << "\n";
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