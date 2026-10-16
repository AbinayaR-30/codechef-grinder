#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

/**
 * Problem Analysis:
 * We need to find non-negative integers x and y such that:
 * 2x + 3y = N
 * Minimize cost = 4x + 5y
 * 
 * Since N <= 100, we can iterate through all possible values of y.
 * If (N - 3y) is non-negative and divisible by 2, then x = (N - 3y) / 2 is a valid solution.
 */

void solve() {
    int N;
    cin >> N;

    int min_cost = INT_MAX;
    bool found = false;

    // Iterate through possible number of 3-flower bundles (y)
    for (int y = 0; y * 3 <= N; ++y) {
        int remaining = N - (y * 3);
        if (remaining % 2 == 0) {
            int x = remaining / 2;
            int current_cost = (x * 4) + (y * 5);
            if (current_cost < min_cost) {
                min_cost = current_cost;
                found = true;
            }
        }
    }

    if (found) {
        cout << min_cost << "\n";
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}