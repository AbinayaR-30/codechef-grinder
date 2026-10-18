#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A win gives 3 points, a loss gives 0 points, and a draw gives 1 point.
 * Let wA be the number of wins for A, lA be the number of losses for A, and dA be the number of draws for A.
 * Let wB be the number of wins for B, lB be the number of losses for B, and dB be the number of draws for B.
 * 
 * Since they play against each other:
 * - A's wins (wA) = B's losses (lB)
 * - A's losses (lA) = B's wins (wB)
 * - A's draws (dA) = B's draws (dB) = D (total number of draws)
 * 
 * Points for A: X = 3 * wA + D
 * Points for B: Y = 3 * wB + D
 * 
 * We want to minimize D.
 * From the equations:
 * X % 3 = (3 * wA + D) % 3 = D % 3
 * Y % 3 = (3 * wB + D) % 3 = D % 3
 * 
 * This implies that D must have the same remainder as X when divided by 3, 
 * and the same remainder as Y when divided by 3.
 * Since D is the number of draws, D % 3 must be equal to X % 3.
 * The smallest non-negative integer D satisfying D % 3 = X % 3 is simply X % 3.
 * 
 * Let's verify:
 * If X = 1, Y = 1: X % 3 = 1. D = 1. (1 = 3*0 + 1, 1 = 3*0 + 1). Correct.
 * If X = 3, Y = 0: X % 3 = 0. D = 0. (3 = 3*1 + 0, 0 = 3*0 + 0). Correct.
 * If X = 11, Y = 5: X % 3 = 2. D = 2. (11 = 3*3 + 2, 5 = 3*1 + 2). Correct.
 * If X = 9, Y = 9: X % 3 = 0. D = 0. (9 = 3*3 + 0, 9 = 3*3 + 0). Correct.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int x, y;
        cin >> x >> y;
        
        // The minimum number of draws is simply x % 3.
        // Since the problem guarantees a valid configuration exists,
        // x % 3 will always be equal to y % 3.
        cout << (x % 3) << "\n";
    }

    return 0;
}