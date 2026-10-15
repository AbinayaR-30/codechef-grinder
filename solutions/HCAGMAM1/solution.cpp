#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - We are given a binary string of length 30.
 * - '1' represents a working day, '0' represents a leave.
 * - Total Salary = (Total number of '1's * X) + (Length of longest streak of '1's * Y).
 * - Constraints: T <= 10^4, X, Y <= 999, |S| = 30.
 * - Since the string length is small (30), a simple linear scan is O(N) per test case,
 *   which is well within the time limit for 10^4 test cases.
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;
    string s;
    cin >> s;

    long long total_working_days = 0;
    int max_streak = 0;
    int current_streak = 0;

    for (char c : s) {
        if (c == '1') {
            total_working_days++;
            current_streak++;
        } else {
            if (current_streak > max_streak) {
                max_streak = current_streak;
            }
            current_streak = 0;
        }
    }
    // Final check for streak ending at the last character
    if (current_streak > max_streak) {
        max_streak = current_streak;
    }

    long long salary = (total_working_days * X) + (max_streak * Y);
    cout << salary << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}