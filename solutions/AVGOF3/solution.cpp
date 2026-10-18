#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find three distinct integers A1, A2, A3 such that:
 * (A1 + A2 + A3) / 3 = X
 * This implies A1 + A2 + A3 = 3 * X.
 * 
 * We can choose A1 = X - 1, A2 = X, and A3 = X + 1.
 * Let's check the conditions:
 * 1. Mean: ((X - 1) + X + (X + 1)) / 3 = (3X) / 3 = X. (Satisfied)
 * 2. Distinct: Since X >= 2, X-1, X, and X+1 are always distinct.
 * 3. Constraints: 1 <= A1, A2, A3 <= 1000.
 *    Given 2 <= X <= 100:
 *    - Minimum A1 = 2 - 1 = 1. (Valid)
 *    - Maximum A3 = 100 + 1 = 101. (Valid, since 101 <= 1000)
 * 
 * This construction works for all given constraints.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int x;
        cin >> x;
        
        // Using the construction A1 = x-1, A2 = x, A3 = x+1
        // For x=2: 1, 2, 3 (Mean = 2, Distinct, Valid)
        // For x=100: 99, 100, 101 (Mean = 100, Distinct, Valid)
        cout << (x - 1) << " " << x << " " << (x + 1) << "\n";
    }

    return 0;
}