# [Chef And Salary Pay (HCAGMAM1)](https://www.codechef.com/problems/HCAGMAM1)

- **Difficulty Rating**: 1269
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef receives a salary based on his attendance over a period of 30 days, represented by a binary string $S$. 
- For every day he worked ('1'), he earns $X$ amount.
- Additionally, he receives a bonus based on his longest consecutive streak of working days, calculated as (length of longest streak of '1's) $\times Y$.
- We need to calculate the total salary earned by Chef.

## Intuition & Mathematical Observation
The problem requires two distinct pieces of information from the string $S$:
1. **Total count of '1's**: This is a simple linear traversal where we increment a counter whenever we encounter a '1'.
2. **Longest streak of '1's**: We maintain a `current_streak` counter that increments when we see a '1' and resets to 0 when we see a '0'. We keep track of the `max_streak` encountered so far.

**Key Edge Case:** If the string ends with a '1', the streak might not be updated inside the loop (since the reset condition `c == '0'` won't trigger). Therefore, we must perform a final check after the loop to update `max_streak` if the `current_streak` at the end is the largest.

The total salary is then calculated using the formula:
$$\text{Salary} = (\text{Total '1's} \times X) + (\text{Max Streak} \times Y)$$

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string (fixed at 30). Given $T$ test cases, the total time complexity is $O(T \times N)$, which is approximately $3 \times 10^5$ operations, well within the 1-second time limit.
- **Space Complexity**: $O(N)$ to store the input string, or $O(1)$ if processed character by character.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - We are given a binary string of length 30.
 * - '1' represents a working day, '0' represents a leave.
 * - Total Salary = (Total number of '1's * X) + (Length of longest streak of '1's * Y).
 * - Constraints: T <= 10^4, X, Y <= 999, |S| = 30.
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
```