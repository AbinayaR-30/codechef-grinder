#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * RCB needs X points from Y matches.
 * Win = 2 points, Tie = 1 point, Loss = 0 points.
 * Let w be the number of wins, t be the number of ties, and l be the number of losses.
 * We have:
 * 1) w + t + l = Y
 * 2) 2*w + 1*t + 0*l = X
 * We want to minimize w.
 * From (2), t = X - 2*w.
 * Since t >= 0, we must have 2*w <= X, so w >= ceil(X/2).
 * Also, since w + t <= Y (because l >= 0), we substitute t:
 * w + (X - 2*w) <= Y
 * X - w <= Y
 * w >= X - Y
 * 
 * Combining these, w must be at least max(0, X - Y).
 * Since we want to minimize w, the answer is max(0, X - Y).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long X, Y;
        cin >> X >> Y;

        // If X <= Y, we can get all points by tying matches, so 0 wins needed.
        // If X > Y, we need at least (X - Y) wins to cover the deficit.
        // Example: X=10, Y=5 -> 10-5 = 5 wins.
        // Example: X=1, Y=5 -> 1-5 = -4 -> max(0, -4) = 0 wins.
        long long ans = max(0LL, X - Y);
        cout << ans << "\n";
    }

    return 0;
}