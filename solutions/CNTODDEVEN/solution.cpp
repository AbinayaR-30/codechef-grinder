#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Given an integer N, we need to count its odd divisors and even divisors.
 * A divisor d of N is odd if d % 2 != 0.
 * A divisor d of N is even if d % 2 == 0.
 * 
 * Since the constraints are small (N <= 100), we can iterate from 1 to N
 * and check if each number is a divisor of N, then categorize it.
 * 
 * Time Complexity: O(T * N)
 * Space Complexity: O(1)
 */

void solve() {
    int N;
    cin >> N;
    
    int odd_count = 0;
    int even_count = 0;
    
    for (int i = 1; i <= N; ++i) {
        if (N % i == 0) {
            if (i % 2 != 0) {
                odd_count++;
            } else {
                even_count++;
            }
        }
    }
    
    cout << odd_count << " " << even_count << "\n";
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