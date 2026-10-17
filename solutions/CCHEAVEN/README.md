# [Chef in Heaven (CCHEAVEN)](https://www.codechef.com/problems/CCHEAVEN)

- **Difficulty Rating**: 1317
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef lives for $L$ years, represented by a binary string $S$ of length $L$, where '1' denotes a good year and '0' denotes a bad year. Chef goes to heaven if, at any point in time (after $L'$ years, where $1 \le L' \le L$), the number of good years is at least 50% of the total years passed. We need to determine if this condition is met at any point during Chef's life.

## Intuition & Mathematical Observation
The condition for Chef to go to heaven is:
$$\frac{\text{good years}}{\text{total years}} \ge 0.5$$

Let $L'$ be the number of years passed (the prefix length) and $G$ be the count of '1's in that prefix. The inequality becomes:
$$\frac{G}{L'} \ge \frac{1}{2}$$

To avoid floating-point precision issues, we can multiply both sides by $2L'$:
$$2 \times G \ge L'$$

By iterating through the string and maintaining a running count of '1's, we can check this condition at every index $i$ (where $L' = i + 1$). If the condition is satisfied at any point, we can immediately conclude "YES" and stop the search. If we finish the loop without the condition ever being met, the answer is "NO".

## Complexity Analysis
- **Time Complexity**: $O(L)$ per test case, where $L$ is the length of the string. We perform a single pass through the string.
- **Space Complexity**: $O(L)$ to store the input string $S$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef lives for L years. We are given a string S of length L where S[i] is '1' (good) or '0' (bad).
 * Chef goes to heaven if there exists some L' (1 <= L' <= L) such that the number of good years
 * in the first L' years is at least 50% of L'.
 * 
 * Let 'good' be the count of '1's in the prefix of length L'.
 * The condition is: good / L' >= 0.5
 * This is equivalent to: 2 * good >= L'
 */

void solve() {
    int L;
    cin >> L;
    string S;
    cin >> S;

    int good_years = 0;
    bool possible = false;

    for (int i = 0; i < L; ++i) {
        if (S[i] == '1') {
            good_years++;
        }
        
        // Current length is i + 1
        // Condition: 2 * good_years >= total_years
        if (2 * good_years >= (i + 1)) {
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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
```