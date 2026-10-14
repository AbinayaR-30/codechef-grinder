# [Opposite Attract (P2169)](https://www.codechef.com/problems/P2169)

- **Difficulty Rating**: 671
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a binary string $S$ of length $N$, we need to construct a new string $T$ of the same length such that for every index $i$, $T[i] \neq S[i]$. Since the string consists only of '0's and '1's, this implies that every '0' in $S$ must be replaced by a '1' in $T$, and every '1' in $S$ must be replaced by a '0' in $T$.

## Intuition & Mathematical Observation
The problem asks us to perform a bitwise NOT operation on every character of the string. 
- If $S[i] = '0'$, then $T[i] = '1'$.
- If $S[i] = '1'$, then $T[i] = '0'$.

This is a straightforward transformation where we iterate through the input string and flip each character. We can achieve this using a simple loop or by modifying the string in place.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. Given the constraints, the total time complexity is $O(\sum N)$, which fits well within the time limits.
- **Space Complexity**: $O(N)$ to store the resulting string $T$ (or $O(1)$ auxiliary space if we modify the string in place).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a binary string S of length N.
 * We need to construct a string T such that T[i] != S[i] for all i.
 * Since the string is binary, the only possible characters are '0' and '1'.
 * If S[i] == '0', then T[i] must be '1'.
 * If S[i] == '1', then T[i] must be '0'.
 * This is equivalent to flipping each bit of the string S.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    string T = "";
    for (int i = 0; i < N; ++i) {
        if (S[i] == '0') {
            T += '1';
        } else {
            T += '0';
        }
    }
    cout << T << "\n";
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