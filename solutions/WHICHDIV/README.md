# [Which Division (WHICHDIV)](https://www.codechef.com/problems/WHICHDIV)

- **Difficulty Rating**: 867
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to categorize a competitive programmer into one of three divisions based on their rating ($R$):
- **Division 1**: Rating is 2000 or higher ($R \ge 2000$).
- **Division 2**: Rating is at least 1600 but less than 2000 ($1600 \le R < 2000$).
- **Division 3**: Rating is less than 1600 ($R < 1600$).

Given $T$ test cases, we need to output the division number for each given rating.

## Intuition & Mathematical Observation
The problem is a straightforward implementation of conditional logic. Since the conditions are mutually exclusive and cover all possible integer values of $R$, we can use an `if-else if-else` structure:

1. First, check if $R \ge 2000$. If true, the answer is `1`.
2. If the first condition fails, check if $R \ge 1600$. Since we already know $R < 2000$ (because the first check failed), this correctly identifies Division 2.
3. If both previous conditions fail, it implies $R < 1600$, which corresponds to Division 3.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and do not use any auxiliary data structures that scale with input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Which Division
 * Logic:
 * - Division 1: R >= 2000
 * - Division 2: 1600 <= R < 2000
 * - Division 3: R < 1600
 * 
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only use a few variables.
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long r;
        cin >> r;
        
        if (r >= 2000) {
            cout << 1 << "\n";
        } else if (r >= 1600) {
            cout << 2 << "\n";
        } else {
            cout << 3 << "\n";
        }
    }
    
    return 0;
}
```