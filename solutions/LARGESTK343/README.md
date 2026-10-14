# [Largest K (LARGESTK343)](https://www.codechef.com/problems/LARGESTK343)

- **Difficulty Rating**: 990
- **Solved in**: 1 attempt(s)

## Problem Summary
Given $X$ zeros and $Y$ ones, we need to arrange them such that there are at least $K$ ones between any two adjacent zeros. The goal is to find the maximum possible integer value of $K$.

## Intuition & Mathematical Observation
To place $X$ zeros such that there is at least one gap between each adjacent pair, we create exactly $X - 1$ gaps. 

Let $g_i$ be the number of ones placed in the $i$-th gap (where $1 \le i \le X-1$). The problem states that for every gap, $g_i \ge K$. To maximize $K$ while using a total of $Y$ ones, we distribute the ones as evenly as possible across these $X-1$ gaps.

The total number of ones used to satisfy the condition is the sum of ones in all gaps:
$$\sum_{i=1}^{X-1} g_i \le Y$$

Since we want the minimum gap size $K$ to be as large as possible, we set $g_i = K$ for all $i$. This gives us:
$$K \times (X - 1) \le Y$$

Rearranging for $K$:
$$K \le \frac{Y}{X - 1}$$

Since $K$ must be an integer, the largest possible value is:
$$K = \lfloor \frac{Y}{X - 1} \rfloor$$

**Edge Case Note:** If $X=1$, there are no gaps between zeros, meaning the condition is vacuously true for any $K$. However, based on the problem constraints, we typically handle the division by $X-1$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves a single division operation. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have X zeros and Y ones.
 * We want to place these zeros such that there are at least K ones between any two adjacent zeros.
 * If we have X zeros, there are (X - 1) gaps between them.
 * Let the number of ones in each gap be g_1, g_2, ..., g_{X-1}.
 * The condition is that g_i >= K for all i = 1 to X-1.
 * The total number of ones used in these gaps is sum(g_i) = G_total.
 * We must have G_total <= Y.
 * To maximize K, we want to distribute the ones such that the minimum gap is as large as possible.
 * The total number of ones required to satisfy a gap of size K is K * (X - 1).
 * Therefore, we need K * (X - 1) <= Y.
 * K <= Y / (X - 1).
 * 
 * Since K must be an integer, the largest K is floor(Y / (X - 1)).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long X, Y;
        cin >> X >> Y;

        // X is the number of 0s.
        // There are X-1 gaps between the X zeros.
        // We need to distribute Y ones into these X-1 gaps such that each gap has at least K ones.
        // K * (X - 1) <= Y
        // K <= Y / (X - 1)
        
        long long gaps = X - 1;
        long long K = Y / gaps;
        
        cout << K << "\n";
    }

    return 0;
}
```