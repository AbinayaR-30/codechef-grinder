# [Hattrick (HATTRICK)](https://www.codechef.com/problems/HATTRICK)

- **Difficulty Rating**: 853
- **Solved in**: 1 attempt(s)

## Problem Summary
Given the outcomes of 6 consecutive balls in a cricket over (where each outcome is either 'W' for a wicket or some other character for a non-wicket), determine if a "hattrick" occurred. A hattrick is defined as taking 3 wickets in 3 consecutive balls. If such a sequence exists, output `YES`; otherwise, output `NO`.

## Intuition & Mathematical Observation
Since the input size is fixed at 6 balls, we can represent the sequence as an array or a vector of strings. A hattrick occurs if there exists an index $i$ such that the elements at $i, i+1,$ and $i+2$ are all equal to "W".

Given the constraints:
- The total number of balls is 6.
- We need to check for a sequence of length 3.
- The possible starting indices for a window of size 3 are $0, 1, 2,$ and $3$.

By iterating through these indices and checking the condition `balls[i] == "W" && balls[i+1] == "W" && balls[i+2] == "W"`, we can determine if a hattrick has occurred. If the condition is met at any point, we can immediately conclude `YES` and stop checking.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since the number of balls is fixed at 6, the loop runs a constant number of times (4 iterations), making the execution time independent of input size.
- **Space Complexity**: $O(1)$. We only store 6 strings, which occupies a constant amount of memory.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given 6 inputs representing the outcome of 6 balls in an over.
 * A hattrick occurs if there are 3 consecutive 'W's.
 * We can store the 6 inputs in an array or vector and check all possible
 * windows of size 3: (0,1,2), (1,2,3), (2,3,4), (3,4,5).
 * If any of these windows contain 'W' at all three positions, output YES.
 * Otherwise, output NO.
 */

void solve() {
    vector<string> balls(6);
    for (int i = 0; i < 6; ++i) {
        cin >> balls[i];
    }

    bool hattrick = false;
    // Check windows of size 3
    for (int i = 0; i <= 3; ++i) {
        if (balls[i] == "W" && balls[i + 1] == "W" && balls[i + 2] == "W") {
            hattrick = true;
            break;
        }
    }

    if (hattrick) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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