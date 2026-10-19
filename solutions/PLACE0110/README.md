# [Placing 01 And 10 (PLACE0110)](https://www.codechef.com/problems/PLACE0110)

- **Difficulty Rating**: 1114
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $X$ copies of the string "01" and $Y$ copies of the string "10". We need to arrange all $X+Y$ strings in some order to form a single string $S$ such that the number of transitions (indices $i$ where $S[i] \neq S[i+1]$) is minimized. We must output this minimum value.

## Intuition & Mathematical Observation
Let $A = "01"$ and $B = "10"$.
1. **Internal Transitions**: Each $A$ contains one transition ($0 \to 1$), and each $B$ contains one transition ($1 \to 0$). Thus, regardless of the arrangement, we start with a base of $X + Y$ transitions.
2. **Boundary Transitions**: When concatenating two strings, we check the boundary:
   - $A + A$ ("0101"): Adds 1 transition ($1 \to 0$).
   - $B + B$ ("1010"): Adds 1 transition ($0 \to 1$).
   - $A + B$ ("0110"): Adds 0 transitions ($1 \to 1$).
   - $B + A$ ("1001"): Adds 0 transitions ($0 \to 0$).

To minimize the total transitions, we want to maximize the number of $A+B$ or $B+A$ adjacencies.
- If $|X - Y| \le 1$, we can alternate the strings (e.g., $A, B, A, B...$), ensuring almost every boundary is a "no transition" boundary. The total transitions remain $X + Y$.
- If $|X - Y| > 1$, we are forced to place identical strings next to each other. For example, if $X > Y + 1$, we can place at most $Y$ strings of $B$ to separate $X$ strings of $A$. This creates $Y+1$ groups of $A$. The number of $A-A$ adjacencies created is $X - (Y + 1)$.
- The total transitions become: $(X + Y) + (X - Y - 1) = 2X - 1$.
- By symmetry, if $Y > X + 1$, the result is $2Y - 1$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution uses simple arithmetic operations.
- **Space Complexity**: $O(1)$, as we only store a few integer variables.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have X strings of "01" and Y strings of "10".
 * Each "01" and "10" contributes 1 to the transition count internally.
 * We minimize the total transitions by alternating "01" and "10" to avoid 
 * creating new transitions at the boundaries.
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;

    // If the difference is 0 or 1, we can perfectly alternate or nearly alternate
    // to avoid extra boundary transitions.
    if (abs(X - Y) <= 1) {
        cout << X + Y << "\n";
    } 
    // If one type significantly outweighs the other, we are forced to place
    // the majority type next to itself, adding extra transitions.
    else if (X > Y) {
        cout << 2 * X - 1 << "\n";
    } else {
        cout << 2 * Y - 1 << "\n";
    }
}

int main() {
    // Optimize I/O operations
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