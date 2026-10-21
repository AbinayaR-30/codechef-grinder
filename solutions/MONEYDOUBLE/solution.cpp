#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * At each year, we have two choices: add 1000 or double.
 * Since Y is small (up to 10), we can explore all 2^Y possible sequences 
 * of operations to find the maximum amount.
 */

long long findMax(long long x, int y) {
    // Base case: no more years left
    if (y == 0) {
        return x;
    }
    
    // Option 1: Add 1000
    long long option1 = findMax(x + 1000, y - 1);
    
    // Option 2: Double the amount
    long long option2 = findMax(x * 2, y - 1);
    
    // Return the maximum of the two paths
    return max(option1, option2);
}

void solve() {
    long long x;
    int y;
    cin >> x >> y;
    
    cout << findMax(x, y) << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}