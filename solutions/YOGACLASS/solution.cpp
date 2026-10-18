#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has N hours.
 * Type 1: 1 hour, earns X.
 * Type 2: 2 hours, earns Y.
 * 
 * Since Y > X, we want to maximize the number of Type 2 sessions.
 * Each Type 2 session takes 2 hours.
 * Number of Type 2 sessions possible = N / 2.
 * Remaining hours = N % 2.
 * These remaining hours must be filled with Type 1 sessions.
 * 
 * Total earnings = (N / 2) * Y + (N % 2) * X.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x, y;
        cin >> n >> x >> y;

        // We want to use as many 2-hour sessions as possible because Y > X.
        // Even if Y < 2*X, the problem states Y > X, but it doesn't guarantee Y > 2*X.
        // However, since we want to maximize earnings, we compare:
        // Option 1: Maximize Type 2 sessions: (n/2)*Y + (n%2)*X
        // Option 2: Use only Type 1 sessions: n*X
        
        long long max_earnings = 0;
        
        // Strategy: Use as many 2-hour blocks as possible
        long long num_type2 = n / 2;
        long long num_type1 = n % 2;
        
        long long earnings_with_type2 = (num_type2 * y) + (num_type1 * x);
        
        // Strategy: Use only 1-hour blocks
        long long earnings_only_type1 = n * x;
        
        max_earnings = max(earnings_with_type2, earnings_only_type1);
        
        cout << max_earnings << "\n";
    }

    return 0;
}