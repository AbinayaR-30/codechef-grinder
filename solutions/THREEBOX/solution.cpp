#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have three boxes with sizes A, B, and C, and bags of size D.
 * Constraints: 1 <= A <= B <= C <= D <= 100.
 * 
 * Strategy:
 * 1. If A + B + C <= D, we only need 1 bag.
 * 2. If A + B + C > D, we check if we can fit two boxes in one bag.
 *    Since A <= B <= C, the largest possible pairs are (A+B), (A+C), or (B+C).
 *    If (A + B + C) > D, we definitely need at least 2 bags.
 *    If (A + B) <= D, we can put A and B in one bag, and C in another (2 bags).
 *    If (A + C) <= D, we can put A and C in one bag, and B in another (2 bags).
 *    If (B + C) <= D, we can put B and C in one bag, and A in another (2 bags).
 *    However, since A <= B <= C, if (A + C) <= D, then (A + B) is also <= D.
 *    If (B + C) > D and (A + C) > D and (A + B) > D, we need 3 bags.
 * 
 * Simplified Logic:
 * - If A + B + C <= D: 1 bag
 * - Else if A + B <= D or A + C <= D: 2 bags (Note: B+C > D is implied if A+B+C > D)
 * - Else: 3 bags
 */

void solve() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    if (A + B + C <= D) {
        cout << 1 << "\n";
    } else if (A + B <= D || A + C <= D) {
        // We can fit two boxes in one bag, leaving the third in another.
        // Since A <= B <= C, if A+B > D, then A+C and B+C are definitely > D.
        // If A+B <= D, we use 2 bags.
        cout << 2 << "\n";
    } else {
        // Cannot fit any pair in one bag.
        cout << 3 << "\n";
    }
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