#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * We need to find the minimum number of days to screen N students with a capacity of K per day.
 * This is equivalent to ceil(N / K).
 * Using integer arithmetic, ceil(N / K) = (N + K - 1) / K.
 * 
 * Complexity:
 * Time: O(T), where T is the number of test cases.
 * Space: O(1).
 */

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n, k;
        if (!(cin >> n >> k)) break;

        // Calculate ceil(n / k) using integer arithmetic
        // (n + k - 1) / k is the standard way to perform ceiling division
        int days = (n + k - 1) / k;
        
        cout << days << "\n";
    }

    return 0;
}