#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The distance of a point (x, y) from the origin (0, 0) is given by the formula:
 * Distance = sqrt(x^2 + y^2)
 * To compare the distances of Alex (X1, Y1) and Bob (X2, Y2), we can compare
 * the squared distances to avoid floating point precision issues and the 
 * computational cost of sqrt().
 * 
 * Squared Distance_Alex = X1^2 + Y1^2
 * Squared Distance_Bob = X2^2 + Y2^2
 * 
 * Constraints: -1000 <= X, Y <= 1000
 * Max squared distance = 1000^2 + 1000^2 = 2,000,000.
 * This fits comfortably within a standard 32-bit signed integer, 
 * but using long long is good practice to prevent overflow in similar problems.
 */

void solve() {
    long long x1, y1, x2, y2;
    if (!(cin >> x1 >> y1 >> x2 >> y2)) return;

    long long distSqAlex = (x1 * x1) + (y1 * y1);
    long long distSqBob = (x2 * x2) + (y2 * y2);

    if (distSqAlex > distSqBob) {
        cout << "ALEX" << "\n";
    } else if (distSqBob > distSqAlex) {
        cout << "BOB" << "\n";
    } else {
        cout << "EQUAL" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}