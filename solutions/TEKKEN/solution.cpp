#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Anna (A), Bob (B), and Claudio (C) fight in pairs.
 * Each fight reduces both players' health by min(X, Y).
 * Effectively, the player with lower health becomes 0, and the player with higher health
 * reduces by the amount of the lower health.
 * 
 * We want to see if Anna can have > 0 health at the end.
 * To maximize Anna's chances, we should let Bob and Claudio fight each other first.
 * After Bob and Claudio fight, the winner (whoever had more health) will have 
 * health = abs(B - C).
 * Then Anna fights this winner.
 * Anna will have positive health if A > abs(B - C).
 */

void solve() {
    long long A, B, C;
    if (!(cin >> A >> B >> C)) return;

    // First, let Bob and Claudio fight.
    // The remaining health of the survivor between Bob and Claudio is abs(B - C).
    long long survivor_BC = abs(B - C);

    // Now Anna fights the survivor.
    // Anna's final health will be A - min(A, survivor_BC).
    // This is positive if A > survivor_BC.
    if (A > survivor_BC) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}