#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given X and Y. We want to reach a state where X >= 2Y or Y >= 2X.
 * In one operation, we can change X or Y by +1 or -1.
 * Since the constraints are very small (X, Y <= 10), we can use a simple 
 * brute-force approach or a greedy approach.
 * 
 * Given the constraints are small, we can check all possible target values 
 * for X' and Y' within a reasonable range and find the minimum operations.
 * However, since we only need to reach a state where X >= 2Y or Y >= 2X,
 * we can simply iterate through all possible changes.
 * 
 * Let's consider the target states:
 * 1. X' >= 2 * Y'
 * 2. Y' >= 2 * X'
 * 
 * Since we want the minimum operations, we can perform a Breadth-First Search (BFS)
 * or simply iterate through a small range of possible values for X and Y.
 * Given X, Y <= 10, the target values will not be very far from the original values.
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;

    long long min_ops = 1e18;

    // We can change X to X' and Y to Y' such that |X-X'| + |Y-Y'| is minimized.
    // Given the constraints are small, we can check a range around X and Y.
    // A range of [0, 30] is sufficient for X, Y <= 10.
    for (int i = 0; i <= 30; ++i) {
        for (int j = 0; j <= 30; ++j) {
            if (i == 0 || j == 0) continue; // Problem states positive integers
            
            if (i >= 2 * j || j >= 2 * i) {
                long long ops = abs(X - i) + abs(Y - j);
                if (ops < min_ops) {
                    min_ops = ops;
                }
            }
        }
    }
    cout << min_ops << "\n";
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