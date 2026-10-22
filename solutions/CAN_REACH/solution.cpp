#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * To reach (x, y) from (0, 0) by moving exactly K units at a time:
 * The total displacement in x must be a multiple of K (x = n * K).
 * The total displacement in y must be a multiple of K (y = m * K).
 * Therefore, the condition is simply (x % K == 0) AND (y % K == 0).
 */

void solve() {
    int x, y, K;
    if (!(cin >> x >> y >> K)) return;
    
    // Check if both x and y are divisible by K
    if (x % K == 0 && y % K == 0) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}