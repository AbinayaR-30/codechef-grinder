#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * We want to reach N kg using 1kg weights (20 rupees) and 2kg weights (30 rupees).
 * Cost = 20x + 30y, where x + 2y = N.
 * Substituting x = N - 2y:
 * Cost = 20(N - 2y) + 30y = 20N - 10y.
 * To minimize cost, we maximize y.
 * Max y = N / 2.
 * 
 * Example N=3:
 * y = 3/2 = 1.
 * x = 3 - 2(1) = 1.
 * Cost = 20(1) + 30(1) = 50. Correct.
 */

void solve() {
    long long n;
    if (!(cin >> n)) return;
    
    // Maximize the number of 2kg weights to minimize cost
    long long y = n / 2;
    long long x = n % 2;
    
    long long min_cost = (x * 20) + (y * 30);
    
    cout << min_cost << "\n";
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