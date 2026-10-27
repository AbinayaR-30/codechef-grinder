#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef is at X, target is Y.
 * Moves:
 * 1. k -> k + 2
 * 2. k -> k - 1
 * 
 * Let 'a' be the number of moonwalks (+2) and 'b' be the number of slides (-1).
 * We want to reach Y from X: X + 2a - b = Y
 * So, 2a - b = Y - X
 * Let D = Y - X.
 * 
 * Case 1: If D >= 0:
 * We want to minimize (a + b).
 * From 2a - b = D, we have b = 2a - D.
 * Since b must be >= 0, 2a >= D, so a >= ceil(D/2).
 * To minimize a + b = a + (2a - D) = 3a - D, we should pick the smallest possible 'a'.
 * If D is even, let a = D/2, then b = 0. Total moves = D/2.
 * If D is odd, let a = (D+1)/2, then b = 2((D+1)/2) - D = D + 1 - D = 1.
 * Total moves = (D+1)/2 + 1 = (D+3)/2.
 * 
 * Case 2: If D < 0:
 * We need to decrease the position. The only way to decrease is the slide (-1).
 * Since we need to reach Y from X where Y < X, we just need |D| slides.
 * Total moves = |D| = X - Y.
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;

    if (Y >= X) {
        long long diff = Y - X;
        if (diff % 2 == 0) {
            cout << diff / 2 << "\n";
        } else {
            // To cover an odd distance, we overshoot by 1 (using (diff+1)/2 moonwalks)
            // and then slide back once.
            // Example: 3 to 8, diff=5. (5+1)/2 = 3 moonwalks (to 9), 1 slide (to 8). Total 4.
            cout << (diff / 2) + 2 << "\n";
        }
    } else {
        // If Y < X, we only use slides.
        cout << (X - Y) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}