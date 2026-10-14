# [Make N Zero (MAKENZERO)](https://www.codechef.com/problems/MAKENZERO)

- **Difficulty Rating**: 846
- **Solved in**: 1 attempt(s)

## Problem Summary
The objective is to determine if a given integer $N$ can be represented as a sum of 3s and 4s. That is, we need to find if there exist non-negative integers $x$ and $y$ such that $3x + 4y = N$.

## Intuition & Mathematical Observation
This problem is a classic application of the **Frobenius Coin Problem** (also known as the Chicken McNugget Theorem). For two coprime integers $a$ and $b$, the largest integer that cannot be expressed as $ax + by$ (where $x, y \ge 0$) is given by the formula $(a \times b) - a - b$.

For $a=3$ and $b=4$:
- The largest impossible number is $(3 \times 4) - 3 - 4 = 5$.
- We can test small values of $N$:
    - $N=1$: Impossible
    - $N=2$: Impossible
    - $N=3$: $3(1) + 4(0) = 3$ (Possible)
    - $N=4$: $3(0) + 4(1) = 4$ (Possible)
    - $N=5$: Impossible
    - $N=6$: $3(2) + 4(0) = 6$ (Possible)
    - $N=7$: $3(1) + 4(1) = 7$ (Possible)
    - $N=8$: $3(0) + 4(2) = 8$ (Possible)

Since we can form 6, 7, and 8, we can form any subsequent integer by simply adding 3 to one of these base cases. Therefore, the only integers that cannot be represented are **1, 2, and 5**.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform a constant number of comparisons.
- **Space Complexity**: $O(1)$, as we use no extra data structures.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We want to represent N as 3x + 4y = N, where x, y >= 0.
 * This is a variation of the Frobenius Coin Problem.
 * The only numbers that cannot be represented as 3x + 4y are 1, 2, and 5.
 */

void solve() {
    int n;
    cin >> n;
    // Check if N is one of the impossible values
    if (n == 1 || n == 2 || n == 5) {
        cout << "NO" << "\n";
    } else {
        cout << "YES" << "\n";
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