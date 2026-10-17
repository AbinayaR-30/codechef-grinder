# [Work Smarter, Not Harder (SMARTER)](https://www.codechef.com/problems/SMARTER)

- **Difficulty Rating**: 924
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to determine the maximum integer wait time $w$ that the hare can afford such that it still finishes the race strictly before the tortoise. 
- The tortoise travels distance $L$ at speed $V_1$.
- The hare travels distance $L$ at speed $V_2$.
- The hare waits for $w$ units of time before starting.
- We need to find the largest integer $w \ge 0$ such that the hare's total time is strictly less than the tortoise's total time. If no such $w$ exists, output -1.

## Intuition & Mathematical Observation
1. **Time Calculation**: Since the race time is the ceiling of the distance divided by speed, we calculate:
   - Tortoise time: $T_{tortoise} = \lceil \frac{L}{V_1} \rceil$
   - Hare running time: $T_{hare\_run} = \lceil \frac{L}{V_2} \rceil$
   - Using integer arithmetic, $\lceil \frac{a}{b} \rceil$ is equivalent to `(a + b - 1) / b`.

2. **Inequality Setup**: The hare wins if:
   $$w + T_{hare\_run} < T_{tortoise}$$
   Rearranging for $w$:
   $$w < T_{tortoise} - T_{hare\_run}$$

3. **Finding $w$**: Since $w$ must be an integer, the maximum value is:
   $$w_{max} = T_{tortoise} - T_{hare\_run} - 1$$
   If $w_{max} < 0$, it is impossible for the hare to win, so we output -1.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations. Total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the inputs and results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Tortoise time (T_tortoise) = ceil(L / V1)
 * Hare running time (T_hare_run) = ceil(L / V2)
 * 
 * Condition to win:
 * w + T_hare_run < T_tortoise
 * w < T_tortoise - T_hare_run
 * 
 * Max integer w = T_tortoise - T_hare_run - 1
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long L, V1, V2;
        cin >> L >> V1 >> V2;

        // Calculate ceil(L / V1) and ceil(L / V2) using integer arithmetic
        long long t_tortoise = (L + V1 - 1) / V1;
        long long t_hare_run = (L + V2 - 1) / V2;

        // Max integer w = t_tortoise - t_hare_run - 1
        long long max_w = t_tortoise - t_hare_run - 1;

        if (max_w < 0) {
            cout << -1 << "\n";
        } else {
            cout << max_w << "\n";
        }
    }

    return 0;
}
```