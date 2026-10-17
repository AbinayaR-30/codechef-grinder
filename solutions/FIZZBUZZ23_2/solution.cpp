#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total family members = 5.
 * Daily consumption = 5 * X.
 * Number of days the buns last = floor(N / (5 * X)).
 * Total survival days = (days buns last) + D.
 * 
 * Constraints:
 * N < 500, X <= 10, D < 20.
 * The total consumption per day is 5 * X, which is at most 50.
 * The number of days the buns last is N / (5 * X).
 * Since N is small, integer division handles the "not enough buns" condition
 * automatically because if N < (5 * X), N / (5 * X) becomes 0.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x, d;
        cin >> n >> x >> d;

        // Total buns consumed by the family per day
        long long daily_consumption = 5 * x;

        // Number of days the buns can sustain the family
        // If n < daily_consumption, this results in 0 days.
        long long days_with_buns = n / daily_consumption;

        // Total survival time is the days with buns plus the extra D days
        long long total_days = days_with_buns + d;

        cout << total_days << "\n";
    }

    return 0;
}