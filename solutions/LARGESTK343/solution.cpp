#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have X zeros and Y ones.
 * We want to place these zeros such that there are at least K ones between any two adjacent zeros.
 * If we have X zeros, there are (X - 1) gaps between them.
 * Let the number of ones in each gap be g_1, g_2, ..., g_{X-1}.
 * The condition is that g_i >= K for all i = 1 to X-1.
 * The total number of ones used in these gaps is sum(g_i) = G_total.
 * We must have G_total <= Y.
 * To maximize K, we want to distribute the ones such that the minimum gap is as large as possible.
 * The total number of ones required to satisfy a gap of size K is K * (X - 1).
 * Therefore, we need K * (X - 1) <= Y.
 * K <= Y / (X - 1).
 * 
 * Since K must be an integer, the largest K is floor(Y / (X - 1)).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long X, Y;
        cin >> X >> Y;

        // X is the number of 0s.
        // There are X-1 gaps between the X zeros.
        // We need to distribute Y ones into these X-1 gaps such that each gap has at least K ones.
        // K * (X - 1) <= Y
        // K <= Y / (X - 1)
        
        long long gaps = X - 1;
        long long K = Y / gaps;
        
        cout << K << "\n";
    }

    return 0;
}