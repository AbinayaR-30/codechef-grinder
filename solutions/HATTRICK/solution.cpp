#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given 6 inputs representing the outcome of 6 balls in an over.
 * A hattrick occurs if there are 3 consecutive 'W's.
 * We can store the 6 inputs in an array or vector and check all possible
 * windows of size 3: (0,1,2), (1,2,3), (2,3,4), (3,4,5).
 * If any of these windows contain 'W' at all three positions, output YES.
 * Otherwise, output NO.
 */

void solve() {
    vector<string> balls(6);
    for (int i = 0; i < 6; ++i) {
        cin >> balls[i];
    }

    bool hattrick = false;
    // Check windows of size 3
    for (int i = 0; i <= 3; ++i) {
        if (balls[i] == "W" && balls[i + 1] == "W" && balls[i + 2] == "W") {
            hattrick = true;
            break;
        }
    }

    if (hattrick) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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