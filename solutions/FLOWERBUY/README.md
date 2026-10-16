# [Buying Flowers (FLOWERBUY)](https://www.codechef.com/problems/FLOWERBUY)

- **Difficulty Rating**: 931
- **Solved in**: 2 attempt(s)

## Problem Summary
We are tasked with buying exactly $N$ flowers using two types of bundles:
1. A bundle of 2 flowers costing 4 units.
2. A bundle of 3 flowers costing 5 units.

We need to find non-negative integers $x$ (number of 2-flower bundles) and $y$ (number of 3-flower bundles) such that $2x + 3y = N$, while minimizing the total cost $4x + 5y$. If no such combination exists, the problem implies we should handle it (though given the constraints, we look for the minimum valid cost).

## Intuition & Mathematical Observation
The problem asks us to satisfy the linear Diophantine equation $2x + 3y = N$ for $x, y \ge 0$. 

Since $N$ is small ($N \le 100$), we can use a brute-force approach:
1. Iterate through all possible values of $y$ starting from 0.
2. For each $y$, calculate the remaining flowers needed: $rem = N - 3y$.
3. If $rem \ge 0$ and $rem$ is divisible by 2, then $x = rem / 2$ is a valid solution.
4. Calculate the cost $4x + 5y$ for every valid pair $(x, y)$ and keep track of the minimum cost found.

This approach is efficient because the loop runs at most $N/3$ times, which is well within the time limits for $N=100$.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case. Since we iterate through possible values of $y$ up to $N/3$, the complexity is linear relative to $N$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the current cost and the minimum cost.

## Solution Code

```cpp
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

/**
 * Problem Analysis:
 * We need to find non-negative integers x and y such that:
 * 2x + 3y = N
 * Minimize cost = 4x + 5y
 * 
 * Since N <= 100, we can iterate through all possible values of y.
 * If (N - 3y) is non-negative and divisible by 2, then x = (N - 3y) / 2 is a valid solution.
 */

void solve() {
    int N;
    cin >> N;

    int min_cost = INT_MAX;
    bool found = false;

    // Iterate through possible number of 3-flower bundles (y)
    for (int y = 0; y * 3 <= N; ++y) {
        int remaining = N - (y * 3);
        if (remaining % 2 == 0) {
            int x = remaining / 2;
            int current_cost = (x * 4) + (y * 5);
            if (current_cost < min_cost) {
                min_cost = current_cost;
                found = true;
            }
        }
    }

    if (found) {
        cout << min_cost << "\n";
    }
}

int main() {
    // Optimize I/O operations
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