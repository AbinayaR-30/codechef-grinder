#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef's total penalty = X + (P * 10)
 * Chefina's total penalty = Y + (Q * 10)
 * We need to compare these two values and output the winner.
 * 
 * Constraints:
 * X, Y <= 100
 * P, Q <= 100
 * Max penalty = 100 + (100 * 10) = 1100.
 * This fits well within a standard integer, but using long long is safe practice.
 */

void solve() {
    long long X, Y, P, Q;
    if (!(cin >> X >> Y >> P >> Q)) return;

    long long chef_penalty = X + (P * 10);
    long long chefina_penalty = Y + (Q * 10);

    if (chef_penalty < chefina_penalty) {
        cout << "Chef" << "\n";
    } else if (chefina_penalty < chef_penalty) {
        cout << "Chefina" << "\n";
    } else {
        cout << "Draw" << "\n";
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